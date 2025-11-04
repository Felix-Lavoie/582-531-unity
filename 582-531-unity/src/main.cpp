#include <Arduino.h>
#include <FastLED.h>
#include <M5_PbHub.h>
M5_PbHub myPbHub;
//CRGB monPixel;
CRGB atomPixel;
#define BTN_LED 27

void setup() {
  FastLED.addLeds<WS2812,BTN_LED,GRB>( & atomPixel, 1);

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
  delay(100);
}
