/*
 * File: fan_control_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef FAN_CONTROL_CA_H
#define FAN_CONTROL_CA_H

/* preprocessor validation checks */
#include "fan_control_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_fan_control_HWRes;
extern CA_PWS_TestResults CA_fan_control_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_fan_control_ExpHW;
extern CA_HWImpl CA_fan_control_ActHW;

/* entry point function to run tests */
void fan_control_caRunTests(void);

#endif                                 /* FAN_CONTROL_CA_H */
