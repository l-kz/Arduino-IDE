// Define pins
#define LED_PIN 13  // Replace with the actual pin number connected to the LED

// Function to hash password
unsigned long hashPassword(String password) {
  unsigned long hashed = 0;
  for (int i = 0; i < password.length(); i++) {
    hashed += password.charAt(i);
  }
  return hashed;
}

// Function to set LED brightness
void setLedBrightness(int pin, int brightness) {
  // Ensure brightness is within valid range [0, 255]
  brightness = max(0, min(brightness, 255));
  // Set the LED brightness using PWM
  analogWrite(pin, brightness);  // Adjust PWM duty cycle
  Serial.print("Setting LED brightness to ");
  Serial.println(brightness);
}

// Function to blink LED
void blinkLed(int pin) {
  // Implement LED blinking logic here
  // Example: blink LED by turning it on and off in a loop
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}

// Main function
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  String correctPassword = "correct_password";
  String incorrectPassword = "incorrect_password";

  Serial.println("Enter password:");
  while (Serial.available() == 0); // Wait for input

  String password = Serial.readStringUntil('\n');
  unsigned long hashedPassword = hashPassword(password);

  if (hashedPassword == hashPassword(correctPassword)) {
    setLedBrightness(LED_PIN, 255);  // Turn LED ON with 100% duty cycle
  } else if (hashedPassword == hashPassword(incorrectPassword)) {
    setLedBrightness(LED_PIN, 127);  // Turn LED ON with 50% duty cycle
    blinkLed(LED_PIN);  // Blink LED
  } else {
    setLedBrightness(LED_PIN, 0);  // Turn LED OFF
  }
}

// Connect the Anode (+) of the LED: Take the longer leg of the LED, which is the Anode (+), and connect it to one end of a current-limiting resistor. The purpose of the resistor is to limit the amount of current flowing through the LED, protecting it from damage. Choose a resistor value between 220-330 ohms.
// Connect the other end of the resistor to a Digital Pin on the Arduino: Choose a digital pin on the Arduino board, such as pin 13, to control the LED. Connect the free end of the resistor (opposite to the one connected to the LED) to the selected digital pin on the Arduino.
// Connect the Cathode (-) of the LED: Take the shorter leg of the LED, which is the Cathode (-), and connect it directly to the Ground (GND) pin on the Arduino. This completes the circuit, allowing the current to flow through the LED when the digital pin is set to HIGH.
// Ensure the Arduino is connected to the computer via USB: To enable serial communication and program the Arduino, ensure it is connected to your computer via USB.