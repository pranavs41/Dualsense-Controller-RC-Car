# Dualsense-Controller-RC-Car

A remotely-controlled RC car built around an ESP32 with a custom PCB, 
driven by a DualSense (PS5) controller over Bluetooth. Includes an 
ultrasonic distance sensor for automatic collision avoidance.

## Features
- BLE pairing with PS5 DualSense controller
- Analog stick control for variable-speed forward/reverse and turning
- DRV8833 motor driver for dual DC motors
- Ultrasonic distance sensor stops forward motion 
  when an obstacle is detected within [X] cm
- Custom PCB designed in KiCad — schematic and gerbers in `/pcb`
- Custom chassis designed in Onshape and 3D printed

## Hardware
- ESP32 DevKit V1
- DRV8833 dual H-bridge motor driver
- 2× DC motors + chassis
- HC-SR04 ultrasonic distance sensor (or whichever you used)
- 7.4 V Li-ion battery
- Custom PCB — see `/pcb` folder

## Firmware
- Platform: PlatformIO
- Framework: Arduino
- Key libraries:
  - Bluepad32 (for PS5 controller pairing)

## PCB
Custom PCB designed in KiCad. Schematic, board files, and gerbers in 
the `/pcb` folder.

## Status
Working. Built and tested 12/15/25.
