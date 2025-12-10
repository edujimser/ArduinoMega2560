#include <Arduino.h>
#include "main.h"

void setup() {                                             // Arduino setup function (runs once at startup)
                                                           // Otherwise, run in normal execution mode
    Serial.begin(57600);                                   // start serial communication at 57600 baud
    while (!Serial);                                       
    
                                                           //Config System
    configuracionMain systemConfiguration = {
    .debugMode = false,                                    // Enable debug mode
    .fullDiagnosticsPins = true,                           // Run full pin diagnostics
    .diagnoseAnalog = false,                               // Disable analog diagnostics
    .diagnoseGPIO = false,                                 // Disable GPIO diagnostics
    .diagnosePWM = false,                                  // Disable PWM diagnostics
    .diagnoseUART = true,                                  // Enable UART diagnostics
    .diagnoseEEPROM = true                                 // Disable EEPROM diagnostics
    };

    if (systemConfiguration.fullDiagnosticsPins) fullDiagnosticsPins();
    if (systemConfiguration.diagnoseAnalog) diagnoseAnalog();
    if (systemConfiguration.diagnoseGPIO) diagnoseGPIO();
    if (systemConfiguration.diagnosePWM)  diagnosePWM();
    if (systemConfiguration.diagnoseUART) diagnoseAllUART();
    if (systemConfiguration.diagnoseEEPROM) DiagnosticsEEPROM::runTest();
    if (systemConfiguration.debugMode) debug_init(); 
};


void loop() {
} 
