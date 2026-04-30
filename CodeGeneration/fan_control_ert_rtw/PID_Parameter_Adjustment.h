/*
 * File: PID_Parameter_Adjustment.h
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

#ifndef PID_Parameter_Adjustment_h_
#define PID_Parameter_Adjustment_h_
#ifndef fan_control_COMMON_INCLUDES_
#define fan_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* fan_control_COMMON_INCLUDES_ */

#include "rt_defines.h"
#include "fan_control_types.h"

extern void PID_Parameter_Adjustment(RT_MODEL_fan_control_T * const
  fan_control_M, real_T rtu_T_Rising, real_T rtu_Over_shoot, real_T rtu_T_Stable,
  real_T *rty_Kp, real_T *rty_Ki, real_T *rty_Damping, real_T *rty_Freq);

#endif                                 /* PID_Parameter_Adjustment_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
