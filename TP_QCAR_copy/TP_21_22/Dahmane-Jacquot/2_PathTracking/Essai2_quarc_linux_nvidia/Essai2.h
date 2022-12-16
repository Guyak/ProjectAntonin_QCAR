/*
 * Essai2.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Essai2".
 *
 * Model version              : 5.4
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Jan 11 15:26:28 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Essai2_h_
#define RTW_HEADER_Essai2_h_
#include <math.h>
#include <string.h>
#ifndef Essai2_COMMON_INCLUDES_
#define Essai2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_types.h"
#include "quanser_extern.h"
#endif                                 /* Essai2_COMMON_INCLUDES_ */

#include "Essai2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ()
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ()
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Essai2_rtModel                 RT_MODEL_Essai2_T

/* Block signals (default storage) */
typedef struct {
  real_T Product1;                     /* '<S2>/Product1' */
  real_T Offset;                       /* '<S4>/Offset' */
  real_T headingpositiongyroscope;     /* '<Root>/Integrator' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T ProportionalGain;             /* '<S43>/Proportional Gain' */
  real_T motorcounts;                  /* '<Root>/HIL Read1' */
  real_T HILRead1_o3;                  /* '<Root>/HIL Read1' */
  real_T Integrator;                   /* '<S6>/Integrator' */
  real_T Integrator1;                  /* '<S6>/Integrator1' */
  real_T psi_headingrad;               /* '<S6>/Integrator2' */
  real_T Unwrap21;                     /* '<Root>/Unwrap 2^1' */
  real_T Product;                      /* '<S2>/Product' */
  real_T Integrator1_l;                /* '<S3>/Integrator1' */
  real_T Product_b;                    /* '<S3>/Product' */
  real_T Product1_f;                   /* '<S3>/Product1' */
  real_T psidotrads;                   /* '<S6>/Product2' */
  real_T v_Xms;                        /* '<S6>/Sum' */
  real_T v_Yms;                        /* '<S6>/Sum1' */
  real_T RateTransition[4];            /* '<S5>/Rate Transition' */
} B_Essai2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T AnimationSFunction_DSTATE[6]; /* '<S5>/Animation S-Function' */
  real_T HILInitialize2_AIMinimums[7]; /* '<Root>/HIL Initialize2' */
  real_T HILInitialize2_AIMaximums[7]; /* '<Root>/HIL Initialize2' */
  real_T HILInitialize2_FilterFrequency[5];/* '<Root>/HIL Initialize2' */
  real_T HILInitialize2_POSortedFreqs[8];/* '<Root>/HIL Initialize2' */
  real_T HILInitialize2_POValues[8];   /* '<Root>/HIL Initialize2' */
  real_T HILInitialize2_OOValues[13];  /* '<Root>/HIL Initialize2' */
  real_T HILRead1_OtherBuffer[2];      /* '<Root>/HIL Read1' */
  real_T Unwrap21_PreviousInput;       /* '<Root>/Unwrap 2^1' */
  real_T Unwrap21_Revolutions;         /* '<Root>/Unwrap 2^1' */
  t_card HILInitialize2_Card;          /* '<Root>/HIL Initialize2' */
  void *HILRead1_PWORK;                /* '<Root>/HIL Read1' */
  void *HILWrite2_PWORK;               /* '<Root>/HIL Write2' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T HILInitialize2_DOStates;     /* '<Root>/HIL Initialize2' */
  int32_T HILInitialize2_QuadratureModes[5];/* '<Root>/HIL Initialize2' */
  int32_T HILInitialize2_InitialEICounts[5];/* '<Root>/HIL Initialize2' */
  int32_T HILInitialize2_POModeValues[8];/* '<Root>/HIL Initialize2' */
  int32_T HILInitialize2_POAlignValues[8];/* '<Root>/HIL Initialize2' */
  int32_T HILInitialize2_POPolarityVals[8];/* '<Root>/HIL Initialize2' */
  int32_T HILRead1_EncoderBuffer[2];   /* '<Root>/HIL Read1' */
  uint32_T HILInitialize2_POSortedChans[8];/* '<Root>/HIL Initialize2' */
  int_T Integrator1_IWORK;             /* '<S2>/Integrator1' */
  int_T Integrator1_IWORK_m;           /* '<S3>/Integrator1' */
  boolean_T Unwrap21_FirstSample;      /* '<Root>/Unwrap 2^1' */
} DW_Essai2_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S2>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S6>/Integrator1' */
  real_T Integrator2_CSTATE_p;         /* '<S6>/Integrator2' */
  real_T Integrator1_CSTATE_g;         /* '<S2>/Integrator1' */
  real_T Integrator1_CSTATE_h;         /* '<S3>/Integrator1' */
  real_T Integrator2_CSTATE_g;         /* '<S3>/Integrator2' */
} X_Essai2_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S2>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S6>/Integrator1' */
  real_T Integrator2_CSTATE_p;         /* '<S6>/Integrator2' */
  real_T Integrator1_CSTATE_g;         /* '<S2>/Integrator1' */
  real_T Integrator1_CSTATE_h;         /* '<S3>/Integrator1' */
  real_T Integrator2_CSTATE_g;         /* '<S3>/Integrator2' */
} XDot_Essai2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S2>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator_CSTATE_f;       /* '<S6>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S6>/Integrator1' */
  boolean_T Integrator2_CSTATE_p;      /* '<S6>/Integrator2' */
  boolean_T Integrator1_CSTATE_g;      /* '<S2>/Integrator1' */
  boolean_T Integrator1_CSTATE_h;      /* '<S3>/Integrator1' */
  boolean_T Integrator2_CSTATE_g;      /* '<S3>/Integrator2' */
} XDis_Essai2_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Essai2_B
#define BlockIO                        B_Essai2_T
#define rtX                            Essai2_X
#define ContinuousStates               X_Essai2_T
#define rtXdot                         Essai2_XDot
#define StateDerivatives               XDot_Essai2_T
#define tXdis                          Essai2_XDis
#define StateDisabled                  XDis_Essai2_T
#define rtP                            Essai2_P
#define Parameters                     P_Essai2_T
#define rtDWork                        Essai2_DW
#define D_Work                         DW_Essai2_T

/* Parameters (default storage) */
struct P_Essai2_T_ {
  real_T X_ic;                         /* Variable: X_ic
                                        * Referenced by: '<S6>/Integrator'
                                        */
  real_T Y_ic;                         /* Variable: Y_ic
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T vehicle_length;               /* Variable: vehicle_length
                                        * Referenced by:
                                        *   '<S6>/1//L'
                                        *   '<S6>/Gain'
                                        */
  real_T yaw_ic;                       /* Variable: yaw_ic
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S43>/Proportional Gain'
                                        */
  uint32_T HILRead1_encoder_channels[2];
                                    /* Mask Parameter: HILRead1_encoder_channels
                                     * Referenced by: '<Root>/HIL Read1'
                                     */
  uint32_T HILRead1_other_channels[2];/* Mask Parameter: HILRead1_other_channels
                                       * Referenced by: '<Root>/HIL Read1'
                                       */
  uint32_T HILWrite2_other_channels; /* Mask Parameter: HILWrite2_other_channels
                                      * Referenced by: '<Root>/HIL Write2'
                                      */
  uint32_T HILWrite2_pwm_channels;     /* Mask Parameter: HILWrite2_pwm_channels
                                        * Referenced by: '<Root>/HIL Write2'
                                        */
  real_T HILInitialize2_OOTerminate;
                                   /* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  real_T HILInitialize2_OOExit;   /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  real_T HILInitialize2_OOStart;       /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T HILInitialize2_OOEnter;   /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  real_T HILInitialize2_POFinal;       /* Expression: final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T HILInitialize2_OOFinal;       /* Expression: final_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T HILInitialize2_AIHigh;        /* Expression: analog_input_maximums
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T HILInitialize2_AILow;         /* Expression: analog_input_minimums
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T HILInitialize2_EIFrequency;   /* Expression: encoder_filter_frequency
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T HILInitialize2_POFrequency;   /* Expression: pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T HILInitialize2_POInitial;     /* Expression: initial_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T HILInitialize2_POWatchdog;    /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T HILInitialize2_OOInitial;     /* Expression: initial_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize2'
                                        */
  real_T Constant1_Value;              /* Expression: 25
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator2'
                                        */
  real_T countstorotations_Gain;       /* Expression: 1/720/4
                                        * Referenced by: '<S4>/counts to rotations'
                                        */
  real_T gearratios_Gain;              /* Expression: (13*19)/(70*37)
                                        * Referenced by: '<S4>/gear ratios'
                                        */
  real_T rotstorads_Gain;              /* Expression: 2*pi
                                        * Referenced by: '<S4>/rot//s to rad//s'
                                        */
  real_T wheelradius_Gain;             /* Expression: 0.0342
                                        * Referenced by: '<S4>/wheel radius'
                                        */
  real_T Offset_Gain;                  /* Expression: 0.87
                                        * Referenced by: '<S4>/Offset'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Constant_Value;               /* Expression: 0.25
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant6_Value;              /* Expression: 0.07
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T commandsaturation1_UpperSat;  /* Expression: 0.20
                                        * Referenced by: '<Root>/command saturation1'
                                        */
  real_T commandsaturation1_LowerSat;  /* Expression: -0.20
                                        * Referenced by: '<Root>/command saturation1'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant_Value_a;             /* Expression: 2
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Unwrap21_Modulus;             /* Expression: modulus
                                        * Referenced by: '<Root>/Unwrap 2^1'
                                        */
  real_T Constant_Value_n;             /* Expression: 2
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Integrator2_IC_f;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  int32_T HILInitialize2_EIInitial;
                                 /* Computed Parameter: HILInitialize2_EIInitial
                                  * Referenced by: '<Root>/HIL Initialize2'
                                  */
  int32_T HILInitialize2_POModes[2];
                                   /* Computed Parameter: HILInitialize2_POModes
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  int32_T HILInitialize2_POConfiguration;
                           /* Computed Parameter: HILInitialize2_POConfiguration
                            * Referenced by: '<Root>/HIL Initialize2'
                            */
  int32_T HILInitialize2_POAlignment;
                               /* Computed Parameter: HILInitialize2_POAlignment
                                * Referenced by: '<Root>/HIL Initialize2'
                                */
  int32_T HILInitialize2_POPolarity;
                                /* Computed Parameter: HILInitialize2_POPolarity
                                 * Referenced by: '<Root>/HIL Initialize2'
                                 */
  uint32_T HILInitialize2_AIChannels[7];
                                /* Computed Parameter: HILInitialize2_AIChannels
                                 * Referenced by: '<Root>/HIL Initialize2'
                                 */
  uint32_T HILInitialize2_DIChannels[20];
                                /* Computed Parameter: HILInitialize2_DIChannels
                                 * Referenced by: '<Root>/HIL Initialize2'
                                 */
  uint32_T HILInitialize2_DOChannels;
                                /* Computed Parameter: HILInitialize2_DOChannels
                                 * Referenced by: '<Root>/HIL Initialize2'
                                 */
  uint32_T HILInitialize2_EIChannels[5];
                                /* Computed Parameter: HILInitialize2_EIChannels
                                 * Referenced by: '<Root>/HIL Initialize2'
                                 */
  uint32_T HILInitialize2_EIQuadrature[2];
                              /* Computed Parameter: HILInitialize2_EIQuadrature
                               * Referenced by: '<Root>/HIL Initialize2'
                               */
  uint32_T HILInitialize2_POChannels[8];
                                /* Computed Parameter: HILInitialize2_POChannels
                                 * Referenced by: '<Root>/HIL Initialize2'
                                 */
  uint32_T HILInitialize2_OOChannels[13];
                                /* Computed Parameter: HILInitialize2_OOChannels
                                 * Referenced by: '<Root>/HIL Initialize2'
                                 */
  boolean_T HILInitialize2_Active;  /* Computed Parameter: HILInitialize2_Active
                                     * Referenced by: '<Root>/HIL Initialize2'
                                     */
  boolean_T HILInitialize2_AOTerminate;
                               /* Computed Parameter: HILInitialize2_AOTerminate
                                * Referenced by: '<Root>/HIL Initialize2'
                                */
  boolean_T HILInitialize2_AOExit;  /* Computed Parameter: HILInitialize2_AOExit
                                     * Referenced by: '<Root>/HIL Initialize2'
                                     */
  boolean_T HILInitialize2_DOTerminate;
                               /* Computed Parameter: HILInitialize2_DOTerminate
                                * Referenced by: '<Root>/HIL Initialize2'
                                */
  boolean_T HILInitialize2_DOExit;  /* Computed Parameter: HILInitialize2_DOExit
                                     * Referenced by: '<Root>/HIL Initialize2'
                                     */
  boolean_T HILInitialize2_POTerminate;
                               /* Computed Parameter: HILInitialize2_POTerminate
                                * Referenced by: '<Root>/HIL Initialize2'
                                */
  boolean_T HILInitialize2_POExit;  /* Computed Parameter: HILInitialize2_POExit
                                     * Referenced by: '<Root>/HIL Initialize2'
                                     */
  boolean_T HILInitialize2_CKPStart;
                                  /* Computed Parameter: HILInitialize2_CKPStart
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_CKPEnter;
                                  /* Computed Parameter: HILInitialize2_CKPEnter
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_CKStart;/* Computed Parameter: HILInitialize2_CKStart
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_CKEnter;/* Computed Parameter: HILInitialize2_CKEnter
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_AIPStart;
                                  /* Computed Parameter: HILInitialize2_AIPStart
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_AIPEnter;
                                  /* Computed Parameter: HILInitialize2_AIPEnter
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_AOPStart;
                                  /* Computed Parameter: HILInitialize2_AOPStart
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_AOPEnter;
                                  /* Computed Parameter: HILInitialize2_AOPEnter
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_AOStart;/* Computed Parameter: HILInitialize2_AOStart
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_AOEnter;/* Computed Parameter: HILInitialize2_AOEnter
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_AOReset;/* Computed Parameter: HILInitialize2_AOReset
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_DOPStart;
                                  /* Computed Parameter: HILInitialize2_DOPStart
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_DOPEnter;
                                  /* Computed Parameter: HILInitialize2_DOPEnter
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_DOStart;/* Computed Parameter: HILInitialize2_DOStart
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_DOEnter;/* Computed Parameter: HILInitialize2_DOEnter
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_DOReset;/* Computed Parameter: HILInitialize2_DOReset
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_EIPStart;
                                  /* Computed Parameter: HILInitialize2_EIPStart
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_EIPEnter;
                                  /* Computed Parameter: HILInitialize2_EIPEnter
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_EIStart;/* Computed Parameter: HILInitialize2_EIStart
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_EIEnter;/* Computed Parameter: HILInitialize2_EIEnter
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_POPStart;
                                  /* Computed Parameter: HILInitialize2_POPStart
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_POPEnter;
                                  /* Computed Parameter: HILInitialize2_POPEnter
                                   * Referenced by: '<Root>/HIL Initialize2'
                                   */
  boolean_T HILInitialize2_POStart;/* Computed Parameter: HILInitialize2_POStart
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_POEnter;/* Computed Parameter: HILInitialize2_POEnter
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_POReset;/* Computed Parameter: HILInitialize2_POReset
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_OOReset;/* Computed Parameter: HILInitialize2_OOReset
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_DOFinal;/* Computed Parameter: HILInitialize2_DOFinal
                                    * Referenced by: '<Root>/HIL Initialize2'
                                    */
  boolean_T HILInitialize2_DOInitial;
                                 /* Computed Parameter: HILInitialize2_DOInitial
                                  * Referenced by: '<Root>/HIL Initialize2'
                                  */
  boolean_T HILRead1_Active;           /* Computed Parameter: HILRead1_Active
                                        * Referenced by: '<Root>/HIL Read1'
                                        */
  boolean_T HILWrite2_Active;          /* Computed Parameter: HILWrite2_Active
                                        * Referenced by: '<Root>/HIL Write2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Essai2_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][8];
  ODE1_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Essai2_T Essai2_P;

/* Block signals (default storage) */
extern B_Essai2_T Essai2_B;

/* Continuous states (default storage) */
extern X_Essai2_T Essai2_X;

/* Block states (default storage) */
extern DW_Essai2_T Essai2_DW;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void Essai2_initialize(void);
extern void Essai2_output0(void);
extern void Essai2_update0(void);
extern void Essai2_output2(void);
extern void Essai2_update2(void);
extern void Essai2_output(int_T tid);
extern void Essai2_update(int_T tid);
extern void Essai2_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Essai2_rtModel *Essai2(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Essai2_T *const Essai2_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Essai2'
 * '<S1>'   : 'Essai2/PID Controller'
 * '<S2>'   : 'Essai2/Second-Order Low-Pass Filter1'
 * '<S3>'   : 'Essai2/Second-Order Low-Pass Filter3'
 * '<S4>'   : 'Essai2/basicSpeedEstimation1'
 * '<S5>'   : 'Essai2/plot 2D planar vehicle1'
 * '<S6>'   : 'Essai2/simple kinematic 2D steered vehicle model1'
 * '<S7>'   : 'Essai2/PID Controller/Anti-windup'
 * '<S8>'   : 'Essai2/PID Controller/D Gain'
 * '<S9>'   : 'Essai2/PID Controller/Filter'
 * '<S10>'  : 'Essai2/PID Controller/Filter ICs'
 * '<S11>'  : 'Essai2/PID Controller/I Gain'
 * '<S12>'  : 'Essai2/PID Controller/Ideal P Gain'
 * '<S13>'  : 'Essai2/PID Controller/Ideal P Gain Fdbk'
 * '<S14>'  : 'Essai2/PID Controller/Integrator'
 * '<S15>'  : 'Essai2/PID Controller/Integrator ICs'
 * '<S16>'  : 'Essai2/PID Controller/N Copy'
 * '<S17>'  : 'Essai2/PID Controller/N Gain'
 * '<S18>'  : 'Essai2/PID Controller/P Copy'
 * '<S19>'  : 'Essai2/PID Controller/Parallel P Gain'
 * '<S20>'  : 'Essai2/PID Controller/Reset Signal'
 * '<S21>'  : 'Essai2/PID Controller/Saturation'
 * '<S22>'  : 'Essai2/PID Controller/Saturation Fdbk'
 * '<S23>'  : 'Essai2/PID Controller/Sum'
 * '<S24>'  : 'Essai2/PID Controller/Sum Fdbk'
 * '<S25>'  : 'Essai2/PID Controller/Tracking Mode'
 * '<S26>'  : 'Essai2/PID Controller/Tracking Mode Sum'
 * '<S27>'  : 'Essai2/PID Controller/Tsamp - Integral'
 * '<S28>'  : 'Essai2/PID Controller/Tsamp - Ngain'
 * '<S29>'  : 'Essai2/PID Controller/postSat Signal'
 * '<S30>'  : 'Essai2/PID Controller/preSat Signal'
 * '<S31>'  : 'Essai2/PID Controller/Anti-windup/Disabled'
 * '<S32>'  : 'Essai2/PID Controller/D Gain/Disabled'
 * '<S33>'  : 'Essai2/PID Controller/Filter/Disabled'
 * '<S34>'  : 'Essai2/PID Controller/Filter ICs/Disabled'
 * '<S35>'  : 'Essai2/PID Controller/I Gain/Disabled'
 * '<S36>'  : 'Essai2/PID Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'Essai2/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'Essai2/PID Controller/Integrator/Disabled'
 * '<S39>'  : 'Essai2/PID Controller/Integrator ICs/Disabled'
 * '<S40>'  : 'Essai2/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S41>'  : 'Essai2/PID Controller/N Gain/Disabled'
 * '<S42>'  : 'Essai2/PID Controller/P Copy/Disabled'
 * '<S43>'  : 'Essai2/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'Essai2/PID Controller/Reset Signal/Disabled'
 * '<S45>'  : 'Essai2/PID Controller/Saturation/Passthrough'
 * '<S46>'  : 'Essai2/PID Controller/Saturation Fdbk/Disabled'
 * '<S47>'  : 'Essai2/PID Controller/Sum/Passthrough_P'
 * '<S48>'  : 'Essai2/PID Controller/Sum Fdbk/Disabled'
 * '<S49>'  : 'Essai2/PID Controller/Tracking Mode/Disabled'
 * '<S50>'  : 'Essai2/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'Essai2/PID Controller/Tsamp - Integral/Disabled wSignal Specification'
 * '<S52>'  : 'Essai2/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'Essai2/PID Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'Essai2/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_Essai2_h_ */
