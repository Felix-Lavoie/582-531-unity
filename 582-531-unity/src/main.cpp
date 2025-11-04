#include <Arduino.h>
#include <FastLED.h>
#include <M5_PbHub.h>
#include <MicroOscSlip.h>
M5_PbHub myPbHub;
MicroOscSlip<128> monOsc(&Serial);
CRGB atomPixel;
#define BTN_LED 27
#include <VL53L0X.h>
VL53L0X  myTOF;

void setup() {
  FastLED.addLeds<WS2812,BTN_LED,GRB>( & atomPixel, 1);
  Wire.begin();
  myTOF.init();
  myPbHub.begin();
  Serial.begin(115200);

  atomPixel = CRGB(255,0,0); // ROUGE
  FastLED.show();
  delay(1000); // PAUSE 1 SECONDE
  atomPixel = CRGB(255,255,0); // JAUNE
  FastLED.show();
  delay(1000); // PAUSE 1 SECONDE
  atomPixel = CRGB(0,255,0); // VERT
  FastLED.show();
  delay(1000); // PAUSE 1 SECONDE
  atomPixel = CRGB(0,0,0);
  FastLED.show(); // PAUSE 1 SECOND
}

void loop() {
  // put your main code here, to run repeatedly:
  int maLectureAngle = myPbHub.analogRead( 0 );
  int mesure = myTOF.readRangeSingleMillimeters();
  monOsc.sendInt("/angle",maLectureAngle);
  monOsc.sendInt("/tuff",mesure);
  delay(100);
}
