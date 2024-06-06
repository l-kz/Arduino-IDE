#define LED_PIN 13 // this defines the pin in the code as 13 sop instead of writing LED_PIN everywhere we use 13
int delayTime = 2000;

void setup() {
  //setting up baud rate
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  pinMode (LED_PIN, OUTPUT); // this meas that the pin specified by LED_PIN will be an output pin such as turning leds on and off
  Serial.println("Enter delay time in ms");


}

void loop() {
  // for input of messages use if (Serial.available())
  if (Serial.available() > 0) {
    int newDelayTime = Serial.parseInt();
    if (newDelayTime >= 100 && newDelayTime <= 400) {
      delayTime = newDelayTime;
      Serial.println("New delay time has been set to:");
      Serial.println(newDelayTime);
    }
    else {
      Serial.println("Delay time is out of range");
    }
  }
  // in order to turn the LED on:
  digitalWrite(LED_PIN, HIGH);
  // wait 2000 milliseconds (2 seconds)
  delay(delayTime);
  // after 2 seconds, turn led off
  digitalWrite(LED_PIN, LOW);
  // wait another 2 seconds before loop turns LED back on
  delay(delayTime);


}