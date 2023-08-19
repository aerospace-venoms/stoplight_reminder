/*
 * main.cpp
 *
 * This file implements the LED strip task reminder.
 */

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

// Connect this STM32 pin to the WS2812b RGB chain's Data In line.
#define LED_PIN A1

// How many WS2812b are in the array?
#define LED_COUNT 5

// some defines for time management later
#define secs_per_hour 3600
#define hours_between_task 36
#define hours_to_critical 36

/*
 * Math for how long each 'tick' on the timer should be
 * Every tick, one LED changes colors, scrolling down the length of
 * the string. Green means task was just done, yellow means time to
 * do the task again, red means we are over time to do the task.
 *
 * Flashy police lights mean the cat police have been called and
 * are on their way.
 */

#define SECS_PER_TICK                                                          \
  (secs_per_hour * (hours_between_task + hours_to_critical) / ((LED_COUNT * 2) + 1))
#define TICK_MS SECS_PER_TICK * 1000

// Declare a light strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

/*
 * I copied this function from the Adafruit NeoPixel library examples.
 *
 * Fill strip pixels one after another with a color. Strip is NOT cleared
 * first; anything there will be covered pixel by pixel. Pass in color
 * (as a single 'packed' 32-bit value, which you can get by calling
 * strip.Color(red, green, blue) as shown in the loop() function above),
 * and a delay time (in milliseconds) between pixels.
 */
void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);              //  Set pixel's color (in RAM)
    strip.show();                               //  Update strip to match
    delay(wait);                                //  Pause for a moment
  }
}

/*
 * This function sets the entire strip to the given color and shows it
 * immediately.
 */
void set_strip_and_show(char red, char green, char blue) {
  for (int c = 0; c < strip.numPixels(); c++) {
    strip.setPixelColor(c, strip.Color(red, green, blue));
  }
  strip.show();
}

void loop() {
  // The device has reset, so begin the countdown

  // Set the color to green
  set_strip_and_show(0, 255, 0);
  delay(TICK_MS);

  // Begin the color wipe toward yellow
  colorWipe(strip.Color(255, 200, 0), TICK_MS);

  // Begin wipe toward red
  colorWipe(strip.Color(255, 0, 0), TICK_MS);
  delay(TICK_MS);

  // After a tick of red, begin the angry colors
  while (1) {
    set_strip_and_show(255, 0, 0);
    delay(200);
    set_strip_and_show(0, 0, 255);
    delay(200);
  }
}