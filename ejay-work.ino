#include <Stepper.h> 
#define STEPS 200

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver
Stepper stepper(STEPS, 2, 3); // Pin 2 connected to DIRECTION & Pin 3 connected to STEP Pin of Driver

// boolean variable used to determine which direction the motor should spin
bool clockwise = true;

void setup() {
  // Set the maximum speed in steps per second:
  stepper.setSpeed(500);
  pinMode(LED_BUILTIN, OUTPUT);

  // LED is off by default. If LED is off, it means the motor is waiting to be moved,
  // if LED is on, it means that the motor is currently moving
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  if (clockwise) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn LED on, meaning the motor is moving
    stepper.step(800*8);              // 800 is 360 deg rotation. 800 * 8 means 8 rotations

    digitalWrite(LED_BUILTIN, LOW);   // turn LED off, meaning the motor is not moving
    delay(5000);                      // wait 5 seconds
    
    clockwise = false;
  }
  else {
    digitalWrite(LED_BUILTIN, HIGH);  // turn LED on, meaning the motor is moving
    stepper.step(-800*8);            // 800 is 360 deg rotation. 800 * 8 means 8 rotations

    digitalWrite(LED_BUILTIN, LOW);   // turn LED off, meaning the motor is not moving
    delay(3000);                      // wait 3 seconds
    
    clockwise = true;
  }
}