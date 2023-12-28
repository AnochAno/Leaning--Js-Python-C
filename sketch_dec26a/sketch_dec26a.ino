#include <Servo.h>

int lightSensorPin = A0;
int soundSensorPin = A1;
int buttonPin = 2;
int servoPin = 9;
int ledPin = 7;
int pos = 0;

int lightintensity = 20;
int soundintensity = 50;

Servo myServo;

bool systemEnabled = true;

void setup() {
  myServo.attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(lightSensorPin);
  int soundValue = analogRead(soundSensorPin);

  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print(" | Sound: ");
  Serial.println(soundValue);

  if (systemEnabled) {
    if (lightValue < lightintensity && soundValue > soundintensity) {
      pos = 180;
      myServo.write(pos);
      digitalWrite(ledPin, HIGH);
      delay(1500);
    }
      if (lightValue > lightintensity && soundValue > soundintensity) {
        pos = 0;
        myServo.write(pos);
        digitalWrite(ledPin, LOW);
        delay(3000);
      }
  }
  

  if (digitalRead(buttonPin) == LOW) {
    systemEnabled = !systemEnabled;
    delay(500);
  }

  delay(500);
}
