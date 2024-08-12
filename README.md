# line-following-bot-with-2-ir-sensors
A line-following robot utilizing two infrared (IR) sensors is designed to autonomously navigate a path by detecting and following a line marked on the ground. This robot typically consists of a microcontroller (like an Arduino), two IR sensors, and motors that drive the wheels.

Navigation Logic:

The robot uses the signals from the two IR sensors to determine its movement:
Moving Forward: If both sensors detect white (indicating the robot is on the line), the robot moves forward.

Turning Left: If the left sensor detects black (indicating the robot is straying off the line), the right motor continues to drive forward while the left motor slows down or reverses, causing the robot to turn left.

Turning Right: Conversely, if the right sensor detects black, the left motor drives forward while the right motor slows down or reverses, resulting in a right turn.
Stopping: If both sensors detect black, the robot stops, indicating it is centered on the line.
