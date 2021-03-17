# My Stepper Library
This is a library for the Arduino platform to control a bipolar stepper motor.

## Usage

Download this code and zip the resultant folder. Now, open the Arduino code editor IDE and select ```Sketch -> Include Library -> Add .ZIP Library```. A file browser will open now. Browse and select the zipped file.
Thats it. You can now start using this library!

## Advantages over the Arduino's default stepper library
I wrote this library to add the **release** function for the stepper motor. Basically, when you use the default library provided with the Arduino, it will hold the position of the motor when the motor is idle. There is no option to turn off the power to the motor. This will eventually heat up the motor which is a bad for the motor. So, I have added a release function to my library which will turn off the current supply  to the motor. This will increase the life of the motor and also save energy. If you really want to hold the motor position, then, you can just omit calling the release function.

## Example
```arduino
#include <MyStepper.h>

// define the pins to which the motor is connected
MyStepper mystepper(8,9,10,11);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // move forward 10 steps
  for(int i=0; i<10; i++) {
    mystepper.stepForward();
    delay(300);
  }

  // move backward 10 steps
  for(int i=0; i<10; i++) {
    mystepper.stepBackward();
    delay(300);
  }

  // relsease the motor
  mystepper.release();

  // do not do anything else... just stop here...
  while(true) {
    
  }
}
```

## Functions
**MyStepper mystepper(pin1, pin2, pin3, pin4)** - The constructor accepts 4 integers which are the 4 pins to which the motor is connected to.

None of the below functions have any arguements.

|Function|Description|
|---|---|
|**moveForward()**|moves the motor 1 step forward|
|**moveBackward()**|moves the motor 1 step backward|
|**release()**|stop power supply to motor|

> If release is not called, then the library will hold the motor in it's last position.
