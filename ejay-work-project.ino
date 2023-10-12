#include <Stepper.h> 

#define STEPS 200

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver
Stepper stepper(STEPS, 2, 3); // Pin 2 connected to DIRECTION & Pin 3 connected to STEP Pin of Driver

bool clockwise = true;
int switchPin = 7;
int currentSwitchState = LOW;

void setup() {
  // Set the maximum speed in steps per second:
  stepper.setSpeed(500);

  // Setting pin mode for LED & switch pin
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(switchPin, INPUT);

  // LED is off by default
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  if (digitalRead(switchPin) != currentSwitchState) {
    currentSwitchState = digitalRead(switchPin);
    digitalWrite(LED_BUILTIN, currentSwitchState);  // LED is on or off depending on current switch state

    stepper.step(800*8);    // 800 is 360 deg rotation. 800 * 15 means 15 rotations
    delay(5000);
    stepper.step(-800*8);   // 800 is 360 deg rotation. 800 * 15 means 15 rotations
  }
}