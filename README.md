
# Line Following Robot with Digital IR Sensors and Servo Motors

This Arduino sketch controls a line-following robot using two digital infrared (IR) sensors and a pair of servo motors. The robot detects and follows a line on the ground by making real-time adjustments to its movement.

https://github.com/user-attachments/assets/d3f7bf70-db7c-4a47-a237-0450069cd639



#### Components Used:
- **Digital IR Sensors (2x):** Positioned on the right and left sides of the robot to detect the presence of a line.
- **Servo Motors (2x):** Control the movement of the robot, with one motor for each wheel.
- **Arduino Board:** Serves as the central controller, processing sensor inputs and controlling the servos.

#### Code Overview:

1. **Pin Definitions:**
   - `IR_SENSOR_RIGHT` and `IR_SENSOR_LEFT` are defined as digital pins connected to the right and left IR sensors, respectively.
   - `MOTOR_SPEED` is the base speed for the servo motors when the robot is moving straight.
   - `TURN_DURATIONleft` and `TURN_DURATIONright` define the time the robot turns left or right, respectively.
   - `LINE_DETECTION_DURATION` is the interval at which the robot checks the sensor inputs to determine the next action.

2. **Servo Motor Control:**
   - The `Servo` library is used to control the two servos (`servoRight` and `servoLeft`).
   - The motors are initially stopped in the `setup()` function.

3. **Main Loop:**
   - The IR sensor values are continuously read in the `loop()` function using `digitalRead()`.
   - Based on the sensor readings, the robot decides whether to move straight, turn left, turn right, or stop.
   - The `performAction()` function executes the appropriate motor commands based on the detected line position.

4. **Driving Functions:**
   - `driveStraight()`: Moves the robot forward by adjusting the motor speeds.
   - `turnRight()`: Turns the robot to the right.
   - `turnLeft()`: Turns the robot to the left.
   - `stopMotors()`: Stops both motors, halting the robot.

5. **Decision-Making:**
   - The robot makes decisions based on the sensor readings:
     - If both sensors detect the line (`LOW`), the robot moves straight.
     - If only the right sensor detects the line (`HIGH`), the robot turns right.
     - If only the left sensor detects the line (`HIGH`), the robot turns left.
     - If neither sensor detects the line, the robot stops.
   - The decisions are based on the `LINE_DETECTION_DURATION` to ensure smooth and timely responses.

#### Customization:
- **Turn Durations:** `TURN_DURATIONleft` and `TURN_DURATIONright` can be adjusted to control the sharpness and duration of the turns.
- **Motor Speed:** `MOTOR_SPEED` and the values in `driveStraight()`, `turnRight()`, and `turnLeft()` functions can be modified to change the robot's speed and responsiveness.

This code provides a straightforward implementation for a basic line-following robot using digital IR sensors. It’s a great starting point for projects involving autonomous navigation.

---

You can adjust the description as needed to fit your specific project details!
