#include <Arduino.h>

// =========================
// Pin mapping from your PCB
// =========================

// Driver 1
const int D1IN1 = 16;
const int D1IN2 = 17;
const int D1IN3 = 19;
const int D1IN4 = 21;
const int D1EEP = 22;

// Driver 2
const int D2IN1 = 32;
const int D2IN2 = 33;
const int D2IN3 = 25;
const int D2IN4 = 26;
const int D2EEP = 27;

// =========================
// Motor assumptions
// =========================
// Driver 1 Motor A = front left
// Driver 1 Motor B = rear left
// Driver 2 Motor A = front right
// Driver 2 Motor B = rear right
//
// If any wheel spins the wrong way, swap that motor's two wires
// or swap HIGH/LOW in that motor's forward/reverse functions.

// -------------------------
// Low-level motor helpers
// -------------------------
void setMotorRaw(int in1, int in2, int direction) {
  // direction:
  //  1 = forward
  // -1 = reverse
  //  0 = stop
  if (direction > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (direction < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}

void enableDrivers() {
  digitalWrite(D1EEP, HIGH);
  digitalWrite(D2EEP, HIGH);
}

void disableDrivers() {
  digitalWrite(D1EEP, LOW);
  digitalWrite(D2EEP, LOW);
}

void stopAllMotors() {
  setMotorRaw(D1IN1, D1IN2, 0);
  setMotorRaw(D1IN3, D1IN4, 0);
  setMotorRaw(D2IN1, D2IN2, 0);
  setMotorRaw(D2IN3, D2IN4, 0);
}

// -------------------------
// Robot movement helpers
// -------------------------
void forward() {
  // Left side
  setMotorRaw(D1IN1, D1IN2, 1);
  setMotorRaw(D1IN3, D1IN4, 1);

  // Right side
  setMotorRaw(D2IN1, D2IN2, 1);
  setMotorRaw(D2IN3, D2IN4, 1);
}

void reverse() {
  // Left side
  setMotorRaw(D1IN1, D1IN2, -1);
  setMotorRaw(D1IN3, D1IN4, -1);

  // Right side
  setMotorRaw(D2IN1, D2IN2, -1);
  setMotorRaw(D2IN3, D2IN4, -1);
}

void turnLeft() {
  // Left side reverse, right side forward
  setMotorRaw(D1IN1, D1IN2, -1);
  setMotorRaw(D1IN3, D1IN4, -1);

  setMotorRaw(D2IN1, D2IN2, 1);
  setMotorRaw(D2IN3, D2IN4, 1);
}

void turnRight() {
  // Left side forward, right side reverse
  setMotorRaw(D1IN1, D1IN2, 1);
  setMotorRaw(D1IN3, D1IN4, 1);

  setMotorRaw(D2IN1, D2IN2, -1);
  setMotorRaw(D2IN3, D2IN4, -1);
}

// -------------------------
// Individual motor test
// -------------------------
void testEachMotor() {
  Serial.println("Testing D1 Motor A");
  setMotorRaw(D1IN1, D1IN2, 1);
  delay(2000);
  setMotorRaw(D1IN1, D1IN2, 0);
  delay(1000);

  Serial.println("Testing D1 Motor B");
  setMotorRaw(D1IN3, D1IN4, 1);
  delay(2000);
  setMotorRaw(D1IN3, D1IN4, 0);
  delay(1000);

  Serial.println("Testing D2 Motor A");
  setMotorRaw(D2IN1, D2IN2, 1);
  delay(2000);
  setMotorRaw(D2IN1, D2IN2, 0);
  delay(1000);

  Serial.println("Testing D2 Motor B");
  setMotorRaw(D2IN3, D2IN4, 1);
  delay(2000);
  setMotorRaw(D2IN3, D2IN4, 0);
  delay(1000);
}

// -------------------------
// Setup
// -------------------------
void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(D1IN1, OUTPUT);
  pinMode(D1IN2, OUTPUT);
  pinMode(D1IN3, OUTPUT);
  pinMode(D1IN4, OUTPUT);
  pinMode(D1EEP, OUTPUT);

  pinMode(D2IN1, OUTPUT);
  pinMode(D2IN2, OUTPUT);
  pinMode(D2IN3, OUTPUT);
  pinMode(D2IN4, OUTPUT);
  pinMode(D2EEP, OUTPUT);

  stopAllMotors();
  enableDrivers();

  Serial.println("ESP32 robot firmware starting...");
  Serial.println("Drivers enabled.");
}

// -------------------------
// Main demo loop
// -------------------------
void loop() {
  testEachMotor();

  Serial.println("Forward");
  forward();
  delay(3000);
  stopAllMotors();
  delay(1000);

  Serial.println("Reverse");
  reverse();
  delay(3000);
  stopAllMotors();
  delay(1000);

  Serial.println("Turn Left");
  turnLeft();
  delay(2000);
  stopAllMotors();
  delay(1000);

  Serial.println("Turn Right");
  turnRight();
  delay(2000);
  stopAllMotors();
  delay(2000);
}
