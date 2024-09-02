# ArduinoRcBoat
This is my program that i wrote with arduino to control a bluetooth via phone toy boat.

This project is an Arduino-based boat control system that allows you to remotely control a DC motor and a servo motor using an HC-05 Bluetooth module. The boat can be controlled to move forward, backward, left, and right using commands sent via Bluetooth. The system uses an L298N motor controller to drive the DC motor and an Arduino board to process the commands.

Components Used:
Arduino Uno
L298N Motor Controller
DC Motor
Servo Motor
HC-05 Bluetooth Module
12V Battery
Features:
Remote control via Bluetooth
Forward and backward motion
Left and right turning using a servo motor
Stop functionality
Wiring:
The Arduino controls the motor and servo based on commands received from the HC-05 module.
The L298N motor controller drives the DC motor, with power supplied by a 12V battery.
Setup:
Connect the components as described in the wiring diagram.
Upload the provided code to the Arduino.
Pair your Bluetooth device with the HC-05 module.
Use a Bluetooth terminal app to send commands (F for forward, B for backward, L for left, R for right, S for stop) to the boat.
