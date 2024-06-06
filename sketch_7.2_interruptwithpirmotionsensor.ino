#define PIR_PIN 21 // Define the digital input pin for the PIR sensor

// Declare a volatile Boolean variable to track motion detection
volatile bool motionDetected = false;

// ISR to handle motion detection interrupt
void IRAM_ATTR motionDetectedInterrupt() {
  // ISR triggered by PIR_PIN RISING
  motionDetected = true;
}
//Attach the interrupt to the PIR sensor pin in the setup() function:

void setup() {
  pinMode(PIR_PIN, INPUT); // Set PIR_PIN as input
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), motionDetectedInterrupt, RISING);
  Serial.begin(115200); // Initialize serial communication
}
//Deal with the interrupt by checking the state of motionDetected and print a message to the serial monitor in the loop() function:

void loop() {
  if (motionDetected) {
    motionDetected = false; // Reset the flag
    Serial.println("Motion detected");
  }
  // Other code in loop
}

// description
//CC (Power): Connect this pin to a 5V power source on your microcontroller or a separate power supply if needed.
//GND (Ground): Connect this pin to the ground (GND) of your microcontroller or power supply.
//Signal Pin (Output): Connect this pin to the digital input pin defined in your code (PIR_PIN, which is pin 21 in your case).
// check code from pratcial slides