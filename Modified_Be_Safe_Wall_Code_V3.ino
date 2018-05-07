#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <cpp_compat.h>
#include <dmx.h>
#include <FastLED.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.h>
#include <noise.h>
#include <pixelset.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>

#define DATA_PIN 6  //this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LEDS 50 //change this for the number of LEDs in the strip
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS];
//I have a few additional integers in here from different tests.
int y = 1;
int z = 0;
int w = 5;
int i = 20;
int a = 0;
int t = 0;

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); //setting up the FastLED
  randomSeed(analogRead(0)); //seeding my random numbers to make it more random.  If you just use the random function it will repeat the same pattern every time it is loaded.



}



void loop() {
  // put your main code here, to run repeatedly:


  wallTypeThis("Donuts Rule");
  dotFill();

  wallTypeThis("No Hand Clamping");
  BeClear();

  wallTypeThis("BeAM");
  BeClear();

  wallTypeThis("MakNet");
  dotFill();

  redBubbleSort();
  BeClear();

  wallTypeThis("Be Safe");
  dotFill();




}

void wallTypeThis(String s) {

  FastLED.clear();

  int sizeOfString = 0;
  sizeOfString = s.length();
  char typeThis[sizeOfString];
  int letterNumber = 0;

  s.toCharArray(typeThis, sizeOfString + 1);



  for (int i = 0; i < sizeOfString; i++) {

    letterNumber = findLetterNumber(typeThis[i]);
    if (letterNumber < 0) {
      FastLED.clear();
      FastLED.show();
      delay(1000);
    } else {
      leds[letterNumber] = CRGB(random(1, 255), random(1, 255), random(1, 255));
      FastLED.show();
      delay(2000);
      FastLED.clear();
      FastLED.show();
      delay(500);
    }
  }

  delay(500);

}

int findLetterNumber(char c) {

  // I plan on adding a HashMap for this later. It will clean up the code and should be faster

  if (c == 'A' || c == 'a') {
    return 49;
  } else if (c == 'B' || c == 'b') {
    return 47;
  } else if (c == 'C' || c == 'c') {
    return 45;
  } else if (c == 'D' || c == 'd') {
    return 43;
  } else if (c == 'E' || c == 'e') {
    return 41;
  } else if (c == 'F' || c == 'f') {
    return 39;
  } else if (c == 'G' || c == 'g') {
    return 37;
  } else if (c == 'H' || c == 'h') {
    return 35;
  } else if (c == 'I' || c == 'i') {
    return 33;
  } else if (c == 'J' || c == 'j') {
    return 31;
  } else if (c == 'K' || c == 'k') {
    return 29;
  } else if (c == 'L' || c == 'l') {
    return 27;
  } else if (c == 'M' || c == 'm') {
    return 25;
  } else if (c == 'N' || c == 'n') {
    return 23;
  } else if (c == 'O' || c == 'o') {
    return 21;
  } else if (c == 'P' || c == 'p') {
    return 19;
  } else if (c == 'Q' || c == 'q') {
    return 17;
  } else if (c == 'R' || c == 'r') {
    return 15;
  } else if (c == 'S' || c == 's') {
    return 13;
  } else if (c == 'T' || c == 't') {
    return 11;
  } else if (c == 'U' || c == 'u') {
    return 9;
  } else if (c == 'V' || c == 'v') {
    return 7;
  } else if (c == 'W' || c == 'w') {
    return 5;
  } else if (c == 'X' || c == 'x') {
    return 3;
  } else if (c == 'Y' || c == 'y') {
    return 1;
  } else if (c == 'Z' || c == 'z') {
    return 0;
  } else {
    return -1;
  }

}

void turnOnAll() {
  delay(300);
  fill_solid(leds, 50, CRGB::Red);
  FastLED.show();
  delay(300);
}

void redBubbleSort() {

  int redValues[50];
  int greenValues[50];
  int r, g;

  for (int i = 0; i < 50; i++) {
    r = random(1, 255);
    g = random(1, 50);
    leds[i] = CRGB(r, g, 0);
    FastLED.show();
    delay(50);
    greenValues[49 - i] = g;
    redValues[49 - i] = r;

  }

  //Sort Red

  for (int j = 49; j > 0; j--) {
    for (int p = 49; p > 0; p--) {
      if (redValues[p] > redValues[p - 1]) {


        int original, next, swap;
        original = redValues[p];
        next = redValues[p - 1];
        swap = next;
        redValues[p] = swap;
        redValues[p - 1] = original;

        leds[p] = CRGB(redValues[p], greenValues[p], 0);
        leds[p - 1] = CRGB(redValues[p - 1], greenValues[p - 1], 0);

        FastLED.show();

        delay(50);

      }
    }
  }

  // Sort Green

  for (int j = 49; j > 0; j--) {
    for (int p = 49; p > 0; p--) {
      if (greenValues[p] < greenValues[p - 1]) {



        int gOriginal, gNext, gSwap;

        gOriginal = greenValues[p];
        gNext = greenValues[p - 1];
        gSwap = gNext;
        greenValues[p] = gSwap;
        greenValues[p - 1] = gOriginal;

        leds[p] = CRGB(redValues[p], greenValues[p], 0);
        leds[p - 1] = CRGB(redValues[p - 1], greenValues[p - 1], 0);

        FastLED.show();

        delay(50);

      }
    }
  }

  delay(5000);

}



void dotFill() {
  FastLED.clear();

  int randomLight, r, g, b;

  int lights[50];
  for (int i = 0; i < 50; i++) {
    lights[i] = 0;
  }


  for (int i = 0; i < 50; i = i + 0) {
    randomLight = random(0, 50);

    if (lights[randomLight] == 0) {
      r = random(1, 255);
      g = random(50, 100);
      b = random(0, 50);
      leds[randomLight] = CRGB(255, g, b);
      delay(500);
      FastLED.show();
      i++;
      lights[randomLight] = 1;
      if (i > 50) {
        break;
      }

    }

  }

  delay(1500);

  FastLED.clear();
}





void BeClear() {

  FastLED.clear();

  int r, g, b;


  for (int i = 49; i >= 0; i--) {
    r = random(1, 255);
    g = random(1, 255);
    b = random(1, 255);
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(50);
    FastLED.clear();
  }

  leds[0] = CRGB(0, 0, 0);

  FastLED.clear();

  for (int j = 0; j < 50; j++) {
    r = random(1, 255);
    g = random(1, 255);
    b = random(1, 255);
    leds[j] = CRGB(r, g, b);
    FastLED.show();
    delay(50);
  }


  delay(1000);

  //  for (int j = 0; j < 50; j++) {
  //    leds[j] = CRGB(0, 0, 0);
  //    FastLED.show();
  //  }
  //  delay(100);

  FastLED.clear();

  delay(1500);


}





