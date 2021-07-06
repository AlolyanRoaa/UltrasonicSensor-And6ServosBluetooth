#include <Servo.h>
#include <Wire.h>

const int UlpingPin = 7;
int period=3000;//after 3sec
unsigned long lastLongMeasureTime; //some global variables
Servo R1, R2, R3, L1, L2,L3;

void setup() {
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
  R1.attach(9);
  R2.attach(10);
  R3.attach(11);
  L1.attach(6);
  L2.attach(5);
  L3.attach(3);
}

byte x = 0;

void loop() {
  long duration, cm;
  
  pinMode(UlpingPin, OUTPUT);
  digitalWrite(UlpingPin, LOW);
  delayMicroseconds(1);
  digitalWrite(UlpingPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(UlpingPin, LOW);

  pinMode(UlpingPin, INPUT);
  duration = pulseIn(UlpingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(0);
  
  
  if (cm > 100) {
  lastLongMeasureTime = millis(); // reset the clock if the distance is too great
}

if (millis() - lastLongMeasureTime >= period) {
      R1.write(90);
      R2.write(90);
      R3.write(90);
      L1.write(90);
      L2.write(90);
      L3.write(90);
      delay(0);
  
  Wire.beginTransmission(4); // transmit to device no A4
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte  
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(500);
    
}
  //back to 0 when object is away than 100cm
   else {
      R1.write(0);
      R2.write(0);
      R3.write(0);
      L1.write(0);
      L2.write(0);
      L3.write(0);
      delay(2000);
    }

}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
