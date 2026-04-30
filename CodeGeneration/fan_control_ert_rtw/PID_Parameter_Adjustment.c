/*
 * File: PID_Parameter_Adjustment.c
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

#include "rtwtypes.h"
#include "PID_Parameter_Adjustment.h"
#include <math.h>
#include "rt_defines.h"
#include "fan_control.h"

/* Output and update for atomic system: '<Root>/MATLAB Function2' */
void PID_Parameter_Adjustment(RT_MODEL_fan_control_T * const fan_control_M,
  real_T rtu_T_Rising, real_T rtu_Over_shoot, real_T rtu_T_Stable, real_T
  *rty_Kp, real_T *rty_Ki, real_T *rty_Damping, real_T *rty_Freq)
{
  real_T Damping_0;
  real_T a_tmp;
  UNUSED_PARAMETER(fan_control_M);
  a_tmp = log(rtu_Over_shoot / 100.0);
  Damping_0 = -a_tmp / sqrt(a_tmp * a_tmp + 9.869604401089358);
  a_tmp = (4.0 / (Damping_0 * rtu_T_Stable) + 1.8 / rtu_T_Rising) / 2.0;
  *rty_Kp = fmax((2.0 * Damping_0 * a_tmp - 0.2334) / 2.857, 0.0);
  *rty_Ki = fmax(a_tmp * a_tmp / 2.857, 0.0);
  *rty_Damping = Damping_0;
  *rty_Freq = a_tmp;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
