/*
 * File: fan_control.c
 *
 * Code generated for Simulink model 'fan_control'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Oct 30 17:26:52 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "fan_control.h"
#include "rtwtypes.h"
#include "fan_control_types.h"
#include "fan_control_private.h"
#include "fan_control_Fan.h"
#include "PID_Parameter_Adjustment.h"
#include "fan_control_capi.h"

P_fan_control_T fan_control_P = {
  /* Start of '<Root>/Fan' */
  {
    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S1>/Discrete-Time Integrator'
     */
    0.0001,

    /* Expression: 0
     * Referenced by: '<S1>/Discrete-Time Integrator'
     */
    0.0
  }
  /* End of '<Root>/Fan' */
};

/* System initialize for referenced model: 'fan_control' */
void fan_control_Init(RT_MODEL_fan_control_T * const fan_control_M)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Fan' */
  fan_control_Fan_Init(&fan_control_M->self_Fan);

  /* End of SystemInitialize for SubSystem: '<Root>/Fan' */
}

/* Output and update for referenced model: 'fan_control' */
real_T Fan_Controller_Exe(RT_MODEL_fan_control_T * const fan_control_M, real_T
  arg_Expect_Speed, real_T arg_Actual_Speed, real_T arg_Rising_time, real_T
  arg_Overshoot, real_T arg_Stable_time, real_T *arg_Damping_ratio, real_T
  *arg_Natural_frequency)
{
  real_T Ki;
  real_T Kp;

  /* specified return value */
  real_T arg_Torque_Control;

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  PID_Parameter_Adjustment(fan_control_M, arg_Rising_time, arg_Overshoot,
    arg_Stable_time, &Kp, &Ki, arg_Damping_ratio, arg_Natural_frequency);

  /* Outputs for Atomic SubSystem: '<Root>/Fan' */
  fan_control_Fan(&fan_control_M->self_Fan, arg_Expect_Speed, arg_Actual_Speed,
                  Kp, Ki, &arg_Torque_Control);

  /* End of Outputs for SubSystem: '<Root>/Fan' */
  return arg_Torque_Control;
}

/* Model initialize function */
void Fan_Controller_Init(const char_T **rt_errorStatus, RT_MODEL_fan_control_T *
  const fan_control_M, rtwCAPI_ModelMappingInfo *rt_ParentMMI, const char_T
  *rt_ChildPath, int_T rt_ChildMMIIdx, int_T rt_CSTATEIdx)
{
  /* Registration code */
  {
    /* initialize error status */
    rtmSetErrorStatusPointer(fan_control_M, rt_errorStatus);
    fan_control_M->self_Fan.defaultParam = &fan_control_P.Fan;

    /* Initialize DataMapInfo substructure containing ModelMap for C API */
    {
      fan_control_InitializeDataMapInfo(fan_control_M);
    }
  }

  /* Initialize Parent model MMI */
  if ((rt_ParentMMI != (NULL)) && (rt_ChildPath != (NULL))) {
    rtwCAPI_SetChildMMI(*rt_ParentMMI, rt_ChildMMIIdx,
                        &(fan_control_M->DataMapInfo.mmi));
    rtwCAPI_SetPath(fan_control_M->DataMapInfo.mmi, rt_ChildPath);
    rtwCAPI_MMISetContStateStartIndex(fan_control_M->DataMapInfo.mmi,
      rt_CSTATEIdx);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
