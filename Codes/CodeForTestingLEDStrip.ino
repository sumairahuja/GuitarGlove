/*
 * This tutorial is part of the course CPLN 571 - Sensing the City, at the University of Pennsylvania, taught by Dr. Allison Lassiter. It is also a part
 * of the final project of the class. It is based on the NeoPixel Library by AdaFruit.
 * 
 * In order to run this tutorial, you will need to install the AdaFruit NeoPixel library.
 */
 
#include <Adafruit_NeoPixel.h> // include the Neopixel Library in this Sketch
 
#define PIN D1 // This is the Arduino Pin controlling the LEDstrip.
 
#define NUMPIXELS 6 // Here, you are informing how many LEDs you have on your strip.
                     // You can also control only a part of the existing LEDs, if you wish.
                     // This strip has 60 LEDs, so I am informing this number.
 
/* 
 *  Remember that I keep annoying you whith capital IMPORTANT warnings? This next line is where it really matters.
 */
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800); // Here, you are specifying your strip,
                                                                                     // Let's go over the details:
 
/*
 * The command Adafruit_NeoPixel pixels assigns (inside the parenthesis, separated by commas (,)):
 * 1) the number of pixels you control, We have created the variable NUMPIXELS, so we can change this number more easily according to our need
 * 2) the PIN on the Arduino Board that sends the signal. In this case, we use PIN 06, as declared globally above
 * 3) The Type of LED flag. In this case, we have a RGB White LED, with 800Khz bitstream. You can check this out on the datasheet we linked above.
 * 
 * Please notice that your LEDs won't work if you do not get this line right. So, here are some tips for more recent fixtures:
 * 
 * NEO_KHZ800 will be common in most NeoPixel products with WS2812 LEDs. If you check the datasheet, of your strip, it should be under
 * data speed, or something similar.
 * NEO_KHZ400 will be preent in WS2811 LEDs. Again, check the datasheet to be sure.
 * 
 * NEO_GRB will be common in NeoPixel products
 * NEO_RGB will be common in Flora Pixel products.
 * 
 * REMEMBER, if yor LED is a RGB White, you have to add a W at the end of this code, so they will be either NEO_RGBW or NEO_GRBW 
 */
 
/*
 * OK, now let's start controlling the leds. The strip I am using has 60 LEDs. I want to control it in 6 groups of 10 LEDs, to make my life easier.
 * So, let's define the following arrays:
 */
 
int PXL1[] = {0,1,2,3,4,5};
 // array controlling the first 10 LEDs. Please notice the "LED 0" is the first one, not "LED 1"
/*int PXL2[] = {10,11,12,13,14,15,16,17,18,19};
int PXL3[] = {20,21,22,23,24,25,26,27,28,29};
int PXL4[] = {30,31,32,33,34,35,36,37,38,39};
int PXL5[] = {40,41,42,43,44,45,46,47,48,49};
int PXL6[] = {50,51,52,53,54,55,56,57,58,59};*/
 
int delayval = 50; // Here we set a delaytime
 
void setup() {
  pinMode(4, OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.
}
 
void loop() {

  /*pixels.setPixelColor(PXL1[0], pixels.Color(0,255,0)); 
  pixels.show();
  delay(1000);
  pixels.setPixelColor(PXL1[1], pixels.Color(0,255,0));
  pixels.show();
  delay(1000);
  pixels.setPixelColor(PXL1[2], pixels.Color(0,255,0));
  pixels.show();
  delay(1000);*/
  //pixels.setPixelColor(PXL1[2], pixels.Color(0,0,255));//changed middle value from 255 to 0
  //pixels.show();
  //delay(1000);
  //pixels.setPixelColor(PXL1[3], pixels.Color(255,0,0));
  //pixels.show();
  //delay(1000);
  /*pixels.setPixelColor(PXL1[4], pixels.Color(0,255,0)); 
  pixels.show();
  delay(1000);*/
  pixels.setPixelColor(PXL1[0], pixels.Color(0,0,255));
  pixels.show();
 
}