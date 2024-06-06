#define LED_PIN 13 // Define LED pin
int delayTime = 2000; // Default delay time
unsigned long previousTimeToggled = 0; // Initialise previous time toggled
unsigned long timeNow; // Initialize current time

void setup() {
  // Setting up serial communication
  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  // Setting up LED pin as output
  pinMode(LED_PIN, OUTPUT);

  // Prompting the user to enter delay time
  Serial.println("Enter delay time in milliseconds:");
}

void loop() {
  if (Serial.available() > 0) {
    int newDelayTime = Serial.parseInt();
    if (newDelayTime >= 100 && newDelayTime <= 4000) {
      delayTime = newDelayTime;
      Serial.print("Delay time has been set to: ");
      Serial.println(delayTime);
    } else {
      Serial.println("Invalid delay time! Please enter a value between 100 and 4000 milliseconds.");
    }
  }

  // Get current time
  timeNow = millis();

  // Check if it's time to toggle LED
  if (timeNow - previousTimeToggled >= delayTime) {
    // Toggle LED
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    // Update previous time toggled
    previousTimeToggled = timeNow;
  }
}