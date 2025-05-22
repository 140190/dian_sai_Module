#include <Arduino.h>
#include "measureDistance.hpp"




void setup() {
  Serial.begin(9600);
  Distance_init();

}

void loop() {
  float distance = measureDistance();
  // 打印距离
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}


