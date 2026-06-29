/* Mon 29 Jun 21:24:05 UTC 2026 vscode */
/* blink them all esp32s3 native wokwi */

#include <Arduino.h>

bool state = LOW;
int rate = 700;  // ms

void half_blink(uint8_t pin) {
  digitalWrite(pin, state);
  delay(rate);
  state = !state;
}

void blink(uint8_t pin) {
  half_blink(pin);
  half_blink(pin);
}

void setup_gpio() {
  int pins[] = {4,  5,  6,  7,  15, 16, 17, 18, 8,
                3,  46, 9,  10, 11, 12, 13, 14, 19,
                20, 21, 47, 48, 45, 0,  35, 36, 37,
                38, 39, 40, 41, 42, 2,  1};
  for (int pin : pins) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}

void blink_all() {
  int pins[] = {4,  5,  6,  7,  15, 16, 17, 18, 8,
                3,  46, 9,  10, 11, 12, 13, 14, 19,
                20, 21, 47, 48, 45, 0,  35, 36, 37,
                38, 39, 40, 41, 42, 2,  1};
  for (int pin : pins) {
    blink(pin);
    delay(500);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S3!");
  setup_gpio();
}

void loop() {
  blink_all();
  delay(10);  // this speeds up the simulation
}

/* end */