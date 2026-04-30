/*
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "fan_control.h"               /* Model header file */

static RT_MODEL_fan_control_T fan_control_M_;
static RT_MODEL_fan_control_T *const fan_control_MPtr = &fan_control_M_;/* Real-time model */

/* Global variables used by function prototype control */

/* '<Root>/Expect_Speed' */
static real_T arg_Expect_Speed = 0.0;

/* '<Root>/Actual_Speed' */
static real_T arg_Actual_Speed = 0.0;

/* '<Root>/Rising_time' */
static real_T arg_Rising_time = 0.0;

/* '<Root>/Overshoot' */
static real_T arg_Overshoot = 0.0;

/* '<Root>/Stable_time' */
static real_T arg_Stable_time = 0.0;

/* '<Root>/Torque_Control' */
static real_T arg_Torque_Control;

/* '<Root>/Damping_ratio' */
static real_T arg_Damping_ratio;

/* '<Root>/Natural_frequency' */
static real_T arg_Natural_frequency;

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_fan_control_T *const fan_control_M);
void rt_OneStep(RT_MODEL_fan_control_T *const fan_control_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(fan_control_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  arg_Torque_Control = Fan_Controller_Exe(fan_control_M, arg_Expect_Speed,
    arg_Actual_Speed, arg_Rising_time, arg_Overshoot, arg_Stable_time,
    &arg_Damping_ratio, &arg_Natural_frequency);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_fan_control_T *const fan_control_M = fan_control_MPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */

  /* Initialize model */
  Fan_Controller_Init(fan_control_M);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.0001 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep(fan_control_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(fan_control_M) == (NULL)) {
    /*  Perform application tasks here */
  }

  /* Terminate model */
  Fan_Controller_terminate(fan_control_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
