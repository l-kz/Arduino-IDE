//Connect the PIR sensor to the ESP32:
// passive infrared
//Connect the VCC pin of the PIR sensor to a 5V pin on the ESP32.
//Connect the GND pin of the PIR sensor to a ground (GND) pin on the ESP32.
//Connect the OUT pin of the PIR sensor to a digital input pin on the ESP32 (e.g., GPIO 21).
//Write a simple Arduino sketch to read and plot the output of the PIR sensor:

#define PIR_PIN 21 // Define the digital input pin for the PIR sensor

void setup() {
  pinMode(PIR_PIN, INPUT); // Set PIR_PIN as input
  Serial.begin(115200); // Initialize serial communication
}

void loop() {
  // Print static values to fix the y-axis of the plotter
  Serial.print("min:-1, max:1.5,");
  // Read and print the PIR sensor reading
  Serial.print("PIR:");
  Serial.println(digitalRead(PIR_PIN));
  delay(500); // Add a delay to customize your plotting
}
//Upload this code to your ESP32 board, and then open the Serial Plotter in the Arduino IDE (Tools > Serial Plotter). You should see the PIR sensor output being plotted. As motion is detected, the plot should show a high (1) value, and as motion stops, it should return to a low (0) value.
// check image for description