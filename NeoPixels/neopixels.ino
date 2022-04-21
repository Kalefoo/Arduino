/*************************************************************************
Things we need:
- Arduino
- NeoPixel strip (Consult configuration in the library page)
Depending on the model the configuration 
may vary, please check the configuration of 
your model on the library creator's web site
https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
*************************************************************************/

//Import the library
#include <Adafruit_NeoPixel.h>

//Read the headline
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(20, 3, NEO_RGB + NEO_KHZ400);

//Variable to be used for the random color change
int neonow = 0;

void setup(){
//We start the module
  pixel.begin();
  pixel.show();
  
  //Simple loading animation (not required)
  pixel.setBrightness(20);
  for(int i = 0; i < 20; i++){
    pixel.setPixelColor(i, 0, 0, 255);
    pixel.show();
    delay(50);
  }
  pixel.setBrightness(0);
  delay(500); 
}

void loop(){
//Random color variables
int r = random(0, 256);
int g = random(0, 256);
int b = random(0, 256);

pixel.setBrightness(20); //We set the brightness of the LEDs
pixel.setPixelColor(neonow, g, r, b); //Set color
pixel.show(); //We show the color on the LED
delay(500); //We wait 500ms before repeating the process on another LED
neonow++; //We move on to the next LED

//If LED 20 is on, it returns to LED 0
if(neonow == 20){
  neonow = 0;
 }
}

/***********************************
I hope you like it, it is a 
basic but useful code to
make a RGB strip of different colors
My website: https://kalefoo.org
***********************************/
