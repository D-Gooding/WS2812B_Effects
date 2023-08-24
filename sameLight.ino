#include <FastLED.h>

#define LED_PIN     2
#define NUM_LEDS    300
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

void setup() {
  

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i < NUM_LEDS; i++){
        leds[i].setRGB( 255, 68, 221);
  }

}
