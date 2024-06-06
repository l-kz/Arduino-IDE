#define BUTTON_PIN 14 // Define button pin
int buttonState = 0; // Global variable to store button state


void setup() {
  // Setting up serial communication
  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  // Setting up button pin as input
  pinMode(BUTTON_PIN, INPUT);

  // Print initial state of the button
  Serial.print("Initial state of button: ");
  Serial.println(digitalRead(BUTTON_PIN));

  // Adding a short delay for stability
  delay(500);
}

void loop() {
  byte newButtonState = digitalRead(BUTTON_PIN); // read the button state
  
  // Button state has changed
  if (newButtonState != buttonState) {
    buttonState = newButtonState; // Update state variable
    
    // Button pressed
    if (buttonState == HIGH) {
      Serial.println("Button pressed");
    } 
    // Button released
    else {
      Serial.println("Button released");
    }
  }
  
  // No delay as we want to see bouncing in the serial monitor
}

// descrption:
//Connect one leg of the button to pin 14 (or any other digital pin you choose) on your Arduino board.
//Connect the other leg of the button to any ground (GND) pin on the Arduino board.
//Here's a step-by-step guide:

//Button Wiring:
//Take a momentary push-button switch. These switches usually have four pins but for basic functionality, you'll only use two of them.
//Identify one leg of the button. This is typically indicated by a longer lead or a different shape on the button housing.
//Connect this leg to pin 14 (or any digital pin you've chosen) on your Arduino. This pin will be your input pin (BUTTON_PIN in the code).
//Identify the other leg of the button. This is typically indicated by a shorter lead or a different shape on the button housing.
//Connect this leg to any GND pin on your Arduino to complete the circuit.
