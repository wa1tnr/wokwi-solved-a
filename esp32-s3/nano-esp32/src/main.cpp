/* Sun 28 Jun 18:17:48 UTC 2026 vscode */
/* blink D2 thru D7 nora - arduino nano esp32 */

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
  int pins[] = {2, 3, 4, 5, 6, 7};
  for (int pin : pins) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}

void blink_all() {
  int pins[] = {2, 3, 4, 5, 6, 7};
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
