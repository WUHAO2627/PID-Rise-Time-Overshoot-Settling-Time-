# MBD with PID Controller
MATLAB/Simulink-based Modeling and Control Design for a Fan System

---

## 1. Overview
This repository contains the complete modeling, simulation, and control design for a fan system using MATLAB/Simulink. The primary goal is to design, tune, and validate a PID controller to meet specific transient performance requirements.

---

## 2. Fan System Modeling
Two modeling approaches are used to describe the fan dynamics:

### 2.1 Differential Equation Model
- **Input**: Control Torque (`Torque_Control`)
- **Output**: Actual Fan Speed (`W_actual` / `Fan_speed`)
- **Purpose**: High-fidelity time-domain simulation and verification.

### 2.2 Transfer Function Model
- **Model**: Derived from rate-point identification
  \[
  G(s) = \frac{N(s)}{D(s)}
  \]
- **Purpose**: Control-oriented linear model for controller design and frequency-domain analysis.

---

## 3. PID Controller Design
A simplified PID controller is implemented for closed-loop speed regulation.

### 3.1 Control Structure
- **Reference Input**: Desired Fan Speed (`Reference_Speed` / `Expect_Speed`)
- **Feedback Signal**: Measured Actual Speed (`Actual_Speed`)
- **Controller**: Simplified PID Controller
- **Control Output**: Torque Command (`Torque_control`)

### 3.2 PID Parameters
The controller is tuned to meet specified transient response criteria:
- Proportional Gain: `Kp = 5`
- Integral Gain: `Ki = 11`
- (Derivative action is not used in this simplified implementation)

---

## 4. Performance Specifications & Validation
The controller is validated against three different sets of performance requirements.

| Test Case | Target Rise Time (tr) | Target Overshoot (Mp) | Target Settling Time (ts) | Achieved tr | Achieved Mp | Achieved ts |
|-----------|-----------------------|------------------------|---------------------------|-------------|-------------|-------------|
| 1         | 5 s                   | 10%                    | 10 s                      | 4.2 s       | 14%         | 10 s        |
| 2         | 10 s                  | 5%                     | 20 s                      | 9.7 s       | 5.3%        | 22 s        |
| 3         | 20 s                  | 5%                     | 30 s                      | 21 s        | 3.3%        | 30 s        |

Key performance metrics analyzed include:
- Rise Time (`tr`)
- Overshoot (`Mp`)
- Damping Ratio (`ζ`)
- Natural Frequency (`ωn`)
- Settling Time (`ts`)

---

## 5. Model Validation
Both the differential equation and transfer function models are compared under identical input conditions to ensure dynamic consistency.
- **Validation**: Time-domain response comparison
- **Result**: Both models exhibit nearly identical behavior, confirming the accuracy of the linearized model.

---

## 6. Code Generation
The Simulink model is configured for embedded code generation.

### 6.1 Generated Code Structure
- **Top-Level Functions**:
  - `Fan_Controller_Init()`: Initializes model states and parameters
  - `Fan_Controller_Exe()`: Executes one time step of the controller
  - `Fan_Controller_Terminate()`: Cleans up resources
- **Subsystem-Level Functions**:
  - `Fan_Control_PID_Init()`: Initializes the PID controller
  - `Fan_Control_PID()`: Executes the PID algorithm
  - `PID_Parameter_Adjustment()`: Online parameter tuning interface

### 6.2 SIL (Software-in-the-Loop)
- The generated C code can be used for SIL simulation to verify algorithm behavior in a software environment before hardware deployment.

---

## 7. HIL (Hardware-in-the-Loop) Testing 
- Target Platform: RT-LAB / OPAL-RT real-time simulator
- Status: Awaiting license update for full real-time simulation and debugging capabilities.

---

## 8. Repository Structure
```text
├── fan/                     # Fan system model files
├── CodeGeneration/          # Generated C code artifacts
├── Pictures/                # Simulation results and plots
├── Validation/              # Model validation scripts and data
├── FanModelingandController.pptx  # Project presentation slides
├── calc_PI2.m               # MATLAB script for PID calculation
├── *.slx / *.slxc           # Simulink model and configuration files
├── *.sldd                   # Simulink data dictionary files
└── README.md                # This document
