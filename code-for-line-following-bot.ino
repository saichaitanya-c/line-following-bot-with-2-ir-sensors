#include <Servo.h>

#define IR_SENSOR_RIGHT 3
#define IR_SENSOR_LEFT 2
#define MOTOR_SPEED 90 // Neutral point where servos stop
#define TURN_DURATIONleft 320//
#define TURN_DURATIONright 400

#define LINE_DETECTION_DURATION 10// 

// Servo motor objects
Servo servoRight;
Servo servoLeft;

unsigned long lastActionTime = 0; // Last time an action was taken
int currentAction = 0; // 0: Stop, 1: Straight, 2: Right, 3: Left

void setup() {
  servoRight.attach(11);
  servoLeft.attach(10);
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  stopMotors(); // Ensure motors are stopped at startup
}

void loop() {
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  if (millis() - lastActionTime > LINE_DETECTION_DURATION) {
    if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
      currentAction = 1; // Go straight
    } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
      currentAction = 2; // Turn right
    } else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
      currentAction = 3; // Turn left
    } else {
      currentAction = 0; // Stop
    }
    lastActionTime = millis(); // Reset the timer
    performAction(currentAction); // Perform the selected action
  }
}

void performAction(int action) {
  switch (action) {
    case 1: // Drive straight
      driveStraight();
      break;
    case 2: // Turn right
      turnRight();
      delay(TURN_DURATIONright);
      stopMotors(); // Optional, remove if continuous movement is desired
      break;
    case 3: // Turn left
      turnLeft();
      delay(TURN_DURATIONleft);
      stopMotors(); // Optional, remove if continuous movement is desired
      break;
    default: // Stop
      stopMotors();
      break;
  }
}

void driveStraight() {
  servoRight.write(MOTOR_SPEED + 9); // 
  servoLeft.write(MOTOR_SPEED  + 0); // 
}

void turnRight() {
  servoRight.write(MOTOR_SPEED + 3); //
  servoLeft.write(MOTOR_SPEED - 11); // 
}

void turnLeft() {
  servoRight.write(MOTOR_SPEED + 20); // 
  servoLeft.write(MOTOR_SPEED + 6); // 
}

void stopMotors() {
  servoRight.write(MOTOR_SPEED + 7);
  servoLeft.write(MOTOR_SPEED + 7);
}
