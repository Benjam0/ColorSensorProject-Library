#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H
#include <Arduino.h>

const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

class ColorSensor {
private:
  byte r_pin, g_pin, b_pin, pht;
  int R_raw, G_raw, B_raw;
  int reflectedOffR, reflectedOnR, reflectedOffG, reflectedOnG, reflectedOffB, reflectedOnB;
  int blackMin[3] = { 5, 10, 10 };
  int blackMax[3] = { 110, 80, 80 };
  int blueMin[3] = { 20, 70, 110 };
  int blueMax[3] = { 200, 250, 420 };
  int greenMin[3] = { 15, 80, 30 };
  int greenMax[3] = { 100, 470, 180 };
  int redMin[3] = { 60, 15, 10 };
  int redMax[3] = { 500, 150, 120 };
  int yellowMin[3] = { 150, 140, 30 };
  int yellowMax[3] = { 545, 350, 160 };
  int whiteMin[3] = { 140, 180, 100 };
  int whiteMax[3] = { 740, 740, 740 };
  int minusR, minusG, minusB;
  byte color;
  unsigned long inicial, final;

public:
  ColorSensor(byte r, byte g, byte b, byte p)
    : r_pin(r), g_pin(g), b_pin(b), pht(p) {
    pinMode(r_pin, OUTPUT);
    pinMode(g_pin, OUTPUT);
    pinMode(b_pin, OUTPUT);
    pinMode(pht, INPUT);
  }

  byte getColor();
  void printValues();
  bool darkness(int cutoffValue);

  void setBlackMin(int r, int g, int b);
  void setBlackMax(int r, int g, int b);
  void setBlueMin(int r, int g, int b);
  void setBlueMax(int r, int g, int b);
  void setGreenMin(int r, int g, int b);
  void setGreenMax(int r, int g, int b);
  void setRedMin(int r, int g, int b);
  void setRedMax(int r, int g, int b);
  void setYellowMin(int r, int g, int b);
  void setYellowMax(int r, int g, int b);
  void setWhiteMin(int r, int g, int b);
  void ColorSensor::setWhiteMax(int r, int g, int b);

};

byte getColor();

void printValues();

bool darkness(int cutoffValue);

#endif