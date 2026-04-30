/*
 * File: Fan.c
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

#include "Fan.h"
#include "rtwtypes.h"

/* Includes for objects with custom storage classes */
#include "fan_control.h"

/* System initialize for atomic system: '<Root>/Fan' */
void fan_control_Fan_Init(self_Fan_fan_control_T *fan_control_self_arg)
{
  P_Fan_fan_control_T *localP_0;
  localP_0 = fan_control_self_arg->defaultParam;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  fan_control_self_arg->dwork.DiscreteTimeIntegrator_DSTATE =
    localP_0->DiscreteTimeIntegrator_IC;
}

/* Output and update for atomic system: '<Root>/Fan' */
real_T fan_control_Fan(self_Fan_fan_control_T *fan_control_self_arg, real_T
  rtu_Reference_speed, real_T rtu_Actual_speed, real_T rtu_PID_adjustP, real_T
  rtu_PID_adjustI)
{
  real_T rty_Torque_control_0;
  P_Fan_fan_control_T *localP_1;
  real_T y;
  localP_1 = fan_control_self_arg->defaultParam;

  /* Sum: '<S1>/Sum4' */
  rty_Torque_control_0 = rtu_Reference_speed - rtu_Actual_speed;

  /* Saturate: '<S1>/Speed_Limit' */
  if (rty_Torque_control_0 > Speed_max) {
    y = Speed_max;
  } else if (rty_Torque_control_0 < -Speed_max) {
    y = -Speed_max;
  } else {
    y = rty_Torque_control_0;
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Product: '<S1>/Product'
   *  Saturate: '<S1>/Speed_Limit'
   */
  rty_Torque_control_0 = rtu_PID_adjustP * y +
    fan_control_self_arg->dwork.DiscreteTimeIntegrator_DSTATE;

  /* Saturate: '<S1>/Torque_Limit' */
  if (rty_Torque_control_0 > Torque_max) {
    rty_Torque_control_0 = Torque_max;
  } else if (rty_Torque_control_0 < -Torque_max) {
    rty_Torque_control_0 = -Torque_max;
  }

  /* End of Saturate: '<S1>/Torque_Limit' */

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Product: '<S1>/Product1'
   *  Saturate: '<S1>/Speed_Limit'
   */
  fan_control_self_arg->dwork.DiscreteTimeIntegrator_DSTATE += y *
    rtu_PID_adjustI * localP_1->DiscreteTimeIntegrator_gainval;
  if (fan_control_self_arg->dwork.DiscreteTimeIntegrator_DSTATE > Torque_max) {
    fan_control_self_arg->dwork.DiscreteTimeIntegrator_DSTATE = Torque_max;
  } else if (fan_control_self_arg->dwork.DiscreteTimeIntegrator_DSTATE <
             -Torque_max) {
    fan_control_self_arg->dwork.DiscreteTimeIntegrator_DSTATE = -Torque_max;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  return rty_Torque_control_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
