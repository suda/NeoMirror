#include <Adafruit_NeoPixel.h>

#define PIN            3
#define NUMPIXELS      30
#define BUTTON         1
#define STEPS          6

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_BRG);
int currentBrightness = 0;
int brightnessSteps[STEPS] = { 0, 16, 32, 64, 128, 255};

void setBrightness(int brightness) {
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(brightnessSteps[brightness], brightnessSteps[brightness], brightnessSteps[brightness]));
    pixels.show();
  }
}

void setup() {
  pixels.begin();
  setBrightness(currentBrightness);
  
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, LOW);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    currentBrightness++;
    if (currentBrightness > STEPS - 1) currentBrightness = 0;
    setBrightness(currentBrightness);
    delay(500);
  }
}
