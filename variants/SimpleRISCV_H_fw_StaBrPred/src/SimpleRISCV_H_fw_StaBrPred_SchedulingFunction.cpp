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

/********************* AUTO GENERATE FILE (create by M2-ISA-R-Perf) *********************/


#include <algorithm>
#include <cstdint>

#include "PerformanceModel.h"

#include "SimpleRISCV_H_fw_StaBrPred_PerformanceModel.h"

namespace SimpleRISCV_H_fw_StaBrPred{

SchedulingFunctionSet* SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet = new SchedulingFunctionSet("SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet");

static SchedulingFunction *schedulingFunction_add = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "add",
  0,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_sub = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "sub",
  1,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_sll = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "sll",
  2,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_xor = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "xor",
  3,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_or = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "or",
  4,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_and = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "and",
  5,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_cadd = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "cadd",
  6,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_mul = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "mul",
  7,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// Multi
uint64_t n_Multi;
n_Multi = n_ID_stage + 1;
perfModel->regModel.setXd(n_Multi);
// EX_stage
uint64_t n_EX_stage = n_Multi;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_rem = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "rem",
  8,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// Multi
uint64_t n_Multi;
n_Multi = n_ID_stage + 1;
perfModel->regModel.setXd(n_Multi);
// EX_stage
uint64_t n_EX_stage = n_Multi;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_addi = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "addi",
  9,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_sltiu = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "sltiu",
  10,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_xori = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "xori",
  11,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_ori = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "ori",
  12,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_andi = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "andi",
  13,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_caddi = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "caddi",
  14,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_cslli = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "cslli",
  15,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_caddi16sp = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "caddi16sp",
  16,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_cmv = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "cmv",
  17,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_cli = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "cli",
  18,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_sb = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "sb",
  19,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX_stage + perfModel->dMemModel.getDelay();
// MEM_stage
uint64_t n_MEM_stage = n_DPort_W;
perfModel->MEM_stage = n_MEM_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_sh = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "sh",
  20,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX_stage + perfModel->dMemModel.getDelay();
// MEM_stage
uint64_t n_MEM_stage = n_DPort_W;
perfModel->MEM_stage = n_MEM_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "sw",
  21,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX_stage + perfModel->dMemModel.getDelay();
// MEM_stage
uint64_t n_MEM_stage = n_DPort_W;
perfModel->MEM_stage = n_MEM_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_csw = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "csw",
  22,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX_stage + perfModel->dMemModel.getDelay();
// MEM_stage
uint64_t n_MEM_stage = n_DPort_W;
perfModel->MEM_stage = n_MEM_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_lh = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "lh",
  23,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_lw = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "lw",
  24,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_lbu = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "lbu",
  25,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_lhu = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "lhu",
  26,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_clw = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "clw",
  27,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_beq = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "beq",
  28,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "bne",
  29,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "blt",
  30,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "bge",
  31,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "bltu",
  32,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "bgeu",
  33,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_cbeqz = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "cbeqz",
  34,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_cbnez = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "cbnez",
  35,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "_def",
  36,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// ID_stage
uint64_t n_ID_stage = n_Decoder;
perfModel->ID_stage = n_ID_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "lb",
  37,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// ID_stage
uint64_t n_ID_stage = n_Decoder;
perfModel->ID_stage = n_ID_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);

static SchedulingFunction *schedulingFunction_slti = new SchedulingFunction(
  SimpleRISCV_H_fw_StaBrPred_SchedulingFunctionSet,
  "slti",
  38,
  [](PerformanceModel* perfModel_){
  SimpleRISCV_H_fw_StaBrPred_PerformanceModel* perfModel = static_cast<SimpleRISCV_H_fw_StaBrPred_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PC_Gen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// ID_stage
uint64_t n_ID_stage = n_Decoder;
perfModel->ID_stage = n_ID_stage;

  // Dump Entrance point for info print (tracing)
  perfModel->entrancePoint = n_Enter;
  }
);


} // namespace SimpleRISCV_H_fw_StaBrPred