#ifndef MAIN_H
#define MAIN_H

#include "system/pinout/pinout.h"
#include <avr8-stub.h>                                     // AVR8 debugging stub for GDB
#include <HardwareSerial.h>                                // Serial communication support
#include "system/diagnostics/diagnosticsUART.h"            // UART diagnostics functions
#include "system/diagnostics/diagnosticsEEPROM.h"
#include "system/config/config.h"                          // System configuration parameters
#include "system/pinout/pinout.h"                          // Pinout definitions
#include "module_ledControl/led.h"                        // LED control module

#endif  // MAIN_H