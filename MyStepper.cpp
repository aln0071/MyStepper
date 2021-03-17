#include "Arduino.h"
#include "MyStepper.h"
MyStepper::MyStepper(int pin1, int pin2, int pin3, int pin4) {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
    _pin1 = pin1;
    _pin2 = pin2;
    _pin3 = pin3;
    _pin4 = pin4;
    _sequence_position = 0;
}

void MyStepper::setOutput(uint8_t* _sequence) {
  digitalWrite(_pin1, _sequence[0]);
  digitalWrite(_pin2, _sequence[1]);
  digitalWrite(_pin3, _sequence[2]);
  digitalWrite(_pin4, _sequence[3]);
}

void MyStepper::stepForward() {
    _sequence_position = (_sequence_position+1)%4;
    setOutput(_step_sequence[_sequence_position]);
}

void MyStepper::stepBackward() {
  _sequence_position = _sequence_position-1;
  if(_sequence_position < 0) {
    _sequence_position = 3;
  }
  setOutput(_step_sequence[_sequence_position]);
}

void MyStepper::release() {
    setOutput(_release_sequence);
}
