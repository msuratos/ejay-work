#include <Stepper.h>
#include <ezButton.h>

#define STEPS 200

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver
Stepper stepper(STEPS, 2, 3); // Pin 2 connected to DIRECTION & Pin 3 connected to STEP Pin of Driver

// Create ezButton object that attach to pin 7 for the top switch
ezButton topLimitSwitch(7);

// Create ezButton object that attach to pin 8 for the bottom switch
ezButton bottomLimitSwitch(8);

// boolean variable used to determine which direction the motor should spin
bool clockwise = true;

void setup() {
  // Set the maximum speed in steps per second:
  stepper.setSpeed(500);

  // Set debounce time to 50 milliseconds
  topLimitSwitch.setDebounceTime(50);
  bottomLimitSwitch.setDebounceTime(50);

  // Set built-in LED pin to OUTPUT
  pinMode(LED_BUILTIN, OUTPUT);

  // LED is off by default. If LED is off, it means the motor is waiting to be moved,
  // if LED is on, it means that the motor is currently moving
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // MUST call the loop() function first
  topLimitSwitch.loop();
  bottomLimitSwitch.loop();

  int topSwitchState = topLimiteSwitch.getState();
  int bottomSwitchState = bottomLimitSwitch.getState();

  // top switch is pressed, set clockwise and wait 3 seconds
  if (topSwitchState.isPressed() || topSwitchState == HIGH) {
    clockwise = true;

    digitalWrite(LED_BUILTIN, LOW);   // turn LED off, meaning the motor is not moving
    delay(3000);
  }

  // bottom switch is pressed, set clockwise and wait 5 seconds
  if (bottomSwitchState.isPressed() || bottomSwitchState == HIGH) {
    clockwise = false;

    digitalWrite(LED_BUILTIN, LOW);   // turn LED off, meaning the motor is not moving
    delay(5000);
  }

  // if clockwise, top switch was pressed, so continue spinning the motor clockwise
  // until we get bottom switch pressed
  if (clockwise) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn LED on, meaning the motor is moving
    stepper.step(800*1);              // 800 is 360 deg rotation. 800 * 1 means 1 rotation
  }
  // if not clockwise, bottom switch was pressed, so continue spinning the motor counter-clockwise
  // until we get top switch pressed
  else {
    digitalWrite(LED_BUILTIN, HIGH);  // turn LED on, meaning the motor is moving
    stepper.step(-800*1);            // 800 is 360 deg rotation. 800 * 1 means 1 rotation
  }
}