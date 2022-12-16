/*
 * Path_following_TP.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Path_following_TP".
 *
 * Model version              : 5.4
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 17 14:15:34 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Path_following_TP_h_
#define RTW_HEADER_Path_following_TP_h_
#include <math.h>
#include <string.h>
#ifndef Path_following_TP_COMMON_INCLUDES_
#define Path_following_TP_COMMON_INCLUDES_
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
#endif                                 /* Path_following_TP_COMMON_INCLUDES_ */

#include "Path_following_TP_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

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
#define Path_following_TP_rtModel      RT_MODEL_Path_following_TP_T

/* Block signals (default storage) */
typedef struct {
  real_T waypoints_data[1258];
  real_T Integrator;                   /* '<S5>/Integrator' */
  real_T Integrator1;                  /* '<S5>/Integrator1' */
  real_T psi_headingrad;               /* '<S5>/Integrator2' */
  real_T desired;                      /* '<S6>/Multiply1' */
  real_T Product1;                     /* '<S2>/Product1' */
  real_T Offset;                       /* '<S3>/Offset' */
  real_T measured;                     /* '<S6>/Multiply' */
  real_T commandsaturation;            /* '<Root>/command saturation' */
  real_T Product;                      /* '<S1>/Product' */
  real_T anglesaturation1;             /* '<Root>/angle saturation1' */
  real_T motorcounts;                  /* '<Root>/HIL Read' */
  real_T Unwrap224;                    /* '<Root>/Unwrap 2^24' */
  real_T Product_e;                    /* '<S2>/Product' */
  real_T psidotrads;                   /* '<S5>/Product2' */
  real_T v_Xms;                        /* '<S5>/Sum' */
  real_T v_Yms;                        /* '<S5>/Sum1' */
  real_T Kim;                          /* '<S6>/Ki (% // m)  ' */
  real_T RateTransition[4];            /* '<S4>/Rate Transition' */
  real_T PurePursuit_o1;               /* '<Root>/Pure Pursuit' */
  boolean_T Compare;                   /* '<S7>/Compare' */
} B_Path_following_TP_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  nav_slalgs_internal_PurePursu_T obj; /* '<Root>/Pure Pursuit' */
  real_T AnimationSFunction_DSTATE[6]; /* '<S4>/Animation S-Function' */
  real_T HILInitialize1_AIMinimums[7]; /* '<Root>/HIL Initialize1' */
  real_T HILInitialize1_AIMaximums[7]; /* '<Root>/HIL Initialize1' */
  real_T HILInitialize1_FilterFrequency[5];/* '<Root>/HIL Initialize1' */
  real_T HILInitialize1_POSortedFreqs[8];/* '<Root>/HIL Initialize1' */
  real_T HILInitialize1_POValues[8];   /* '<Root>/HIL Initialize1' */
  real_T HILInitialize1_OOValues[13];  /* '<Root>/HIL Initialize1' */
  real_T HILRead_OtherBuffer[2];       /* '<Root>/HIL Read' */
  real_T Unwrap224_PreviousInput;      /* '<Root>/Unwrap 2^24' */
  real_T Unwrap224_Revolutions;        /* '<Root>/Unwrap 2^24' */
  t_card HILInitialize1_Card;          /* '<Root>/HIL Initialize1' */
  void *HILWrite1_PWORK;               /* '<Root>/HIL Write1' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  void *HILRead_PWORK;                 /* '<Root>/HIL Read' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S6>/Scope' */

  int32_T HILInitialize1_DOStates;     /* '<Root>/HIL Initialize1' */
  int32_T HILInitialize1_QuadratureModes[5];/* '<Root>/HIL Initialize1' */
  int32_T HILInitialize1_InitialEICounts[5];/* '<Root>/HIL Initialize1' */
  int32_T HILInitialize1_POModeValues[8];/* '<Root>/HIL Initialize1' */
  int32_T HILInitialize1_POAlignValues[8];/* '<Root>/HIL Initialize1' */
  int32_T HILInitialize1_POPolarityVals[8];/* '<Root>/HIL Initialize1' */
  int32_T HILRead_EncoderBuffer[2];    /* '<Root>/HIL Read' */
  uint32_T HILInitialize1_POSortedChans[8];/* '<Root>/HIL Initialize1' */
  int_T Integrator1_IWORK;             /* '<S2>/Integrator1' */
  boolean_T Unwrap224_FirstSample;     /* '<Root>/Unwrap 2^24' */
  boolean_T objisempty;                /* '<Root>/Pure Pursuit' */
} DW_Path_following_TP_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S5>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S5>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S5>/Integrator2' */
  real_T Integrator2_CSTATE_o;         /* '<S2>/Integrator2' */
  real_T Integrator1_CSTATE_f;         /* '<S6>/Integrator1' */
  real_T Integrator1_CSTATE_d;         /* '<S2>/Integrator1' */
} X_Path_following_TP_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S5>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S5>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S5>/Integrator2' */
  real_T Integrator2_CSTATE_o;         /* '<S2>/Integrator2' */
  real_T Integrator1_CSTATE_f;         /* '<S6>/Integrator1' */
  real_T Integrator1_CSTATE_d;         /* '<S2>/Integrator1' */
} XDot_Path_following_TP_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S5>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S5>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S5>/Integrator2' */
  boolean_T Integrator2_CSTATE_o;      /* '<S2>/Integrator2' */
  boolean_T Integrator1_CSTATE_f;      /* '<S6>/Integrator1' */
  boolean_T Integrator1_CSTATE_d;      /* '<S2>/Integrator1' */
} XDis_Path_following_TP_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator1_Reset_ZCE;    /* '<S6>/Integrator1' */
} PrevZCX_Path_following_TP_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Path_following_TP_B
#define BlockIO                        B_Path_following_TP_T
#define rtX                            Path_following_TP_X
#define ContinuousStates               X_Path_following_TP_T
#define rtXdot                         Path_following_TP_XDot
#define StateDerivatives               XDot_Path_following_TP_T
#define tXdis                          Path_following_TP_XDis
#define StateDisabled                  XDis_Path_following_TP_T
#define rtP                            Path_following_TP_P
#define Parameters                     P_Path_following_TP_T
#define rtDWork                        Path_following_TP_DW
#define D_Work                         DW_Path_following_TP_T
#define rtPrevZCSigState               Path_following_TP_PrevZCX
#define PrevZCSigStates                PrevZCX_Path_following_TP_T

/* Parameters (default storage) */
struct P_Path_following_TP_T_ {
  real_T X_ic;                         /* Variable: X_ic
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T Y_ic;                         /* Variable: Y_ic
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T p2[1258];                     /* Variable: p2
                                        * Referenced by: '<Root>/waypoint matrix'
                                        */
  real_T vehicle_length;               /* Variable: vehicle_length
                                        * Referenced by:
                                        *   '<S5>/1//L'
                                        *   '<S5>/Gain'
                                        */
  real_T yaw_ic;                       /* Variable: yaw_ic
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  uint32_T HILRead_encoder_channels[2];
                                     /* Mask Parameter: HILRead_encoder_channels
                                      * Referenced by: '<Root>/HIL Read'
                                      */
  uint32_T HILWrite1_other_channels; /* Mask Parameter: HILWrite1_other_channels
                                      * Referenced by: '<Root>/HIL Write1'
                                      */
  uint32_T HILRead_other_channels[2];  /* Mask Parameter: HILRead_other_channels
                                        * Referenced by: '<Root>/HIL Read'
                                        */
  uint32_T HILWrite1_pwm_channels;     /* Mask Parameter: HILWrite1_pwm_channels
                                        * Referenced by: '<Root>/HIL Write1'
                                        */
  real_T PurePursuit_DesiredLinearVeloci;/* Expression: 0.2
                                          * Referenced by: '<Root>/Pure Pursuit'
                                          */
  real_T PurePursuit_MaxAngularVelocity;/* Expression: 1
                                         * Referenced by: '<Root>/Pure Pursuit'
                                         */
  real_T PurePursuit_LookaheadDistance;/* Expression: 0.05
                                        * Referenced by: '<Root>/Pure Pursuit'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T HILInitialize1_OOTerminate;
                                   /* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  real_T HILInitialize1_OOExit;   /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  real_T HILInitialize1_OOStart;       /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T HILInitialize1_OOEnter;   /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  real_T HILInitialize1_POFinal;       /* Expression: final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T HILInitialize1_OOFinal;       /* Expression: final_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T HILInitialize1_AIHigh;        /* Expression: analog_input_maximums
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T HILInitialize1_AILow;         /* Expression: analog_input_minimums
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T HILInitialize1_EIFrequency;   /* Expression: encoder_filter_frequency
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T HILInitialize1_POFrequency;   /* Expression: pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T HILInitialize1_POInitial;     /* Expression: initial_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T HILInitialize1_POWatchdog;    /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T HILInitialize1_OOInitial;     /* Expression: initial_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize1'
                                        */
  real_T commandsaturation_UpperSat;   /* Expression: 0.8
                                        * Referenced by: '<S6>/command saturation'
                                        */
  real_T commandsaturation_LowerSat;   /* Expression: -0.8
                                        * Referenced by: '<S6>/command saturation'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Kffms_Gain;                   /* Expression: 0.1
                                        * Referenced by: '<S6>/Kff  (% // m//s)'
                                        */
  real_T Constant2_Value;              /* Expression: 25
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator2'
                                        */
  real_T countstorotations_Gain;       /* Expression: 1/720/4
                                        * Referenced by: '<S3>/counts to rotations'
                                        */
  real_T gearratios_Gain;              /* Expression: (13*19)/(70*37)
                                        * Referenced by: '<S3>/gear ratios'
                                        */
  real_T rotstorads_Gain;              /* Expression: 2*pi
                                        * Referenced by: '<S3>/rot//s to rad//s'
                                        */
  real_T wheelradius_Gain;             /* Expression: 0.0342
                                        * Referenced by: '<S3>/wheel radius'
                                        */
  real_T Offset_Gain;                  /* Expression: 0.87
                                        * Referenced by: '<S3>/Offset'
                                        */
  real_T Kpms_Gain;                    /* Expression: 0.3
                                        * Referenced by: '<S6>/Kp (% // m//s)'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Integrator1_UpperSat;         /* Expression: 0.1
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Integrator1_LowerSat;         /* Expression: -0.1
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Motor_commandsat_UpperSat;    /* Expression: 0.5
                                        * Referenced by: '<S6>/Motor_command  sat'
                                        */
  real_T Motor_commandsat_LowerSat;    /* Expression: -0.5
                                        * Referenced by: '<S6>/Motor_command  sat'
                                        */
  real_T directionconvention_Gain;     /* Expression: -1
                                        * Referenced by: '<Root>/direction convention'
                                        */
  real_T commandsaturation_UpperSat_e; /* Expression: 0.20
                                        * Referenced by: '<Root>/command saturation'
                                        */
  real_T commandsaturation_LowerSat_k; /* Expression: -0.20
                                        * Referenced by: '<Root>/command saturation'
                                        */
  real_T Constant6_Value;              /* Expression: 2
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Bicyclelength_Value;          /* Expression: 0.256
                                        * Referenced by: '<S1>/Bicycle length'
                                        */
  real_T SineWaveFunction_Amp;         /* Expression: 1
                                        * Referenced by: '<S1>/Sine Wave Function'
                                        */
  real_T SineWaveFunction_Bias;        /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave Function'
                                        */
  real_T SineWaveFunction_Freq;        /* Expression: 1
                                        * Referenced by: '<S1>/Sine Wave Function'
                                        */
  real_T SineWaveFunction_Phase;       /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave Function'
                                        */
  real_T Lookaheaddistance_Value;      /* Expression: 0.05
                                        * Referenced by: '<S1>/Lookahead distance'
                                        */
  real_T anglesaturation1_UpperSat;    /* Expression: 0.5
                                        * Referenced by: '<Root>/angle saturation1'
                                        */
  real_T anglesaturation1_LowerSat;    /* Expression: -0.5
                                        * Referenced by: '<Root>/angle saturation1'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant_Value_n;             /* Expression: 2
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Unwrap224_Modulus;            /* Expression: modulus
                                        * Referenced by: '<Root>/Unwrap 2^24'
                                        */
  real_T Kim_Gain;                     /* Expression: 1
                                        * Referenced by: '<S6>/Ki (% // m)  '
                                        */
  int32_T HILInitialize1_EIInitial;
                                 /* Computed Parameter: HILInitialize1_EIInitial
                                  * Referenced by: '<Root>/HIL Initialize1'
                                  */
  int32_T HILInitialize1_POModes[2];
                                   /* Computed Parameter: HILInitialize1_POModes
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  int32_T HILInitialize1_POConfiguration;
                           /* Computed Parameter: HILInitialize1_POConfiguration
                            * Referenced by: '<Root>/HIL Initialize1'
                            */
  int32_T HILInitialize1_POAlignment;
                               /* Computed Parameter: HILInitialize1_POAlignment
                                * Referenced by: '<Root>/HIL Initialize1'
                                */
  int32_T HILInitialize1_POPolarity;
                                /* Computed Parameter: HILInitialize1_POPolarity
                                 * Referenced by: '<Root>/HIL Initialize1'
                                 */
  uint32_T HILInitialize1_AIChannels[7];
                                /* Computed Parameter: HILInitialize1_AIChannels
                                 * Referenced by: '<Root>/HIL Initialize1'
                                 */
  uint32_T HILInitialize1_DIChannels[20];
                                /* Computed Parameter: HILInitialize1_DIChannels
                                 * Referenced by: '<Root>/HIL Initialize1'
                                 */
  uint32_T HILInitialize1_DOChannels;
                                /* Computed Parameter: HILInitialize1_DOChannels
                                 * Referenced by: '<Root>/HIL Initialize1'
                                 */
  uint32_T HILInitialize1_EIChannels[5];
                                /* Computed Parameter: HILInitialize1_EIChannels
                                 * Referenced by: '<Root>/HIL Initialize1'
                                 */
  uint32_T HILInitialize1_EIQuadrature[2];
                              /* Computed Parameter: HILInitialize1_EIQuadrature
                               * Referenced by: '<Root>/HIL Initialize1'
                               */
  uint32_T HILInitialize1_POChannels[8];
                                /* Computed Parameter: HILInitialize1_POChannels
                                 * Referenced by: '<Root>/HIL Initialize1'
                                 */
  uint32_T HILInitialize1_OOChannels[13];
                                /* Computed Parameter: HILInitialize1_OOChannels
                                 * Referenced by: '<Root>/HIL Initialize1'
                                 */
  boolean_T HILInitialize1_Active;  /* Computed Parameter: HILInitialize1_Active
                                     * Referenced by: '<Root>/HIL Initialize1'
                                     */
  boolean_T HILInitialize1_AOTerminate;
                               /* Computed Parameter: HILInitialize1_AOTerminate
                                * Referenced by: '<Root>/HIL Initialize1'
                                */
  boolean_T HILInitialize1_AOExit;  /* Computed Parameter: HILInitialize1_AOExit
                                     * Referenced by: '<Root>/HIL Initialize1'
                                     */
  boolean_T HILInitialize1_DOTerminate;
                               /* Computed Parameter: HILInitialize1_DOTerminate
                                * Referenced by: '<Root>/HIL Initialize1'
                                */
  boolean_T HILInitialize1_DOExit;  /* Computed Parameter: HILInitialize1_DOExit
                                     * Referenced by: '<Root>/HIL Initialize1'
                                     */
  boolean_T HILInitialize1_POTerminate;
                               /* Computed Parameter: HILInitialize1_POTerminate
                                * Referenced by: '<Root>/HIL Initialize1'
                                */
  boolean_T HILInitialize1_POExit;  /* Computed Parameter: HILInitialize1_POExit
                                     * Referenced by: '<Root>/HIL Initialize1'
                                     */
  boolean_T HILInitialize1_CKPStart;
                                  /* Computed Parameter: HILInitialize1_CKPStart
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_CKPEnter;
                                  /* Computed Parameter: HILInitialize1_CKPEnter
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_CKStart;/* Computed Parameter: HILInitialize1_CKStart
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_CKEnter;/* Computed Parameter: HILInitialize1_CKEnter
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_AIPStart;
                                  /* Computed Parameter: HILInitialize1_AIPStart
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_AIPEnter;
                                  /* Computed Parameter: HILInitialize1_AIPEnter
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_AOPStart;
                                  /* Computed Parameter: HILInitialize1_AOPStart
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_AOPEnter;
                                  /* Computed Parameter: HILInitialize1_AOPEnter
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_AOStart;/* Computed Parameter: HILInitialize1_AOStart
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_AOEnter;/* Computed Parameter: HILInitialize1_AOEnter
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_AOReset;/* Computed Parameter: HILInitialize1_AOReset
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_DOPStart;
                                  /* Computed Parameter: HILInitialize1_DOPStart
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_DOPEnter;
                                  /* Computed Parameter: HILInitialize1_DOPEnter
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_DOStart;/* Computed Parameter: HILInitialize1_DOStart
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_DOEnter;/* Computed Parameter: HILInitialize1_DOEnter
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_DOReset;/* Computed Parameter: HILInitialize1_DOReset
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_EIPStart;
                                  /* Computed Parameter: HILInitialize1_EIPStart
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_EIPEnter;
                                  /* Computed Parameter: HILInitialize1_EIPEnter
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_EIStart;/* Computed Parameter: HILInitialize1_EIStart
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_EIEnter;/* Computed Parameter: HILInitialize1_EIEnter
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_POPStart;
                                  /* Computed Parameter: HILInitialize1_POPStart
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_POPEnter;
                                  /* Computed Parameter: HILInitialize1_POPEnter
                                   * Referenced by: '<Root>/HIL Initialize1'
                                   */
  boolean_T HILInitialize1_POStart;/* Computed Parameter: HILInitialize1_POStart
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_POEnter;/* Computed Parameter: HILInitialize1_POEnter
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_POReset;/* Computed Parameter: HILInitialize1_POReset
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_OOReset;/* Computed Parameter: HILInitialize1_OOReset
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_DOFinal;/* Computed Parameter: HILInitialize1_DOFinal
                                    * Referenced by: '<Root>/HIL Initialize1'
                                    */
  boolean_T HILInitialize1_DOInitial;
                                 /* Computed Parameter: HILInitialize1_DOInitial
                                  * Referenced by: '<Root>/HIL Initialize1'
                                  */
  boolean_T HILWrite1_Active;          /* Computed Parameter: HILWrite1_Active
                                        * Referenced by: '<Root>/HIL Write1'
                                        */
  boolean_T HILRead_Active;            /* Computed Parameter: HILRead_Active
                                        * Referenced by: '<Root>/HIL Read'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Path_following_TP_T {
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
  real_T odeF[1][6];
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
extern P_Path_following_TP_T Path_following_TP_P;

/* Block signals (default storage) */
extern B_Path_following_TP_T Path_following_TP_B;

/* Continuous states (default storage) */
extern X_Path_following_TP_T Path_following_TP_X;

/* Block states (default storage) */
extern DW_Path_following_TP_T Path_following_TP_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Path_following_TP_T Path_following_TP_PrevZCX;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void Path_following_TP_initialize(void);
extern void Path_following_TP_output0(void);
extern void Path_following_TP_update0(void);
extern void Path_following_TP_output2(void);
extern void Path_following_TP_update2(void);
extern void Path_following_TP_output(int_T tid);
extern void Path_following_TP_update(int_T tid);
extern void Path_following_TP_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Path_following_TP_rtModel *Path_following_TP(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Path_following_TP_T *const Path_following_TP_M;

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
 * '<Root>' : 'Path_following_TP'
 * '<S1>'   : 'Path_following_TP/AlphaToDelta'
 * '<S2>'   : 'Path_following_TP/Second-Order Low-Pass Filter'
 * '<S3>'   : 'Path_following_TP/basicSpeedEstimation'
 * '<S4>'   : 'Path_following_TP/plot 2D planar vehicle'
 * '<S5>'   : 'Path_following_TP/simple kinematic 2D steered vehicle model'
 * '<S6>'   : 'Path_following_TP/speedController'
 * '<S7>'   : 'Path_following_TP/speedController/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_Path_following_TP_h_ */
