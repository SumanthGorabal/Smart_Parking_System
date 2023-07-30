#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200 // Maximum distance to measure in centimeters
// Connection to the LED
#define LED_PIN 8

// Minimum distance for parking detection (in cm)
#define PARKING_THRESHOLD 50

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned int distance = sonar.ping_cm();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < PARKING_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // Space is occupied
  } 
  else {
    digitalWrite(LED_PIN, LOW); // Space is available
  }

  delay(500);
}
