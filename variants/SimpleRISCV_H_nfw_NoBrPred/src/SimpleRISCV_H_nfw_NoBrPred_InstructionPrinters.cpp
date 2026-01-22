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

#include "SimpleRISCV_H_nfw_NoBrPred_Printer.h"

#include <sstream>
#include <string>
#include <iomanip>

InstructionPrinterSet *SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet = new InstructionPrinterSet("SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet");

static InstructionPrinter *instrPrinter_add = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "add",
  0,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sub = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "sub",
  1,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sll = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "sll",
  2,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xor = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "xor",
  3,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_or = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "or",
  4,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_and = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "and",
  5,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_cadd = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "cadd",
  6,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mul = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "mul",
  7,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_rem = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "rem",
  8,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_addi = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "addi",
  9,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sltiu = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "sltiu",
  10,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xori = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "xori",
  11,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_ori = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "ori",
  12,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_andi = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "andi",
  13,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_caddi = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "caddi",
  14,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_cslli = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "cslli",
  15,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_caddi16sp = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "caddi16sp",
  16,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_cmv = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "cmv",
  17,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_cli = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "cli",
  18,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sb = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "sb",
  19,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sh = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "sh",
  20,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sw = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "sw",
  21,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csw = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "csw",
  22,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lh = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "lh",
  23,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lw = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "lw",
  24,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lbu = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "lbu",
  25,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lhu = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "lhu",
  26,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_clw = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "clw",
  27,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_beq = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "beq",
  28,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bne = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "bne",
  29,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_blt = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "blt",
  30,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bge = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "bge",
  31,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bltu = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "bltu",
  32,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bgeu = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "bgeu",
  33,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_cbeqz = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "cbeqz",
  34,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_cbnez = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "cbnez",
  35,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter__def = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "_def",
  36,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lb = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "lb",
  37,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slti = new InstructionPrinter(
  SimpleRISCV_H_nfw_NoBrPred_InstrPrinterSet,
  "slti",
  38,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SimpleRISCV_H_nfw_NoBrPred_Printer* printer = static_cast<SimpleRISCV_H_nfw_NoBrPred_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    ret_strs << std::endl;
    return ret_strs.str();
  }
);
