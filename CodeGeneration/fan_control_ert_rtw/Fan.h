/*
 * File: Fan.h
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

#ifndef Fan_h_
#define Fan_h_
#ifndef fan_control_COMMON_INCLUDES_
#define fan_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* fan_control_COMMON_INCLUDES_ */

#include "fan_control_types.h"

/* Block states (default storage) for system '<Root>/Fan' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
} DW_Fan_fan_control_T;

/* Parameters for system: '<Root>/Fan' */
struct P_Fan_fan_control_T_ {
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S1>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
};

/* model data, for system '<Root>/Fan' */
typedef struct {
  DW_Fan_fan_control_T dwork;
  P_Fan_fan_control_T* defaultParam;
} self_Fan_fan_control_T;

extern void fan_control_Fan_Init(self_Fan_fan_control_T *fan_control_self_arg);
extern real_T fan_control_Fan(self_Fan_fan_control_T *fan_control_self_arg,
  real_T rtu_Reference_speed, real_T rtu_Actual_speed, real_T rtu_PID_adjustP,
  real_T rtu_PID_adjustI);

#endif                                 /* Fan_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
