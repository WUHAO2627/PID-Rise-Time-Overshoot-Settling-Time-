/*
 * File: fan_control.h
 *
 * Code generated for Simulink model 'fan_control'.
 *
 * Model version                  : 1.49
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Oct 29 17:12:54 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef fan_control_h_
#define fan_control_h_
#ifndef fan_control_COMMON_INCLUDES_
#define fan_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* fan_control_COMMON_INCLUDES_ */

#include "fan_control_types.h"
#include "Fan.h"
#include "rtw_modelmap.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define Speed_max                      437.03                    /* Referenced by: '<S1>/Speed_Limit' */
#define Torque_max                     26.25                     /* Referenced by:
                                                                  * '<S1>/Discrete-Time Integrator'
                                                                  * '<S1>/Torque_Limit'
                                                                  */

/* Parameters (default storage) */
struct P_fan_control_T_ {
  P_Fan_fan_control_T Fan;             /* '<Root>/Fan' */
};

/* Self model data, for system '<Root>' */
struct tag_RTM_fan_control_T {
  const char_T * volatile errorStatus;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[2];
    int32_T* vardimsAddress[2];
    RTWLoggingFcnPtr loggingPtrs[2];
  } DataMapInfo;

  self_Fan_fan_control_T self_Fan;
};

/* Block parameters (default storage) */
extern P_fan_control_T fan_control_P;

/* Model entry point functions */
extern void Fan_Controller_Init(RT_MODEL_fan_control_T *const fan_control_M);
extern void Fan_Controller_terminate(RT_MODEL_fan_control_T *const fan_control_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  fan_control_GetCAPIStaticMap(void);

/* Customized model step function */
extern real_T Fan_Controller_Exe(RT_MODEL_fan_control_T *const fan_control_M,
  real_T arg_Expect_Speed, real_T arg_Actual_Speed, real_T arg_Rising_time,
  real_T arg_Overshoot, real_T arg_Stable_time, real_T *arg_Damping_ratio,
  real_T *arg_Natural_frequency);

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
 * '<Root>' : 'fan_control'
 * '<S1>'   : 'fan_control/Fan'
 * '<S2>'   : 'fan_control/MATLAB Function2'
 */
#endif                                 /* fan_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
