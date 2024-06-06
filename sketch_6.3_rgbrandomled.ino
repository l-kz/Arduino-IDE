// Define the pins for the RGB LED
#define RED_PIN A0
#define GREEN_PIN A1
#define BLUE_PIN A5

// Initialize variables to store color values
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  Serial.begin(115200);
  
  // Set the RGB LED pins as outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Initialize random seed
  randomSeed(analogRead(0));
}

void setRGBColour(int redValue, int greenValue, int blueValue) {
  analogWrite(RED_PIN, redValue);
  analogWrite(GREEN_PIN, greenValue);
  analogWrite(BLUE_PIN, blueValue);
  
  // Print color values to serial monitor
  Serial.print("Red: ");
  Serial.print(redValue);
  Serial.print("\tGreen: ");
  Serial.print(greenValue);
  Serial.print("\tBlue: ");
  Serial.println(blueValue);
}

void loop() {
  // Generate random color values between 0 and 255
  redValue = random(0, 256);
  greenValue = random(0, 256);
  blueValue = random(0, 256);
  
  // Set the RGB LED to the random color
  setRGBColour(redValue, greenValue, blueValue);
  
  // Delay for 1 second (1000 milliseconds)
  delay(1000);
}

// for description check practical image
// Connect the RGB LED: RGB LEDs usually have four pins - one for each color (Red, Green, and Blue) and one common cathode (or anode). Since you're using individual pins for each color, ensure you're using a common cathode RGB LED. Connect the cathode pin (the longer one) to the ground (GND) pin on the Arduino.
//Connect the Red Pin (RED_PIN): Connect the pin labeled "Red" on the RGB LED to an analog pin on the Arduino (A0 in this case). Ensure that there's a current-limiting resistor (220-330 ohms) between this pin and the Arduino pin.
//Connect the Green Pin (GREEN_PIN): Connect the pin labeled "Green" on the RGB LED to another analog pin on the Arduino (A1 in this case). Again, use a current-limiting resistor between this pin and the Arduino pin.
//Connect the Blue Pin (BLUE_PIN): Connect the pin labeled "Blue" on the RGB LED to yet another analog pin on the Arduino (A5 in this case). Use a current-limiting resistor between this pin and the Arduino pin.