# Ultrasonic Sensor with 6 Servos and Bluetooth


Circuit design that contains an ultrasonic sensor, 6 servos, and Bluetooth for the reception robot. When it senses a person in front of the robot at a distance of 100 cm, the robot will move its hands by 90 degrees and send a Bluetooth notification to start playing videos.


This project has done using Tinkercad


Tinkercad link: https://www.tinkercad.com/things/iCszEyfa4KJ

## Circuit Description

*please note: in this design, a micro servo is used. but for the project, a different servo will be used. also, another controller was used instead of the Bluetooth for the reason of availability in Tinkercad.*

| Element   | description |
|-------|------------|
|  Ultrasonic  |  when an object get less than 100cm close for 3 seconds servos will move and notification will be sent |
|  Arduino  |  represents who will receive 6 bytes of data every half second after an object get less than 100cm close to ultrasonic for 3 seconds   |
| R servos |   represent the right arm of the robot  |
| L servos |   represent the left arm of the robot  |



## Circuit Design


when the power is off:


![off](https://github.com/AlolyanRoaa/UltrasonicSensor-And6ServosBluetooth/blob/main/images/off.PNG)



when an object get less than 100cm close for 3 seconds:



![inPosWithCloseObjectPass3sec](https://github.com/AlolyanRoaa/UltrasonicSensor-And6ServosBluetooth/blob/main/images/inPosWithCloseObjectPass3sec.PNG)



receiver print the received bytes on serial monitor window:



![receiverPrintbytes](https://github.com/AlolyanRoaa/UltrasonicSensor-And6ServosBluetooth/blob/main/images/receiverPrintbytes.PNG)



## Assembly


After connecting the arduino's (Arduino Uno R3) ground to breadboard (-), and 5v to breadboard (+).


then for each servo : brow wire to ground, red to power, and orange for signal to the arduino.


| Servo  | Digital pwm |
|-------|------------|
| R1  |   D9  |
| R2  |   D10  |
| R3 |   D11   |
| L1  |   D6   |
| L2  |   D5  |
| L3  |   D3   |


connect the ultrasonic ground to breadboard (-), and power to breadboard (+), and signal to the arduino digital pwm #7.


for arduino #2 connect analog A5 to arduino #1 to analog A5, and arduino #2 analog A4 to arduino #1 to analog A4, and connect them to common ground. 


these two Arduino programmed to communicate with one another in a Master Writer/Slave Receiver configuration via the I2C synchronous serial protocol.



