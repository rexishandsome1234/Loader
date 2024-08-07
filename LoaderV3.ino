#include "Loader.h"
#include <Arduino.h>
#define buttonpin 3
Loader Loader(7, 3, 2);
void setup() {
  Serial.begin(9600);
  Loader.attach(7);
  pinMode(buttonpin, INPUT_PULLUP);
  digitalWrite(buttonpin, HIGH);
}

void loop() {
  Loader.write(60);
  Serial.print(" count: ");
  Serial.print(Loader.gettime());
  Serial.print(" buttonstate: ");
  Serial.print(Loader.getbuttonstate());
  Serial.print(" angle: ");
  Serial.println(Loader.getwrite());
}
