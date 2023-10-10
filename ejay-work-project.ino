#include <Stepper.h> 

#define STEPS 200

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver
Stepper stepper(STEPS, 2, 3); // Pin 2 connected to DIRECTION & Pin 3 connected to STEP Pin of Driver

bool clockwise = true;

void setup() {
  // Set the maximum speed in steps per second:
  stepper.setSpeed(500);
  pinMode(LED_BUILTIN, OUTPUT);

  // LED is on by default
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  if (clockwise) {
    stepper.step(800*15);   // 800 is 360 deg rotation. 800 * 15 means 15 rotations
    delay(5000);
    digitalWrite(LED_BUILTIN, LOW);
    clockwise = false;
  }
  else {
    stepper.step(-800*15);     // 800 is 360 deg rotation. 800 * 15 means 15 rotations
    delay(5000);
    digitalWrite(LED_BUILTIN, HIGH);
    clockwise = true;
  }
}