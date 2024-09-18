/*
 * Copyright 2022 Chair of EDA, Technical University of Munich
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

/// Test core based on CVA6 for configurable memory model (hand written)
/// TODO: remove me

#ifndef SWEVAL_BACKENDS_TEST_CORE_PERFORMANCE_MODEL_H
#define SWEVAL_BACKENDS_TEST_CORE_PERFORMANCE_MODEL_H

#include <stdbool.h>
#include <string>
#include <algorithm>
#include <cstdint>

#include "PerformanceModel.h"

#include "models/common/StandardRegisterModel.h"
#include "models/cva6/ClobberModel.h"
#include "models/cva6/ICacheModel.h"
#include "models/cva6/DCacheModel.h"
#include "models/cva6/BranchPredictionModel.h"
#include "models/cva6/CVA6_DividerModel.h"
#include "models/cva6/CVA6_DividerUnsignedModel.h"

class Channel;

class TestCore_PerformanceModel : public PerformanceModel
{
public:

    class PcGenStage_Model
    {
    public:

      PcGenStage_Model() = default;

      uint64_t get_backPressure(void) { return get_leaveStage(); };

      uint64_t get_leaveStage(void) { return leaveStage; };
      void set_leaveStage(uint64_t c) { leaveStage = c; };

      uint64_t getStageInfo(void) { return leaveStage; };

    private:

      uint64_t leaveStage = 0;

    };

    class IfStage_Model
    {
    public:

      IfStage_Model() = default;

      uint64_t get_backPressure(void) { return get_leaveICacheIn(); };

      uint64_t get_leaveICacheIn(void) { return leaveICacheIn; };
      void set_leaveICacheIn(uint64_t c) { leaveICacheIn = c; };

      uint64_t get_leaveICache(void) { return leaveICache; };
      void set_leaveICache(uint64_t c) { leaveICache = c; };

      uint64_t get_leaveStage(void) { return leaveStage; };
      void set_leaveStage(uint64_t c) { leaveStage = c; };

      uint64_t getStageInfo(void) { return leaveStage; };

    private:

      uint64_t leaveStage = 0;

      uint64_t leaveICacheIn = 0;
      uint64_t leaveICache = 0;

    };

    class IqStage_Model
    {
    public:

      IqStage_Model() = default;

      //uint64_t get_backPressure(void) { return std::max({get_leaveStage(), get_leaveInsert()}); };
      uint64_t get_backPressure(void) { return get_leaveStage(); };

      void set_leaveInsert(uint64_t c) { leaveInsert = c ;};
      uint64_t get_leaveInsert(void) {return leaveInsert; };

      void set_leaveStage (uint64_t c)
      {
        curLeaveStage = c;
        leaveStage[stage_ptr] = c;
        stage_ptr = (++stage_ptr)%7;
      }
      uint64_t get_leaveStage(void) { return leaveStage[stage_ptr]; };

      uint64_t getStageInfo(void) { return curLeaveStage; };

    private:

      uint64_t leaveInsert = 0;

      uint64_t leaveStage[7] = {};
      int stage_ptr = 0;

      uint64_t curLeaveStage = 0;
    };

    class IdStage_Model
    {
    public:

      IdStage_Model() = default;

      uint64_t get_backPressure(void) { return get_leaveStage(); };

      void set_leaveStage (uint64_t c) { leaveStage = c; };
      uint64_t get_leaveStage(void) { return leaveStage; };

      uint64_t getStageInfo(void) { return leaveStage; };

    private:

      uint64_t leaveStage = 0;

    };

    class IsStage_Model
    {
    public:

      IsStage_Model() = default;

      uint64_t get_backPressure(void) { return get_leaveStage(); };

      void set_leaveStage (uint64_t c) { leaveStage = c; };
      uint64_t get_leaveStage(void) { return leaveStage; };

      uint64_t getStageInfo(void) { return leaveStage; };

    private:

      uint64_t leaveStage = 0;

    };

    class ExStage_Model
    {
    public:

      ExStage_Model() = default;

      //uint64_t get_backPressure_arith(void) { return std::max({get_leaveStage_i8(), get_leaveAlu(), get_leaveMul_i1(), get_leaveDiv()}); };
      uint64_t get_backPressure_arith(void) { return std::max({get_leaveStage_i8(), get_leaveAlu(), get_leaveMulO(), get_leaveDiv()}); };
      //uint64_t get_backPressure_mul(void) { return std::max({get_leaveStage_i8(), get_leaveMul_i2(), get_leaveDiv()}); };
      uint64_t get_backPressure_mul(void) { return std::max({get_leaveStage_i8(), get_leaveMulI(), get_leaveDiv()}); };
      uint64_t get_backPressure_div(void) { return std::max({get_leaveStage_i8(), get_leaveDiv()}); };
      uint64_t get_backPressure_load(void) { return std::max({get_leaveStage_i8(), get_leaveLCtrl()}); };
      uint64_t get_backPressure_store(void) { return std::max({get_leaveStage_i8(), get_leaveSCtrl()}); };

      uint64_t get_transGuard(void) { return get_leaveStage_i1(); };

      void set_leaveAlu(uint64_t c) { leaveAlu = c; };
      uint64_t get_leaveAlu(void) { return leaveAlu; };

      ////void set_leaveMul(uint64_t c) { leaveMul = c; };
      //void set_leaveMul(uint64_t);
      //uint64_t get_leaveMul_i2(void) { return leaveMul[mul_ptr_i2]; };
      //uint64_t get_leaveMul_i1(void) { return leaveMul[mul_ptr_i1]; };

      void set_leaveMulI(uint64_t c) { leaveMulI = c; };
      void set_leaveMulO(uint64_t c) { leaveMulO = c; };

      uint64_t get_leaveMulI(void) { return leaveMulI; };
      uint64_t get_leaveMulO(void) { return leaveMulO; };

      void set_leaveDiv(uint64_t c) { leaveDiv = c; };
      uint64_t get_leaveDiv(void) { return leaveDiv; };

      void set_leaveLCtrl(uint64_t c) { leaveLCtrl = c; };
      uint64_t get_leaveLCtrl(void) { return leaveLCtrl; };

      void set_leaveDCache(uint64_t c) { leaveDCache = c; };
      uint64_t get_leaveDCache(void) { return leaveDCache; };

      void set_leaveLUnit(uint64_t c) { leaveLUnit = c; };
      uint64_t get_leaveLUnit(void) { return leaveLUnit; };

      void set_leaveSCtrl(uint64_t c) { leaveSCtrl = c; };
      uint64_t get_leaveSCtrl(void) { return leaveSCtrl; };

      void set_leaveSUnit(uint64_t c) { leaveSUnit = c; };
      uint64_t get_leaveSUnit(void) { return leaveSUnit; };

      void set_leaveStage (uint64_t c)
      {
        curLeaveStage = c;
        leaveStage[stage_ptr_i8] = c;
        stage_ptr_i8 = (++stage_ptr_i8)%8;
        stage_ptr_i1 = (++stage_ptr_i1)%8;
      }
      uint64_t get_leaveStage_i8(void) { return leaveStage[stage_ptr_i8]; };
      uint64_t get_leaveStage_i1(void) { return leaveStage[stage_ptr_i1]; };

      uint64_t getStageInfo(void) { return curLeaveStage; };

    private:

      uint64_t leaveDiv = 0;

      //uint64_t leaveMul[2] = { };
      uint64_t leaveMulI = 0;
      uint64_t leaveMulO = 0;

      uint64_t leaveAlu = 0; // TODO: Do we need to differentiate between ALU, BU and CSR?
      uint64_t leaveLCtrl = 0;
      uint64_t leaveDCache = 0;
      uint64_t leaveLUnit = 0;
      uint64_t leaveSCtrl = 0;
      uint64_t leaveSUnit = 0;
      uint64_t leaveStage[8] = { };

      //int mul_ptr_i2 = 0;
      //int mul_ptr_i1 = 1;
      int stage_ptr_i8 = 0;
      int stage_ptr_i1 = 7;

      uint64_t curLeaveStage = 0;
      /*
      uint64_t leaveMul = 0;
      int mul_ptr_i2 = 0;
      int mul_ptr_i1 = 1;
      uint64_t mul_array[2] = {};
      */

      //uint64_t leaveStage = 0;
      //int stage_ptr_i8 = 0;
      //int stage_ptr_i1 = 7;
      //uint64_t stage_array[8] = { };

    };

    class ComStage_Model
    {
    public:

      ComStage_Model() = default;

      uint64_t get_backPressure(void) { return get_leaveStage(); }

      void set_leaveStage (uint64_t c)
      {
        curLeaveStage = c;
        leaveStage[stage_ptr] = c;
        stage_ptr = (++stage_ptr)%2;
      }
      uint64_t get_leaveStage(void) { return leaveStage[stage_ptr]; }

      uint64_t getStageInfo(void) { return curLeaveStage; }

    private:

      uint64_t leaveStage[2] = {};
      int stage_ptr = 0;

      uint64_t curLeaveStage = 0;
    };

    /**
     * @brief Instantiates the instruction set of this class once needed (lazy). 
     * Calling this function mutliple times yields the same instruction set pointer.
     */
    static InstructionModelSet* instructionSet();
    
    TestCore_PerformanceModel() : 
        PerformanceModel("TestCore", instructionSet())
        ,regModel(this)
        ,cbModel(this)
        ,iCacheModel(this)
        ,dCacheModel(this)
        ,brPredModel(this)
        ,divModel(this)
        ,divUModel(this)
    {}

    PcGenStage_Model PcGenStage;
    IfStage_Model IfStage;
    IqStage_Model IqStage;
    IdStage_Model IdStage;
    IsStage_Model IsStage;
    ExStage_Model ExStage;
    ComStage_Model ComStage;

    StandardRegisterModel regModel;
    ClobberModel cbModel;
    ICacheModel iCacheModel;
    DCacheModel dCacheModel;
    BranchPredictionModel brPredModel;
    CVA6_DividerModel divModel;
    CVA6_DividerUnsignedModel divUModel;

    void connectChannel(Channel*) override;
    uint64_t getCycleCount(void) override;
    std::string getPipelineStream(void) override;
    std::string getPrintHeader(void) override;
};

#endif // SWEVAL_BACKENDS_TEST_CORE_PERFORMANCE_MODEL_H
