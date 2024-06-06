#include <Adafruit_AHTX0.h> // Include the library for the AHT20 sensor

#define LHS_PIN 17
#define RHS_PIN 21

Adafruit_AHTX0 aht; // Create an instance of the AHT20 sensor

void setup() {
  pinMode(LHS_PIN, INPUT_PULLDOWN); // Set LHS_PIN as input with internal pull-down resistor
  pinMode(RHS_PIN, INPUT_PULLDOWN); // Set RHS_PIN as input with internal pull-down resistor
  Serial.begin(115200); // Initialize serial communication
  
  if (!aht.begin()) { // Initialize the AHT20 sensor
    Serial.println("Could not find AHT20 sensor!");
    while (1) { delay(10); } // Halt program
  }
  Serial.println("AHT20 sensor found and initialized.");
}

void loop() {
  // Check the state of the SPDT switch
  if (digitalRead(LHS_PIN) == HIGH) {
    // Read temperature and humidity from the sensor
    float temperature = aht.readTemperature();
    float humidity = aht.readHumidity();

    // Print the readings to the serial monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" degrees C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    // Print a message indicating that reading is paused
    Serial.println("Reading paused. Toggle the switch to resume.");
  }

  delay(2000); // Delay for 2 seconds before reading again
}

// check image for description
