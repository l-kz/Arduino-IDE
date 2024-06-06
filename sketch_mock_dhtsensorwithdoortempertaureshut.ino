#include <DHT.h>

#define DHTPIN 2  // Replace with the actual pin number connected to the DHT22 data pin
#define DHTTYPE DHT22  // Define the type of DHT sensor

#define DOOR_PIN 3  // Replace with the actual pin number connected to the door control mechanism

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(DOOR_PIN, OUTPUT);
  dht.begin();
}

#include <DHT.h>

#define DHTPIN 2    // Pin connected to the DHT22 sensor
#define DHTTYPE DHT22  // Type of DHT sensor

#define MAGNETIC_SWITCH_PIN 3  // Pin connected to the magnetic door switch

#define DOOR_OPEN  LOW  // Define the state when the door is open
#define DOOR_CLOSED  HIGH  // Define the state when the door is closed

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(MAGNETIC_SWITCH_PIN, INPUT_PULLUP);  // Use INPUT_PULLUP to enable internal pull-up resistor
  dht.begin();
}

void loop() {
  // Read temperature
  float temperature = dht.readTemperature();

  // Read state of magnetic door switch
  int doorState = digitalRead(MAGNETIC_SWITCH_PIN);

  // Check if the door is closed
  if (doorState == DOOR_CLOSED) {
    Serial.println("Door is closed.");
    
    // Check if temperature is within the desired range (20°C to 30°C)
    if (!isnan(temperature) && temperature >= 20 && temperature <= 30) {
      Serial.println("Temperature is within the desired range. Door open.");
      // Keep the door open
      // digitalWrite(DOOR_CONTROL_PIN, LOW); // Keep door control mechanism inactive
    } else {
      Serial.println("Temperature is not within the desired range. Door shut.");
      // Trigger door control mechanism to shut the door
      // digitalWrite(DOOR_CONTROL_PIN, HIGH); // Activate door control mechanism
    }
  } else {
    Serial.println("Door is open.");
    // Keep the door open
    // digitalWrite(DOOR_CONTROL_PIN, LOW); // Keep door control mechanism inactive
  }

  delay(5000);  // Read temperature and door state every 5 seconds (adjust as needed)
}

//Connect the VCC pin of the DHT22 sensor to the 3.3V power source on your microcontroller or a separate 3.3V power supply.
//C/onnect the GND pin of the DHT22 sensor to the ground (GND) pin on your microcontroller or to the ground of the power supply.
//Connect the DATA pin of the DHT22 sensor to pin 2 (or any other digital pin you choose) on your microcontroller.
//Magnetic Door Switch:
//Connect one terminal of the magnetic door switch to a digital pin on your microcontroller (for example, pin 3).
//Connect the other terminal of the magnetic door switch to ground (GND) on your microcontroller.