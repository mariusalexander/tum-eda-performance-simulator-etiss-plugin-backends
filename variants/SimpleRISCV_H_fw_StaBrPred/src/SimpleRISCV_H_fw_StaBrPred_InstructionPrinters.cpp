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

/********************* AUTO GENERATE FILE (create by M2-ISA-R::Trace-Generator) *********************/


#include "Printer.h"
#include "Channel.h"

#include "SimpleRISCV_H_fw_StaBrPred_Printer.h"

#include <sstream>
#include <string>
#include <iomanip>

InstructionPrinterSet *SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet = new InstructionPrinterSet("SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet");

static InstructionPrinter *instrPrinter_add = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "add",
  0,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sub = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "sub",
  1,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xor = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "xor",
  2,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_or = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "or",
  3,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_and = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "and",
  4,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slt = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "slt",
  5,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sltu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "sltu",
  6,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sll = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "sll",
  7,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srl = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "srl",
  8,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sra = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "sra",
  9,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_addi = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "addi",
  10,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xori = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "xori",
  11,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_ori = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "ori",
  12,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_andi = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "andi",
  13,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slti = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "slti",
  14,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sltiu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "sltiu",
  15,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slli = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "slli",
  16,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srli = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "srli",
  17,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srai = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "srai",
  18,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_auipc = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "auipc",
  19,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lui = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "lui",
  20,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mul = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "mul",
  21,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulh = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "mulh",
  22,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulhu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "mulhu",
  23,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulhsu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "mulhsu",
  24,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_div = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "div",
  25,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_rem = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "rem",
  26,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_divu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "divu",
  27,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_remu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "remu",
  28,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrw = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "csrrw",
  29,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrs = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "csrrs",
  30,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrc = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "csrrc",
  31,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrwi = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "csrrwi",
  32,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrsi = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "csrrsi",
  33,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrci = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "csrrci",
  34,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sb = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "sb",
  35,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sh = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "sh",
  36,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sw = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "sw",
  37,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lw = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "lw",
  38,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lh = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "lh",
  39,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lhu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "lhu",
  40,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lb = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "lb",
  41,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lbu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "lbu",
  42,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_beq = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "beq",
  43,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bne = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "bne",
  44,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_blt = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "blt",
  45,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bge = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "bge",
  46,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bltu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "bltu",
  47,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bgeu = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "bgeu",
  48,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter__def = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "_def",
  49,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_jal = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "jal",
  50,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_jalr = new InstructionPrinter(
  SimpleRISCV_H_fw_StaBrPred_InstrPrinterSet,
  "jalr",
  51,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_fw_StaBrPred_Printer* printer = static_cast<SimpleRISCV_H_fw_StaBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
