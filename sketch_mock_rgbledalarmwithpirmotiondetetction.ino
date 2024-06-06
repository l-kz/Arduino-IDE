#define PIR_PIN 2 // Digital pin connected to the PIR motion sensor
#define LED_PIN_RED 3 // Digital pin connected to the red LED of the RGB LED
#define LED_PIN_GREEN 4 // Digital pin connected to the green LED of the RGB LED
#define LED_PIN_BLUE 5 // Digital pin connected to the blue LED of the RGB LED
#define BUZZER_PIN 6 // Digital pin connected to the buzzer

bool motionDetected = false;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
  pinMode(LED_PIN_BLUE, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    if (!motionDetected) {
      // Motion detected, trigger alarm and change LED color
      motionDetected = true;
      triggerAlarm();
      changeLEDColor(255, 0, 0); // Red color for armed
    }
  } else {
    if (motionDetected) {
      // Motion no longer detected, reset state
      motionDetected = false;
      stopAlarm();
      changeLEDColor(0, 255, 0); // Green color for disarmed
    }
  }
}

void triggerAlarm() {
  Serial.println("Motion detected! Alarm triggered!");
  // Turn on the buzzer
  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000); // Alarm duration
}

void stopAlarm() {
  // Turn off the buzzer
  digitalWrite(BUZZER_PIN, LOW);
}

void changeLEDColor(int red, int green, int blue) {
  analogWrite(LED_PIN_RED, red);
  analogWrite(LED_PIN_GREEN, green);
  analogWrite(LED_PIN_BLUE, blue);
}

//VCC: Connect to 5V on the Arduino.
//OUT: Connect to digital pin (e.g., Pin 2) on the Arduino.
//GND: Connect to GND on the Arduino.
//RGB LED:
//Anode (Long Leg):
//Connect to a current-limiting resistor (220-470 ohms).
//Connect the other end of the resistor to a digital pin (e.g., Pin 3) on the Arduino.
//Cathodes (Short Legs):
//Connect the red cathode to a digital pin (e.g., Pin 4) on the Arduino.
//Connect the green cathode to a digital pin (e.g., Pin 5) on the Arduino.
//Connect the blue cathode to a digital pin (e.g., Pin 6) on the Arduino.
//Connect all cathodes to a common GND rail on the breadboard.
//Buzzer:
//Positive (+): Connect to a digital pin (e.g., Pin 7) on the Arduino.
//Negative (-): Connect to GND on the Arduino.
//Power:
//Connect the 5V and GND pins on the Arduino to the power and ground rails on the breadboard, respectively.