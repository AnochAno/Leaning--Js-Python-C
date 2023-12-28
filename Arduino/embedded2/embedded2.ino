#include <Servo.h>

int lightSensorPin = A0;
int soundSensorPin = A1;
int buttonPin = 2;
int button2Pin = 3;  // Button to pause detection for 5 seconds
int button3Pin = 4;  // Button to revert servo to the original position
int servoPin = 9;
int ledPin = 7;
int pos = 0;
int prevPos = 0;  // Variable to store previous servo position

int lightintensity = 20;
int soundintensity = 50;

Servo myServo;

bool systemEnabled = true;
bool pauseDetection = false;

void setup() {
  myServo.attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
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

  // Check if pause button is pressed
  if (digitalRead(button2Pin) == LOW) {
    pauseDetection = true;
    delay(500);  // Debounce delay
  }

  // Check if revert button is pressed
  if (digitalRead(button3Pin) == LOW) {
    // Revert to the previous servo position
    pos = prevPos;
    myServo.write(pos);
    delay(500);  // Debounce delay
  }

  if (systemEnabled && !pauseDetection) {
    if (lightValue < lightintensity && soundValue > soundintensity) {
      // Store the current position before moving the servo
      prevPos = pos;
      
      pos = 180;
      myServo.write(pos);
      digitalWrite(ledPin, HIGH);
      delay(15000);
    }

    if (lightValue > lightintensity && soundValue > soundintensity) {
      // Store the current position before moving the servo
      prevPos = pos;
      
      pos = 0;
      myServo.write(pos);
      digitalWrite(ledPin, LOW);
      delay(3000);
    }
  }

  // Check if pause duration is over
  if (pauseDetection && millis() > 5000) {
    pauseDetection = false;
  }

  // Toggle system status if button is pressed
  if (digitalRead(buttonPin) == LOW) {
    systemEnabled = !systemEnabled;
    delay(500);  // Debounce delay
  }

  delay(500);
}
