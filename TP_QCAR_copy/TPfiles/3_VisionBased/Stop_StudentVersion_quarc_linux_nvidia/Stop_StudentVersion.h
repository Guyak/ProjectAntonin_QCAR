/*
 * Stop_StudentVersion.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Stop_StudentVersion".
 *
 * Model version              : 5.9
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Oct 18 10:54:14 2022
 *
 * Target selection: quarc_linux_nvidia.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Stop_StudentVersion_h_
#define RTW_HEADER_Stop_StudentVersion_h_
#include <math.h>
#include <string.h>
#ifndef Stop_StudentVersion_COMMON_INCLUDES_
#define Stop_StudentVersion_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "quanser_image_processing.h"
#include "quanser_messages.h"
#include "quanser_memory.h"
#include "quanser_channel.h"
#include "extmode_support.h"
#include "hil.h"
#include "quanser_types.h"
#include "quanser_video3d.h"
#include "quanser_string.h"
#include "quanser_time.h"
#include "quanser_extern.h"
#endif                                /* Stop_StudentVersion_COMMON_INCLUDES_ */

#include "Stop_StudentVersion_types.h"

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
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
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
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
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
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
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
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
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
#define Stop_StudentVersion_rtModel    RT_MODEL_Stop_StudentVersion_T

/* Block signals (default storage) */
typedef struct {
  uint8_T ImageTransform[2764800];     /* '<S16>/Image Transform' */
  t_uint64 Depth_o2;                   /* '<S6>/Depth' */
  t_uint64 RGB_o2;                     /* '<S6>/RGB' */
  real_T encodercounts;                /* '<S3>/HIL Read' */
  real_T Unwrap224;                    /* '<S3>/Unwrap 2^24' */
  real_T Product;                      /* '<S11>/Product' */
  real_T Product1;                     /* '<S11>/Product1' */
  real_T Depth_o3;                     /* '<S6>/Depth' */
  real_T RGB_o3;                       /* '<S6>/RGB' */
  real_T desired;                      /* '<S10>/Multiply1' */
  real_T Kffms;                        /* '<S10>/Kff  (% // m//s)' */
  real_T measured;                     /* '<S10>/Multiply' */
  real_T commandsaturation;            /* '<S3>/command saturation' */
  real_T Kim;                          /* '<S10>/Ki (% // m)  ' */
  real_T actualsampletime;             /* '<S9>/Sample Time' */
  real_T reference;                    /* '<S9>/Constant' */
  real_T computationtime;              /* '<S9>/Computation Time' */
  real_T Constant;                     /* '<S8>/Constant' */
  real_T Subtract[2];                  /* '<S8>/Subtract' */
  t_channel Channel;                   /* '<S13>/Channel' */
  t_channel Channel_o;                 /* '<S15>/Channel' */
  t_channel Channel_a;                 /* '<S12>/Channel' */
  real32_T Depth_o1[921600];           /* '<S6>/Depth' */
  real32_T Selector;                   /* '<S7>/Selector' */
  uint8_T RGB_o1[2764800];             /* '<S6>/RGB' */
  uint8_T ImageCompress[921600];       /* '<S13>/Image Compress' */
  uint8_T ImageCompress_g[2764800];    /* '<S15>/Image Compress' */
  uint8_T ImageCompress_c[921600];     /* '<S12>/Image Compress' */
  uint8_T HSVColorThresholding[921600];/* '<S16>/HSV Color Thresholding' */
  boolean_T RGB_o4;                    /* '<S6>/RGB' */
  boolean_T Compare;                   /* '<S18>/Compare' */
  boolean_T Compare_c;                 /* '<S14>/Compare' */
} B_Stop_StudentVersion_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  t_timeout SampleTime_PreviousTime;   /* '<S9>/Sample Time' */
  t_timeout ComputationTime_BeginTime; /* '<S9>/Computation Time' */
  t_timeout ComputationTime_ComputationTime;/* '<S9>/Computation Time' */
  real_T HILInitialize_AIMinimums[7];  /* '<S3>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[7];  /* '<S3>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[5];/* '<S3>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[8];/* '<S3>/HIL Initialize' */
  real_T HILInitialize_POValues[8];    /* '<S3>/HIL Initialize' */
  real_T HILInitialize_OOValues[13];   /* '<S3>/HIL Initialize' */
  real_T HILRead_AnalogBuffer[2];      /* '<S3>/HIL Read' */
  real_T Unwrap224_PreviousInput;      /* '<S3>/Unwrap 2^24' */
  real_T Unwrap224_Revolutions;        /* '<S3>/Unwrap 2^24' */
  t_video3d Depth_Video3D;             /* '<S6>/Depth' */
  t_video3d RGB_Video3D;               /* '<S6>/RGB' */
  t_video3d Video3DInitialize_Video3D; /* '<S6>/Video3D Initialize' */
  t_video3d_stream Depth_Stream;       /* '<S6>/Depth' */
  t_video3d_stream RGB_Stream;         /* '<S6>/RGB' */
  t_jpeg_compress ImageCompress_Compress;/* '<S13>/Image Compress' */
  t_jpeg_compress ImageCompress_Compress_c;/* '<S15>/Image Compress' */
  t_jpeg_compress ImageCompress_Compress_g;/* '<S12>/Image Compress' */
  t_find_blobs ImageFindObjects_FindHandle;/* '<S8>/Image Find Objects' */
  t_image_rgb_to_hsv ImageTransform_AlgHandle;/* '<S16>/Image Transform' */
  t_card HILInitialize_Card;           /* '<S3>/HIL Initialize' */
  void *HILRead_PWORK;                 /* '<S3>/HIL Read' */
  void *HILWrite_PWORK;                /* '<S3>/HIL Write' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S10>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<Root>/Scope' */

  struct {
    void *Fifo;
  } Channel_PWORK;                     /* '<S13>/Channel' */

  struct {
    void *Fifo;
  } Channel_PWORK_d;                   /* '<S15>/Channel' */

  struct {
    void *Fifo;
  } Channel_PWORK_f;                   /* '<S12>/Channel' */

  int32_T HILInitialize_DOStates;      /* '<S3>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[5];/* '<S3>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[5];/* '<S3>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[8];/* '<S3>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[8];/* '<S3>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[8];/* '<S3>/HIL Initialize' */
  int32_T HILRead_EncoderBuffer;       /* '<S3>/HIL Read' */
  int32_T ImageCompress_DIMS1;         /* '<S13>/Image Compress' */
  int32_T ImageCompress_DIMS1_l;       /* '<S15>/Image Compress' */
  int32_T ImageCompress_DIMS1_e;       /* '<S12>/Image Compress' */
  uint32_T HILInitialize_POSortedChans[8];/* '<S3>/HIL Initialize' */
  int_T Integrator1_IWORK;             /* '<S11>/Integrator1' */
  int8_T findStopSignLocation_SubsysRanB;/* '<Root>/findStopSignLocation' */
  int8_T findStopSignDistance_SubsysRanB;/* '<Root>/findStopSignDistance' */
  uint8_T ImageCompress_ScanLine[10240];/* '<S13>/Image Compress' */
  uint8_T ImageCompress_ScanLine_a[30720];/* '<S15>/Image Compress' */
  uint8_T ImageCompress_ScanLine_c[10240];/* '<S12>/Image Compress' */
  boolean_T Unwrap224_FirstSample;     /* '<S3>/Unwrap 2^24' */
} DW_Stop_StudentVersion_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S11>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S11>/Integrator2' */
  real_T Integrator1_CSTATE_o;         /* '<S10>/Integrator1' */
} X_Stop_StudentVersion_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S11>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S11>/Integrator2' */
  real_T Integrator1_CSTATE_o;         /* '<S10>/Integrator1' */
} XDot_Stop_StudentVersion_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S11>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S11>/Integrator2' */
  boolean_T Integrator1_CSTATE_o;      /* '<S10>/Integrator1' */
} XDis_Stop_StudentVersion_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator1_Reset_ZCE;    /* '<S10>/Integrator1' */
} PrevZCX_Stop_StudentVersion_T;

#ifndef ODE2_INTG
#define ODE2_INTG

/* ODE2 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[2];                        /* derivatives */
} ODE2_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Stop_StudentVersion_B
#define BlockIO                        B_Stop_StudentVersion_T
#define rtX                            Stop_StudentVersion_X
#define ContinuousStates               X_Stop_StudentVersion_T
#define rtXdot                         Stop_StudentVersion_XDot
#define StateDerivatives               XDot_Stop_StudentVersion_T
#define tXdis                          Stop_StudentVersion_XDis
#define StateDisabled                  XDis_Stop_StudentVersion_T
#define rtP                            Stop_StudentVersion_P
#define Parameters                     P_Stop_StudentVersion_T
#define rtDWork                        Stop_StudentVersion_DW
#define D_Work                         DW_Stop_StudentVersion_T
#define rtPrevZCSigState               Stop_StudentVersion_PrevZCX
#define PrevZCSigStates                PrevZCX_Stop_StudentVersion_T

/* Parameters (default storage) */
struct P_Stop_StudentVersion_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S17>/Constant'
                                       */
  int32_T HSVColorThresholding_b_comparis;
                              /* Mask Parameter: HSVColorThresholding_b_comparis
                               * Referenced by: '<S16>/HSV Color Thresholding'
                               */
  int32_T ImageFindObjects_connectivity;
                                /* Mask Parameter: ImageFindObjects_connectivity
                                 * Referenced by: '<S8>/Image Find Objects'
                                 */
  int32_T HSVColorThresholding_g_comparis;
                              /* Mask Parameter: HSVColorThresholding_g_comparis
                               * Referenced by: '<S16>/HSV Color Thresholding'
                               */
  int32_T HSVColorThresholding_r_comparis;
                              /* Mask Parameter: HSVColorThresholding_r_comparis
                               * Referenced by: '<S16>/HSV Color Thresholding'
                               */
  int32_T ImageFindObjects_sort_order;
                                  /* Mask Parameter: ImageFindObjects_sort_order
                                   * Referenced by: '<S8>/Image Find Objects'
                                   */
  uint32_T HILRead_analog_channels[2];/* Mask Parameter: HILRead_analog_channels
                                       * Referenced by: '<S3>/HIL Read'
                                       */
  uint32_T CompareToConstant_const_h;
                                    /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S14>/Constant'
                                     */
  uint32_T HILRead_encoder_channels; /* Mask Parameter: HILRead_encoder_channels
                                      * Referenced by: '<S3>/HIL Read'
                                      */
  uint32_T ImageFindObjects_max_pixels;
                                  /* Mask Parameter: ImageFindObjects_max_pixels
                                   * Referenced by: '<S8>/Image Find Objects'
                                   */
  uint32_T ImageFindObjects_min_pixels;
                                  /* Mask Parameter: ImageFindObjects_min_pixels
                                   * Referenced by: '<S8>/Image Find Objects'
                                   */
  uint32_T HILWrite_other_channels;   /* Mask Parameter: HILWrite_other_channels
                                       * Referenced by: '<S3>/HIL Write'
                                       */
  uint32_T HILWrite_pwm_channels;      /* Mask Parameter: HILWrite_pwm_channels
                                        * Referenced by: '<S3>/HIL Write'
                                        */
  uint32_T Depth_stream_index;         /* Mask Parameter: Depth_stream_index
                                        * Referenced by: '<S6>/Depth'
                                        */
  uint32_T RGB_stream_index;           /* Mask Parameter: RGB_stream_index
                                        * Referenced by: '<S6>/RGB'
                                        */
  boolean_T Video3DInitialize_active;/* Mask Parameter: Video3DInitialize_active
                                      * Referenced by: '<S6>/Video3D Initialize'
                                      */
  boolean_T ImageFindObjects_exclude_at_edg;
                              /* Mask Parameter: ImageFindObjects_exclude_at_edg
                               * Referenced by: '<S8>/Image Find Objects'
                               */
  boolean_T ImageFindObjects_largest;/* Mask Parameter: ImageFindObjects_largest
                                      * Referenced by: '<S8>/Image Find Objects'
                                      */
  real_T Constant_Value;               /* Expression: 720/2
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T AdjustforVFOV_Gain;           /* Expression: 42.5/57
                                        * Referenced by: '<S7>/Adjust for V-FOV'
                                        */
  real_T AdjustforHFOV_Gain;           /* Expression: 69.4/86
                                        * Referenced by: '<S7>/Adjust for H-FOV'
                                        */
  real_T Constant1_Value;              /* Expression: 1280/2
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant1_Value_j;            /* Expression: 255
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T blobLocationpx2_Y0;           /* Computed Parameter: blobLocationpx2_Y0
                                        * Referenced by: '<S8>/blobLocation (px) [2]'
                                        */
  real_T ImageTransform_MinPixel;      /* Expression: min_pixel
                                        * Referenced by: '<S16>/Image Transform'
                                        */
  real_T ImageTransform_MaxPixel;      /* Expression: max_pixel
                                        * Referenced by: '<S16>/Image Transform'
                                        */
  real_T ImageTransform_FocalLen;      /* Expression: focal_length
                                        * Referenced by: '<S16>/Image Transform'
                                        */
  real_T ImageTransform_Extrapolated;  /* Expression: extrapolated
                                        * Referenced by: '<S16>/Image Transform'
                                        */
  real_T ImageTransform_Angle;         /* Expression: angle
                                        * Referenced by: '<S16>/Image Transform'
                                        */
  real_T ImageTransform_RCoeff[2];     /* Expression: radial_coeffs
                                        * Referenced by: '<S16>/Image Transform'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T HueThreshold_Value;           /* Expression: 20
                                        * Referenced by: '<S16>/Hue Threshold'
                                        */
  real_T Gain_Gain;                    /* Expression: 255/360
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Constant1_Value_a[2];         /* Expression: [100, 100]
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant2_Value[2];           /* Expression: [255, 255]
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T HSVColorThresholding_Channel0Mi;/* Expression: r_min
                                          * Referenced by: '<S16>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel0Ma;/* Expression: r_max
                                          * Referenced by: '<S16>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel1Mi;/* Expression: g_min
                                          * Referenced by: '<S16>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel1Ma;/* Expression: g_max
                                          * Referenced by: '<S16>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel2Mi;/* Expression: b_min
                                          * Referenced by: '<S16>/HSV Color Thresholding'
                                          */
  real_T HSVColorThresholding_Channel2Ma;/* Expression: b_max
                                          * Referenced by: '<S16>/HSV Color Thresholding'
                                          */
  real_T Constant3_Value[2];           /* Expression: [720/2, 1280/2]
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T HILInitialize_OOTerminate;/* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  real_T HILInitialize_OOExit;    /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<S3>/HIL Initialize'
                                   */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;    /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_OOFinal;        /* Expression: final_other_outputs
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_EIFrequency;    /* Expression: encoder_filter_frequency
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_POWatchdog;     /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_OOInitial;      /* Expression: initial_other_outputs
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T Constant1_Value_n;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 25
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Constant_Value_o;             /* Expression: 2
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Unwrap224_Modulus;            /* Expression: modulus
                                        * Referenced by: '<S3>/Unwrap 2^24'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S11>/Integrator2'
                                        */
  real_T Depth_Brightness;             /* Expression: d_brightness
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_Contrast;               /* Expression: d_contrast
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_Hue;                    /* Expression: d_hue
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_Saturation;             /* Expression: d_saturation
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_Sharpness;              /* Expression: d_sharpness
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_Gamma;                  /* Expression: d_gamma
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_WhiteBalance;           /* Expression: d_whitebalance
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_BacklightCompensation;  /* Expression: d_backlightcompensation
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_Gain;                   /* Expression: d_gain
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_Exposure;               /* Expression: d_exposure
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T Depth_Emitter;                /* Expression: emitter
                                        * Referenced by: '<S6>/Depth'
                                        */
  real_T RGB_Brightness;               /* Expression: d_brightness
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_Contrast;                 /* Expression: d_contrast
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_Hue;                      /* Expression: d_hue
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_Saturation;               /* Expression: d_saturation
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_Sharpness;                /* Expression: d_sharpness
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_Gamma;                    /* Expression: d_gamma
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_WhiteBalance;             /* Expression: d_whitebalance
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_BacklightCompensation;    /* Expression: d_backlightcompensation
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_Gain;                     /* Expression: d_gain
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_Exposure;                 /* Expression: d_exposure
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T RGB_Emitter;                  /* Expression: emitter
                                        * Referenced by: '<S6>/RGB'
                                        */
  real_T ms_Value;                     /* Expression: 0.2
                                        * Referenced by: '<Root>/m//s'
                                        */
  real_T commandsaturation_UpperSat;   /* Expression: 5
                                        * Referenced by: '<S10>/command saturation'
                                        */
  real_T commandsaturation_LowerSat;   /* Expression: -5
                                        * Referenced by: '<S10>/command saturation'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Kffms_Gain;                   /* Expression: 0.1
                                        * Referenced by: '<S10>/Kff  (% // m//s)'
                                        */
  real_T countstorotations_Gain;       /* Expression: 1/720/4
                                        * Referenced by: '<S5>/counts to rotations'
                                        */
  real_T gearratios_Gain;              /* Expression: (13*19)/(70*37)
                                        * Referenced by: '<S5>/gear ratios'
                                        */
  real_T rotstorads_Gain;              /* Expression: 2*pi
                                        * Referenced by: '<S5>/rot//s to rad//s'
                                        */
  real_T wheelradius_Gain;             /* Expression: 0.0342
                                        * Referenced by: '<S5>/wheel radius'
                                        */
  real_T Kpms_Gain;                    /* Expression: 0.3
                                        * Referenced by: '<S10>/Kp (% // m//s)'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S10>/Integrator1'
                                        */
  real_T Integrator1_UpperSat;         /* Expression: 0.4
                                        * Referenced by: '<S10>/Integrator1'
                                        */
  real_T Integrator1_LowerSat;         /* Expression: -0.4
                                        * Referenced by: '<S10>/Integrator1'
                                        */
  real_T directionconvention_Gain;     /* Expression: -1
                                        * Referenced by: '<S3>/direction convention'
                                        */
  real_T commandsaturation_UpperSat_e; /* Expression: 0.25
                                        * Referenced by: '<S3>/command saturation'
                                        */
  real_T commandsaturation_LowerSat_h; /* Expression: -0.25
                                        * Referenced by: '<S3>/command saturation'
                                        */
  real_T Steering_Value;               /* Expression: 0.0
                                        * Referenced by: '<S3>/Steering'
                                        */
  real_T Gain_Gain_j;                  /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T SteeringBias_Bias;            /* Expression: 0.0
                                        * Referenced by: '<S3>/Steering Bias'
                                        */
  real_T Kim_Gain;                     /* Expression: 1
                                        * Referenced by: '<S10>/Ki (% // m)  '
                                        */
  real_T Constant_Value_e;             /* Expression: qc_get_step_size
                                        * Referenced by: '<S9>/Constant'
                                        */
  int32_T ImageTransform_PrPoint[2];
                                   /* Computed Parameter: ImageTransform_PrPoint
                                    * Referenced by: '<S16>/Image Transform'
                                    */
  int32_T ImageTransform_Interpolation;
                             /* Computed Parameter: ImageTransform_Interpolation
                              * Referenced by: '<S16>/Image Transform'
                              */
  int32_T ImageTransform_Origin[2]; /* Computed Parameter: ImageTransform_Origin
                                     * Referenced by: '<S16>/Image Transform'
                                     */
  int32_T ImageTransform_OOrigin[2];
                                   /* Computed Parameter: ImageTransform_OOrigin
                                    * Referenced by: '<S16>/Image Transform'
                                    */
  int32_T HILInitialize_EIInitial;/* Computed Parameter: HILInitialize_EIInitial
                                   * Referenced by: '<S3>/HIL Initialize'
                                   */
  int32_T HILInitialize_POModes[2]; /* Computed Parameter: HILInitialize_POModes
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  int32_T HILInitialize_POConfiguration;
                            /* Computed Parameter: HILInitialize_POConfiguration
                             * Referenced by: '<S3>/HIL Initialize'
                             */
  int32_T HILInitialize_POAlignment;
                                /* Computed Parameter: HILInitialize_POAlignment
                                 * Referenced by: '<S3>/HIL Initialize'
                                 */
  int32_T HILInitialize_POPolarity;
                                 /* Computed Parameter: HILInitialize_POPolarity
                                  * Referenced by: '<S3>/HIL Initialize'
                                  */
  real32_T distanceToSignm_Y0;         /* Computed Parameter: distanceToSignm_Y0
                                        * Referenced by: '<S7>/distanceToSign (m)'
                                        */
  uint32_T ImageCompress_Quality;   /* Computed Parameter: ImageCompress_Quality
                                     * Referenced by: '<S12>/Image Compress'
                                     */
  uint32_T ImageTransform_ColorTheme;
                                /* Computed Parameter: ImageTransform_ColorTheme
                                 * Referenced by: '<S16>/Image Transform'
                                 */
  uint32_T ImageCompress_Quality_o;
                                  /* Computed Parameter: ImageCompress_Quality_o
                                   * Referenced by: '<S13>/Image Compress'
                                   */
  uint32_T ImageCompress_Quality_f;
                                  /* Computed Parameter: ImageCompress_Quality_f
                                   * Referenced by: '<S15>/Image Compress'
                                   */
  uint32_T HILInitialize_AIChannels[7];
                                 /* Computed Parameter: HILInitialize_AIChannels
                                  * Referenced by: '<S3>/HIL Initialize'
                                  */
  uint32_T HILInitialize_DIChannels[20];
                                 /* Computed Parameter: HILInitialize_DIChannels
                                  * Referenced by: '<S3>/HIL Initialize'
                                  */
  uint32_T HILInitialize_DOChannels;
                                 /* Computed Parameter: HILInitialize_DOChannels
                                  * Referenced by: '<S3>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIChannels[5];
                                 /* Computed Parameter: HILInitialize_EIChannels
                                  * Referenced by: '<S3>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIQuadrature[2];
                               /* Computed Parameter: HILInitialize_EIQuadrature
                                * Referenced by: '<S3>/HIL Initialize'
                                */
  uint32_T HILInitialize_POChannels[8];
                                 /* Computed Parameter: HILInitialize_POChannels
                                  * Referenced by: '<S3>/HIL Initialize'
                                  */
  uint32_T HILInitialize_OOChannels[13];
                                 /* Computed Parameter: HILInitialize_OOChannels
                                  * Referenced by: '<S3>/HIL Initialize'
                                  */
  uint32_T Depth_Preset;               /* Computed Parameter: Depth_Preset
                                        * Referenced by: '<S6>/Depth'
                                        */
  uint32_T RGB_Preset;                 /* Computed Parameter: RGB_Preset
                                        * Referenced by: '<S6>/RGB'
                                        */
  boolean_T VideoDisplay_UseHardware;
                                 /* Computed Parameter: VideoDisplay_UseHardware
                                  * Referenced by: '<S12>/Video Display'
                                  */
  boolean_T blobFound_Y0;              /* Computed Parameter: blobFound_Y0
                                        * Referenced by: '<S8>/blobFound?'
                                        */
  boolean_T VideoDisplay_UseHardware_g;
                               /* Computed Parameter: VideoDisplay_UseHardware_g
                                * Referenced by: '<S13>/Video Display'
                                */
  boolean_T VideoDisplay_UseHardware_d;
                               /* Computed Parameter: VideoDisplay_UseHardware_d
                                * Referenced by: '<S15>/Video Display'
                                */
  boolean_T HILInitialize_Active;    /* Computed Parameter: HILInitialize_Active
                                      * Referenced by: '<S3>/HIL Initialize'
                                      */
  boolean_T HILInitialize_AOTerminate;
                                /* Computed Parameter: HILInitialize_AOTerminate
                                 * Referenced by: '<S3>/HIL Initialize'
                                 */
  boolean_T HILInitialize_AOExit;    /* Computed Parameter: HILInitialize_AOExit
                                      * Referenced by: '<S3>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOTerminate;
                                /* Computed Parameter: HILInitialize_DOTerminate
                                 * Referenced by: '<S3>/HIL Initialize'
                                 */
  boolean_T HILInitialize_DOExit;    /* Computed Parameter: HILInitialize_DOExit
                                      * Referenced by: '<S3>/HIL Initialize'
                                      */
  boolean_T HILInitialize_POTerminate;
                                /* Computed Parameter: HILInitialize_POTerminate
                                 * Referenced by: '<S3>/HIL Initialize'
                                 */
  boolean_T HILInitialize_POExit;    /* Computed Parameter: HILInitialize_POExit
                                      * Referenced by: '<S3>/HIL Initialize'
                                      */
  boolean_T HILInitialize_CKPStart;/* Computed Parameter: HILInitialize_CKPStart
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKPEnter;/* Computed Parameter: HILInitialize_CKPEnter
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKStart;  /* Computed Parameter: HILInitialize_CKStart
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_CKEnter;  /* Computed Parameter: HILInitialize_CKEnter
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AIPStart;/* Computed Parameter: HILInitialize_AIPStart
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AIPEnter;/* Computed Parameter: HILInitialize_AIPEnter
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPStart;/* Computed Parameter: HILInitialize_AOPStart
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPEnter;/* Computed Parameter: HILInitialize_AOPEnter
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOStart;  /* Computed Parameter: HILInitialize_AOStart
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOEnter;  /* Computed Parameter: HILInitialize_AOEnter
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOReset;  /* Computed Parameter: HILInitialize_AOReset
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOPStart;/* Computed Parameter: HILInitialize_DOPStart
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOPEnter;/* Computed Parameter: HILInitialize_DOPEnter
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOStart;  /* Computed Parameter: HILInitialize_DOStart
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOEnter;  /* Computed Parameter: HILInitialize_DOEnter
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOReset;  /* Computed Parameter: HILInitialize_DOReset
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIPStart;/* Computed Parameter: HILInitialize_EIPStart
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIPEnter;/* Computed Parameter: HILInitialize_EIPEnter
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIStart;  /* Computed Parameter: HILInitialize_EIStart
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIEnter;  /* Computed Parameter: HILInitialize_EIEnter
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POPStart;/* Computed Parameter: HILInitialize_POPStart
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POPEnter;/* Computed Parameter: HILInitialize_POPEnter
                                    * Referenced by: '<S3>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POStart;  /* Computed Parameter: HILInitialize_POStart
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POEnter;  /* Computed Parameter: HILInitialize_POEnter
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POReset;  /* Computed Parameter: HILInitialize_POReset
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_OOReset;  /* Computed Parameter: HILInitialize_OOReset
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOFinal;  /* Computed Parameter: HILInitialize_DOFinal
                                     * Referenced by: '<S3>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOInitial;
                                  /* Computed Parameter: HILInitialize_DOInitial
                                   * Referenced by: '<S3>/HIL Initialize'
                                   */
  boolean_T HILRead_Active;            /* Computed Parameter: HILRead_Active
                                        * Referenced by: '<S3>/HIL Read'
                                        */
  boolean_T HILWrite_Active;           /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<S3>/HIL Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Stop_StudentVersion_T {
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
  real_T odeY[3];
  real_T odeF[2][3];
  ODE2_IntgData intgData;
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
    boolean_T firstInitCondFlag;
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
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Stop_StudentVersion_T Stop_StudentVersion_P;

/* Block signals (default storage) */
extern B_Stop_StudentVersion_T Stop_StudentVersion_B;

/* Continuous states (default storage) */
extern X_Stop_StudentVersion_T Stop_StudentVersion_X;

/* Block states (default storage) */
extern DW_Stop_StudentVersion_T Stop_StudentVersion_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Stop_StudentVersion_T Stop_StudentVersion_PrevZCX;

/* Model entry point functions */
extern void Stop_StudentVersion_initialize(void);
extern void Stop_StudentVersion_output(void);
extern void Stop_StudentVersion_update(void);
extern void Stop_StudentVersion_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Stop_StudentVersion_rtModel *Stop_StudentVersion(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Stop_StudentVersion_T *const Stop_StudentVersion_M;

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
 * '<Root>' : 'Stop_StudentVersion'
 * '<S1>'   : 'Stop_StudentVersion/MATLAB Function1'
 * '<S2>'   : 'Stop_StudentVersion/Powered by QUARC'
 * '<S3>'   : 'Stop_StudentVersion/QCar'
 * '<S4>'   : 'Stop_StudentVersion/Quanser'
 * '<S5>'   : 'Stop_StudentVersion/basicSpeedEstimation'
 * '<S6>'   : 'Stop_StudentVersion/captureRGBD'
 * '<S7>'   : 'Stop_StudentVersion/findStopSignDistance'
 * '<S8>'   : 'Stop_StudentVersion/findStopSignLocation'
 * '<S9>'   : 'Stop_StudentVersion/monitorTiming '
 * '<S10>'  : 'Stop_StudentVersion/speedController'
 * '<S11>'  : 'Stop_StudentVersion/QCar/Second-Order Low-Pass Filter'
 * '<S12>'  : 'Stop_StudentVersion/findStopSignDistance/Depth Image (m)'
 * '<S13>'  : 'Stop_StudentVersion/findStopSignLocation/Binary showing blob found'
 * '<S14>'  : 'Stop_StudentVersion/findStopSignLocation/Compare To Constant'
 * '<S15>'  : 'Stop_StudentVersion/findStopSignLocation/Raw RGB'
 * '<S16>'  : 'Stop_StudentVersion/findStopSignLocation/colorThresholdingHSV'
 * '<S17>'  : 'Stop_StudentVersion/findStopSignLocation/colorThresholdingHSV/Compare To Constant'
 * '<S18>'  : 'Stop_StudentVersion/speedController/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_Stop_StudentVersion_h_ */
