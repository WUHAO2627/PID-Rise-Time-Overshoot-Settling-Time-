/*
 * File: fan_control.c
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

#include "fan_control.h"
#include "rtwtypes.h"
#include "PID_Parameter_Adjustment.h"
#include "Fan.h"
#include "fan_control_capi.h"

/* Model step function */
real_T Fan_Controller_Exe(RT_MODEL_fan_control_T *const fan_control_M, real_T
  arg_Expect_Speed, real_T arg_Actual_Speed, real_T arg_Rising_time, real_T
  arg_Overshoot, real_T arg_Stable_time, real_T *arg_Damping_ratio, real_T
  *arg_Natural_frequency)
{
  real_T Ki;
  real_T Kp;

  /* specified return value */
  real_T arg_Torque_Control;

  /* Outport: '<Root>/Natural_frequency' incorporates:
   *  Inport: '<Root>/Overshoot'
   *  Inport: '<Root>/Rising_time'
   *  Inport: '<Root>/Stable_time'
   *  MATLAB Function: '<Root>/MATLAB Function2'
   *  Outport: '<Root>/Damping_ratio'
   */
  PID_Parameter_Adjustment(fan_control_M, arg_Rising_time, arg_Overshoot,
    arg_Stable_time, &Kp, &Ki, arg_Damping_ratio, arg_Natural_frequency);

  /* Outputs for Atomic SubSystem: '<Root>/Fan' */

  /* Outport: '<Root>/Torque_Control' incorporates:
   *  Inport: '<Root>/Actual_Speed'
   *  Inport: '<Root>/Expect_Speed'
   */
  arg_Torque_Control = fan_control_Fan(&fan_control_M->self_Fan,
    arg_Expect_Speed, arg_Actual_Speed, Kp, Ki);

  /* End of Outputs for SubSystem: '<Root>/Fan' */
  return arg_Torque_Control;
}

/* Model initialize function */
void Fan_Controller_Init(RT_MODEL_fan_control_T *const fan_control_M)
{
  /* Registration code */
  {
    fan_control_M->self_Fan.defaultParam = &fan_control_P.Fan;

    /* Initialize DataMapInfo substructure containing ModelMap for C API */
    fan_control_InitializeDataMapInfo(fan_control_M);
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/Fan' */
  fan_control_Fan_Init(&fan_control_M->self_Fan);

  /* End of SystemInitialize for SubSystem: '<Root>/Fan' */
}

/* Model terminate function */
void Fan_Controller_terminate(RT_MODEL_fan_control_T *const fan_control_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(fan_control_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
