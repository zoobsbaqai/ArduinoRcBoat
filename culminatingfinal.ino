//Zohair Baqai
// 09/01/2024
// this code is for the boat I made for the culminating assignment


#include <Servo.h>
#include <SoftwareSerial.h>


//motor control pins
const int motorENAPin = 5; // Enable pin for the L298N Motor Controller
const int motorIN1Pin = 7; // Input 1 for the DC motor
const int motorIN2Pin = 8; // Input 2 for the DC motor


//servo control pin
const int servoPin = 11;


// Bluetooth settings
const int bluetoothRxPin = 0; // RX pin of HC-05 module
const int bluetoothTxPin = 1; // TX pin of HC-05 module


int command;


Servo boatServo;
SoftwareSerial bluetoothSerial(bluetoothRxPin, bluetoothTxPin);


void setup() {
  // Set motor control pins as outputs
  pinMode(motorENAPin, OUTPUT);
  pinMode(motorIN1Pin, OUTPUT);
  pinMode(motorIN2Pin, OUTPUT);


  // Attach servo to its pin
  boatServo.attach(servoPin);


  // Start serial communication to hc-05
  Serial.begin(9600);
  bluetoothSerial.begin(9600);
}


void loop() {
  // Check if there's data available from Bluetooth
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();
    Serial.print(command);
    boatServo.write(90);


    // Perform action based on the received command
    switch (command) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
       case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
      case 'S':
        stopBoat();
        break;
      default:
        // Invalid command
        break;
    }
  }
}


void moveForward() {
  Serial.println("forwards");
  digitalWrite(motorIN1Pin, HIGH);
  digitalWrite(motorIN2Pin, LOW);
  analogWrite(motorENAPin, 125);
}


void moveBackward() {
  Serial.println("backward");
  digitalWrite(motorIN1Pin, LOW);
  digitalWrite(motorIN2Pin, HIGH);
  analogWrite(motorENAPin, 125);
}


void turnLeft() {
  Serial.println("left");
  boatServo.write(0);
  delay(1000);
  boatServo.write(90);
}


void turnRight() {
  Serial.println("right");
  boatServo.write(180);
  delay(1000);
  boatServo.write(90);
}


void stopBoat() {
  Serial.println("stop");
  digitalWrite(motorIN1Pin, LOW);
  digitalWrite(motorIN2Pin, LOW);
  analogWrite(motorENAPin, 0);
}