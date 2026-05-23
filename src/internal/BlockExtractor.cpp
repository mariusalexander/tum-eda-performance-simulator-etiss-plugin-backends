/*
 * Copyright 2026 Chair of EDA, Technical University of Munich
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *	 http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "BlockExtractor.h"

#include "Channel.h"

#include <iostream>
#include <memory>
#include <fstream>
#include <algorithm>
#include <stdexcept>

void BlockExtractor::initialize(void){
    std::cout << "BlockExtractor initialized" << std::endl;
}

void BlockExtractor::execute(void){

    for(uint64_t instrIdx_i=0; instrIdx_i < *ch_instrCnt_ptr; instrIdx_i++){
        globalInstrCnt++;

        uint64_t curPc = ch_pc_ptr[instrIdx_i];
        
        while(1){
            // Check if Block-Start
            if(!activeBlock){
                lastPc = curPc - 4;
                activeBlock = true;
                globalBlockCnt++;

                // Check if block has been observed before
                auto it = blockMap.find(curPc);
                if(it != blockMap.end()){
                    curBlock = it->second.get();
                    registeredBlock = true;
                }
                else{
                    blockMap.emplace(curPc, std::make_unique<Block_Extractor::Block>(blockMap.size(), curPc, *blockInstrGen));
                    curBlock = blockMap[curPc].get();
                    registeredBlock = false;
                }
                curBlock->increaseCallCnt();
            }

            if (curPc != lastPc + 4)
            {
                if (curBlock->getFinalPc() != 0){
                    std::stringstream error;
                    error << "### WARNING: Block 0x" << std::hex << curBlock->getPc() << " - 0x" << curBlock->getFinalPc() << " ended at 0x" << lastPc << "! Need to split BB?" << std::endl;
                    throw std::logic_error(error.str());
                }
            
                std::cout << "### BB 0x" << std::hex << curBlock->getPc() << " - 0x" << lastPc << " ended: pc change at 0x" << curPc << std::dec << ", typeId: " << ch_typeId_ptr[instrIdx_i] << std::endl;
                curBlock->forceEnd(lastPc);
                activeBlock = false;
                continue;
            }
            break;
        }

        // Append instrType if block has not been observed before
        if(!registeredBlock){
            if (curBlock->getFinalPc() > 0) {
                std::stringstream error;
                error << "### WARNING: Block 0x" << std::hex << curBlock->getPc() << " - 0x" << curBlock->getFinalPc() << " was assumed finished!" << std::endl;
                throw std::logic_error(error.str());
            }
            // std::cout << "### appending: 0x" << std::hex << curBlock->getPc() << " -> pc: 0x" << curPc << " typeId: " << std::dec << ch_typeId_ptr[instrIdx_i] << std::endl;
            curBlock->appendInstr(
                ch_typeId_ptr[instrIdx_i],
                channel,
                curPc,
                instrIdx_i
            );
        }
        lastPc = curPc;

        // Check if Block-End
        if(!registeredBlock){
            if(curBlock->checkEnd(curPc)){
                activeBlock = false;
                std::cout << "### BB 0x" << std::hex << curBlock->getPc() << " - 0x" << curBlock->getFinalPc() << " ended: branch instr with id: " << std::dec << ch_typeId_ptr[instrIdx_i] << std::endl;
            }
        }
        else{
            if(curBlock->getFinalPc() == curPc){
                activeBlock = false;
            }
        }
    }
}

void BlockExtractor::finalize(void){

    // Sort blocks from unordered map into a vector (sorted by id)
    std::vector<Block_Extractor::Block*> blockVector;
    blockVector.reserve(blockMap.size());
    for(const auto& [pc_i, block_i]: blockMap){
        blockVector.push_back(block_i.get());
    }
    std::sort(blockVector.begin(), blockVector.end(),
        [](const Block_Extractor::Block* a, const Block_Extractor::Block* b){ return a->getId() < b->getId(); }
    );

    // Write json file
    std::ofstream file(outputPath);

    file << "[\n";

    int maxCount = 0;
    bool isFirst = true;
    for(const auto& block_i: blockVector){
        if(isFirst){
            isFirst = false;
        }
        else{
            file << ",\n";
        }

        file << "\t{\n";
        file << "\t\t\"id\": " << block_i->getId() << ",\n";
        file << "\t\t\"startPc\": " << block_i->getPc() << ",\n";
        file << "\t\t\"endPc\": " << block_i->getFinalPc() << ",\n";
        file << "\t\t\"callCnt\": " << block_i->getCallCnt() << ",\n";
        file << "\t\t\"instrs\": [\n";
        bool isFirstInstr = true;
        for(const auto& instr_i : block_i->getInstrVector()){
            if(isFirstInstr){
                isFirstInstr = false;
            }
            else{
                file << ",\n";
            }
            file << instr_i->getJsonStr(std::string("\t\t\t"));
        }
        maxCount = std::max(maxCount, block_i->getCallCnt());
        file << "\n";
        file << "\t\t]\n";

        file << "\t}";
    }

    file << "\n]\n";

    file.close();

    // Summary to terminal
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Writing block list to: " << outputPath << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "SUMMARY:" << std::endl;

    std::cout << "Number of counted instructions: " << globalInstrCnt << std::endl;
    std::cout << "Number of counted blocks: " << globalBlockCnt << std::endl;
    std::cout << "Number of registered blocks: " << blockMap.size() << std::endl;
    std::cout << "maxCount: " << maxCount << std::endl;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

}