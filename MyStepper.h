#ifndef MyStepper_h
#define MyStepper_h
#include "Arduino.h"
class MyStepper {
    public:
        MyStepper(int pin1, int pin2, int pin3, int pin4);
        void stepForward();
        void stepBackward();
        void release();
    private:
        int _pin1, _pin2, _pin3, _pin4, _sequence_position;
        uint8_t _step_sequence[4][4]={
            {LOW, HIGH, LOW, HIGH},
            {HIGH, LOW, LOW, HIGH},
            {HIGH, LOW, HIGH, LOW},
            {LOW, HIGH, HIGH, LOW}
        };
        uint8_t _release_sequence[4] = {LOW, LOW, LOW, LOW};
        void setOutput(uint8_t* _sequence);
};
#endif
