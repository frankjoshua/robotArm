// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

int pwm_b = 11;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_b = 13;  //dir control for motor outputs 3 and 4 is on digital pin 13

AF_DCMotor mGripper(1);
AF_DCMotor mRotor(2);
AF_DCMotor mTopArm(3);
AF_DCMotor mArm(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  
  //pinMode(pwm_b, OUTPUT);  //Set control pins to be outputs
  //pinMode(dir_b, OUTPUT);
  
  // turn on motor
  mGripper.setSpeed(200);
  mGripper.run(RELEASE);
  mRotor.setSpeed(200);
  mRotor.run(RELEASE);
  mTopArm.setSpeed(200);
  mTopArm.run(RELEASE);
  mArm.setSpeed(200);
  mArm.run(RELEASE);
}

void loop() {
  //analogWrite(pwm_b, 0);
  
  //digitalWrite(dir_b, LOW);
  
  if (Serial.available() > 2) {
      char c[1];
      c[0] = Serial.read();
      int m = atoi(c);
      c[0] = Serial.read();
      int dir = atoi(c);
      c[0] = Serial.read();
      int wait = atoi(c) * 250;
      AF_DCMotor motor = getMotor(m);
      Serial.println(m);
      Serial.println(dir);
      motor.run(dir);
      delay(wait);
  }
//  mArm.run(BACKWARD);
//  mTopArm.run(BACKWARD);
//  mRotor.run(BACKWARD);
//  delay(1000);
//  mArm.run(FORWARD);
//  mTopArm.run(FORWARD);
//  mRotor.run(FORWARD);
//  delay(1250);
//  mArm.run(RELEASE);
//  mTopArm.run(RELEASE);
//  mRotor.run(RELEASE);
//  delay(1000);
//  quickMotorTest(motor2, FORWARD, 500);
//  quickMotorTest(motor2, BACKWARD, 500);
//  quickMotorTest(motor3, BACKWARD, 3000);
//  quickMotorTest(motor3, FORWARD, 3000);
//  quickMotorTest(motor1, FORWARD, 500);
//  quickMotorTest(motor1, BACKWARD, 500);
  //delay(1000);
}

AF_DCMotor getMotor(int motorNum){
  switch(motorNum){
    case 1:
      return mRotor;
    case 2:
      return mArm;
    case 3:
      return mTopArm;
    case 4:
      return mGripper;
    default:
      return mGripper;  
  }
}

void quickMotorTest(AF_DCMotor motor, int dir, int time){
  motor.run(dir);
  delay(time);
  motor.run(RELEASE);
}

void motorTest(AF_DCMotor motor){
    uint8_t i;
  
  Serial.print("tick");
  
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tock");

  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  

  Serial.print("tech");
  motor.run(RELEASE);
}
