#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    300
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 500

uint8_t brightness = 255;


CRGBPalette16 currentPalette;
TBlendType    currentBlending;


extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;
void setup() {
  delay( 3000 );       
  currentBlending = LINEARBLEND;
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

}

void loop() {
  // put your main code here, to run repeatedly:
     SetupSnowPalette();

 
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromSnowPaletteColors( startIndex);


    SetupBlanketOfSnow();
    
    SnowBlanket();


    static uint8_t Bright = 0;
    Bright = Bright + 1;
    SetupCloud();
    SnowCloud(Bright);

    

    
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  
}
void FillLEDsFromSnowPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 6; i < 53; ++i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 9;
    }
    

    for( int i = 150; i > 110; --i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 9;
    }
    
}



void SnowBlanket()
{
  uint8_t brightness = 60;
  for( int i = 187; i < 258; ++i) {
      leds[i] = ColorFromPalette( currentPalette, 1, brightness, currentBlending);
       
    }
    addSnow(40,258,300);
    addSnow(40,150,187);
    for( int i = 0; i < 14; ++i) {
      leds[i] = ColorFromPalette( currentPalette, 1, brightness, currentBlending);
      
    }
    

}
void addSnow( fract8 chanceOfGlitter, int start, int ends) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(ends - start)+start ] += CRGB::White;
  }
  if( random8() < chanceOfGlitter) {
    leds[ random16(ends - start)+start ] = CRGB::Black;
  }
  
}

void SnowCloud(uint8_t B)
{
  //uint8_t brightness = 20;
  for( int i = 53; i < 110; ++i) {
      leds[i] = ColorFromPalette( currentPalette, 1, brightness, currentBlending);
  
       
    }
    
 
    

}




void SetupSnowPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[5] = CRGB::White;
    currentPalette[10] = CRGB::White;
    
}

void SetupBlanketOfSnow()
{
  fill_solid( currentPalette, 16, CRGB::White);

}
void SetupCloud()
{
  fill_solid( currentPalette, 16, CRGB::Blue);

}
