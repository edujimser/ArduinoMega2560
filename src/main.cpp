#include <Arduino.h>
#include "main.h"

//INIT PINS
    PinInfo PIN_DIGITAL_24 = Pins::GPIO[3];

void setup() {                                             // Arduino setup function (runs once at startup)

                                                               //Config System
    configuracionMain systemConfiguration = {
                                                                                                             // Byte 0 (bits 0–7)
        .debugMode = false,                                    // Enable debug mode                          | Byte 0, Bit 0 (LSB)
        .fullDiagnosticsPins = true,                           // Run full pin diagnostics                   | Byte 0, Bit 1
        .diagnoseAnalog = false,                               // Disable analog diagnostics                 | Byte 0, Bit 2
        .diagnoseGPIO = false,                                 // Disable GPIO diagnostics                   | Byte 0, Bit 3
        .diagnosePWM = false,                                  // Disable PWM diagnostics                    | Byte 0, Bit 4
        .diagnoseUART = true,                                  // Enable UART diagnostics                    | Byte 0, Bit 5
        .diagnoseEEPROM = true,                                // Disable EEPROM diagnostics                | Byte 0, Bit 6
        .reserved = false                                      // Byte 0, Bit 7 → reservado o libre (MSB)    | Byte 0, Bit 7
    };

                                                           // Otherwise, run in normal execution mode
    Serial.begin(57600);                                   // start serial communication at 57600 baud
    while (!Serial);                                       
    

    if (systemConfiguration.fullDiagnosticsPins) fullDiagnosticsPins();
    if (systemConfiguration.diagnoseAnalog) diagnoseAnalog();
    if (systemConfiguration.diagnoseGPIO) diagnoseGPIO();
    if (systemConfiguration.diagnosePWM)  diagnosePWM(); 
    if (systemConfiguration.diagnoseUART) diagnoseAllUART();
    if (systemConfiguration.diagnoseEEPROM) DiagnosticsEEPROM::runTest();
    if (systemConfiguration.debugMode) debug_init(); 

    
};


void loop() {
    LedDigital led1(PIN_DIGITAL_24.number, PIN_DIGITAL_24.name, LedDigital::Enum_StateLedDigital::ON, 0, 0);
    
} 
