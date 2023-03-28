#include <Servo.h>

Servo servo_base; //Naming of base servo 
Servo servo_claw; //Naming of claw servo 
Servo servo_right; //Naming of right hand servo
Servo servo_left; //Naming of left hand side servo
const int base_pin = A0;
const int right_pin = A1;
const int left_pin = A2;
const int claw_pin = A3;

void setup() {
  Serial.begin(9600); //This is the baud rate (how many bits per second)
  servo_claw.attach(3); 
  servo_base.attach(4);
  servo_left.attach(5); 
  servo_right.attach(6);
}

void loop() {
// left between 0 and 130
// right between 130 and 180
// base between 0 and 180 
// claw design doesn't work

  int base_angle = analogRead(base_pin);
  base_angle = map(base_angle, 0, 1023, 0, 180);
  servo_base.write(base_angle);
  delay(5);

  int right_angle = analogRead(right_pin);
  right_angle = map(right_angle, 0, 1023, 130, 180);
  servo_right.write(right_angle);
  delay(5);

  int left_angle = analogRead(left_pin);
  left_angle = map(left_angle, 0, 1023, 0, 130);
  servo_left.write(left_angle);
  delay(5);

  int claw_angle = analogRead(claw_pin);
  claw_angle = map(claw_angle, 0, 1023, 0, 180);
  servo_claw.write(claw_angle);
  delay(5);
}
