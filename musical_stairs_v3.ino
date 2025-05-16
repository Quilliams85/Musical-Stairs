#include "MIDIUSB.h"  
#include <Control_Surface.h> // Include the Control Surface library
USBMIDI_Interface midi;


const MIDIAddress midiNote = {MIDI_Notes::C[4], Channel_1};
// Sensor configuration
const int NUM_SENSORS = 3;
const int TRIG_PINS[NUM_SENSORS] = {2, 3, 4};  // Trigger pins
const int ECHO_PINS[NUM_SENSORS] = {23, 25, 27};  // Echo pins

// Musical notes for each stair (C4, D4, E4, F4)
const byte MIDI_NOTES[NUM_SENSORS] = {60, 62, 64};

// Distance thresholds in centimeters (adjust according to your stairs)
const int THRESHOLDS[NUM_SENSORS] = {200, 200, 200};


int ledPin = 50;
int ledPin2 = 48;
int ledPin3 = 46;
int trigPin = 2;
int echoPin = 23;
int trigPin2 = 3;
int echoPin2 = 25;
int trigPin3 = 4;
int echoPin3 = 27;

NoteButton button1 {
  49,                             // Push button on pin 5
  {MIDI_Notes::C[4], Channel_1}, // Note C4 on MIDI channel 1
};

NoteButton button2 {
  47,                             // Push button on pin 5
  {MIDI_Notes::D[4], Channel_1}, // Note C4 on MIDI channel 1
};


NoteButton button3 {
  45,                             // Push button on pin 5
  {MIDI_Notes::E[4], Channel_1}, // Note C4 on MIDI channel 1
};

void setup() {
  Control_Surface.begin(); // Initialize Control Surface
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  Control_Surface.loop(); // Update the Control Surface
  int duration, distance;
  digitalWrite (trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin, LOW);
  duration = pulseIn (echoPin, HIGH);
  distance = (duration/2) / 29.1;

      Serial.print(distance);  
      Serial.print("cm");
      Serial.println();

  if (distance < 30) {  // Change the number for long or short distances.
    digitalWrite (ledPin, LOW);
  } else {
    digitalWrite (ledPin, HIGH);
  }

    int duration2, distance2;
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration = pulseIn (echoPin2, HIGH);
    distance2 = (duration/2) / 29.1;
   
      Serial.print(distance2);  
      Serial.print("cm");
      Serial.println();
   
    if (distance2 < 30) {  // Change the number for long or short distances.
      digitalWrite (ledPin2, LOW);
    }
 else {
      digitalWrite (ledPin2, HIGH);
    }

    int duration3, distance3;
    digitalWrite (trigPin3, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin3, LOW);
    duration = pulseIn (echoPin3, HIGH);
    distance3 = (duration/2) / 29.1;
   
      Serial.print(distance3);  
      Serial.print("cm");
      Serial.println();
   
    if (distance3 < 30) {  // Change the number for long or short distances.
      digitalWrite (ledPin3, LOW);
    }
 else {
      digitalWrite (ledPin3, HIGH);
    }

  }
// Code ends here.