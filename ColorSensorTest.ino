#include <ColorSensor.h>

ColorSensor sensorLeft(23, 25, 27, A0);
ColorSensor sensorRight(29, 31, 33, A1);

void setup() {
  Serial.begin(9600);
  sensorLeft.setBlackMin(50, 50, 50);
  sensorRight.setGreenMax(50, 200, 30);
}

void loop() {
  Serial.print(sensorLeft.getColor());
  Serial.println(sensorRight.getColor());
  sensorLeft.printValues();
  sensorRight.printValues();
}
