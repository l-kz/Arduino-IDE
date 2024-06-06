#define PIR_PIN 33 // Define the input pin for the PIR sensor

void setup() {
  pinMode(PIR_PIN, INPUT); // Set PIR_PIN as input
  Serial.begin(115200); // Initialize serial communication
  while (!Serial) { continue; } // Wait for serial connection
  Serial.println("Device ready"); // Print message indicating device readiness
  
  // Enable EXT0 as wakeup source for motion detection
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
}

void loop() {
  // Check the wake up reason
  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
  switch(wakeup_reason) {
    case ESP_SLEEP_WAKEUP_EXT0:
      Serial.println("Wakeup caused by external signal using RTC_IO");
      break;
    case ESP_SLEEP_WAKEUP_EXT1:
      Serial.println("Wakeup caused by external signal using RTC_CNTL");
      break;
    default:
      Serial.println("Wakeup not caused by external signal");
      break;
  }

  //Connect the VCC pin of the PIR sensor to a 5V power source.
//Connect the GND pin of the PIR sensor to the ground (GND) of your microcontroller.
//Signal Pin (Output):
//onnect the OUT pin of the PIR sensor to pin 33 (or any other pin you've defined) on your ESP32.