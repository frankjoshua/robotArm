<h3>Requirements</h3>
SainSmart L293D Motor Drive:<br>
http://www.sainsmart.com/arduino/arduino-shields/motor-shields/sainsmart-l293d-motor-drive-shield-for-arduino-duemilanove-mega-uno-r3-avr-atmel.html<br>
Adafruit Motor Library:<br>
https://github.com/adafruit/Adafruit-Motor-Shield-library

<h3>Directions</h3>
motor<br>
1 = M2 = Rotate<br>
2 = M4 = Upper Arm<br>
3 = M3 = Lower Arm<br>
4 = M1 = Gripper<br>
direction<br>
1 = CW = close = up<br>
2 = CCW = open = down<br>
4 = stop<br>
time = time * 250<br>

<h4>How to</h4>
Use the arduino serial monitor to send a string of digits to the arduino via USB.
First digit is the motor.
Second digit is the direction.
Third digit is the time.


<h3>Sample Commands</h3>
416440 //Close<br>
426440 //Open<br>
310229229240340 //Retract<br>
320219219240340 //Extend<br>
129129119119140 //Rotate back and forth<br>

<h3>Demos</h3>
320219219240340414440424440129129119119140310229229240340<br>

110320219219240340142417440120310229229240340140217240424440 //sweep<br>

416440426440 //Open and close<br>

