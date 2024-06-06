//Connect one wire of the magnetic door switch to GPIO pin 21 on your ESP32 board.
//Connect a 10kΩ resistor between GPIO pin 21 and the positive VCC rail (3.3V).
//Connect the other wire of the magnetic door switch to the ground (GND) rail.
//After connecting the door switch, you can use the following code to verify its operation:


#define DOOR_PIN 21

void setup() {
  pinMode(DOOR_PIN, INPUT);
  Serial.begin(115200);
  Serial.print("Door status: ");
  Serial.println(digitalRead(DOOR_PIN) == HIGH ? "Open" : "Closed");
}

void loop() {
  // Continuous monitoring of the door status
  Serial.print("Door status: ");
  Serial.println(digitalRead(DOOR_PIN) == HIGH ? "Open" : "Closed");
  delay(1000); // Delay for 1 second before reading again
}