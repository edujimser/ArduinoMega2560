#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LedDigital {
public:
    // Internal enumeration: represents the current state of the LED
    enum class Enum_StateLedDigital {
        OFF,                    // The LED is turned off
        ON,                     // The LED is turned on
        BLINKING,               // The LED is blinking automatically
        BLINKING_MANUAL         // The LED is blinking manually
    };

private:
    uint8_t numberPin;           // Pin associated with the LED
    const char* namePin;         // Name of the LED
    Enum_StateLedDigital state;  // Current state of the LED
    unsigned long timeOn;        // Duration the LED stays on during blinking (in milliseconds)
    unsigned long timeOff;       // Duration the LED stays off during blinking (in milliseconds)

// Constructor: initializes the LED with a pin and a name
public:
    LedDigital(uint8_t pin, const char* name, Enum_StateLedDigital state, unsigned long timeOn, unsigned long timeOff)
        : numberPin(pin), 
          namePin(name),
          state(state), 
          timeOn(timeOn), 
          timeOff(timeOff) 
          
        {
            pinMode(numberPin, OUTPUT);       // Configure pin as output
            switch (state)
            {
            case Enum_StateLedDigital::OFF:
                digitalWrite(numberPin, LOW);
                break;
            case Enum_StateLedDigital::ON:
                digitalWrite(numberPin, HIGH);
                break;
            default:
                digitalWrite(numberPin, LOW);
                break;
            }

        }

};





#endif  // LED_H