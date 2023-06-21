#include <Adafruit_NeoPixel.h>

#define GSR_PIN A0
#define LED_PIN 6
#define LED_COUNT 60
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to off
  pinMode(GSR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
//add for serial monitor
Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read the GSR sensor value
  int gsrValue = analogRead(GSR_PIN);
  //serial monitor
  Serial.print(gsrValue);
  Serial.print(",");

  // Map the GSR value to the lower range of NeoPixel brightness (0-100)
  long brightness = map(gsrValue,300,500, 0, 150);
  //long brightness = map(gsrValue,400, 500, 0, 70);

  if (gsrValue < 320) {
    brightness = 10;
  }
  if (gsrValue >320 && gsrValue < 340) {
   brightness = 30;
  }
  if (gsrValue >340 && gsrValue < 360) {
   brightness = 60;
  }
    if (gsrValue >360 && gsrValue < 380) {
   brightness = 80;
  }
    if (gsrValue >380 && gsrValue < 450) {
   brightness = 100;
  }
     if (gsrValue >450) {
   brightness = 150;
  }



  //brightness = 50;

  // Set the brightness of all NeoPixels
  strip.setBrightness(brightness);
  strip.fill(strip.Color(255,222,173));//warm white
  //strip.fill(strip.Color(255,0,0));
  //strip.fill(strip.Color(brightness, 0, 255-brightness)); // colour red blue
  //strip.fill(strip.Color(brightness, brightness , brightness)); // white

  strip.show(); // Update the NeoPixel strip

  //delay(100); // Adjust the delay as needed
}

