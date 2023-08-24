//this is a program I wrote far a light box istallation in my gloomy ass bedroom
//




#include "FastLED.h"           	// This sketch uses the FastLED library

#define DATA_PIN 3    		   	// Data connected to Digital Pin 6 on the Arduino

#define LED_TYPE WS2811      	//this is an array of 40 in an 8X5 pattern
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];

void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(2000);
    LEDS.addLeds<LED_TYPE, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
   // Move a single white led in its own row
   for(int Row1 = 0; Row1 < 8; Row1 = Row1 + 1) for(int row2 = 8; row2 <16; row2 = row2 +1) {
       leds[Row1] = CRGB::White; leds[row2] = CRGB :: White;}
     delay(1000);
      FastLED.show();
//same as above but now it trns them off 
   for(int Row1 = 0; Row1 < 8; Row1 = Row1 + 1) for(int row2 = 8; row2 <16; row2 = row2 +1)
    {leds[Row1] = CRGB ::Black; leds[row2] = CRGB ::Black;}
    delay(1000);
      FastLED.show();

}
