#define DOOR_PIN 21

// Declare a volatile Boolean variable to track door opened event
volatile bool doorOpened = false;

// Declare variables for debouncing
volatile unsigned long timePreviousDoorOpening = 0;
unsigned long debounceDelay = 150;

void IRAM_ATTR doorOpenedInterrupt() {
  // ISR triggered by DOOR_PIN RISING
  unsigned long timeNow = millis();
  if (timeNow - timePreviousDoorOpening > debounceDelay) {
    timePreviousDoorOpening = timeNow;
    doorOpened = true;
  }
}

void setup() {
  pinMode(DOOR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(DOOR_PIN), doorOpenedInterrupt, RISING);
  Serial.begin(115200);
}

void loop() {
  if (doorOpened) {
    doorOpened = false; // Reset the flag
    Serial.println("Door opened");
  }
}

//We declare a volatile Boolean variable doorOpened to track whether a door opening event has occurred.
//We declare variables timePreviousDoorOpening and debounceDelay for debouncing. timePreviousDoorOpening stores the time of the previous door opening event, and debounceDelay defines the debounce time interval.
//In the doorOpenedInterrupt() ISR, we calculate the current time using millis() and compare it with timePreviousDoorOpening to check if the interrupt was triggered after the debounce delay. If so, we set doorOpened to true.
//In the setup() function, we set up the door pin as an input and attach the interrupt to it, triggering on a RISING signal.
//In the loop() function, we check if doorOpened is true. If it is, we print a message to the serial monitor indicating that the door has been opened and reset the flag
//
//description
//Connect the Door Sensor: The door sensor typically consists of two parts - a magnet and a reed switch. When the door opens, the magnet moves away from the reed switch, causing it to close. Connect one end of the reed switch to the ground (GND) pin on the Arduino.
//Connect the Other End of the Reed Switch (DOOR_PIN): Connect the other end of the reed switch (the one not connected to GND) to the digital pin on the Arduino you've defined as DOOR_PIN (pin 21 in this case).
//Ensure Proper Wiring: Ensure that the wiring between the door sensor and the Arduino is secure. You may need to use jumper wires to extend the connection if the sensor is far from the Arduino.
//Power Supply: Ensure that the Arduino is connected to a power supply (USB or external power source) to power the board and the door sensor
//
//check pratcial for image of thsi code












