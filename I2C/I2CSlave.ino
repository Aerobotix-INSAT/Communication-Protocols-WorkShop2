#include <Wire.h>

int x = 0;  // Variable to hold data to send to master

void setup() {
  // Define the LED pin as Output
  pinMode(LED_BUILTIN, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach functions to handle receive and request events
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  
  // Start serial communication for debugging
  Serial.begin(9600);
}

void receiveEvent(int bytes) {
  // Read one character from the I2C bus
  x = Wire.read();
  Serial.println(x);
}

void requestEvent() {
  // Send data back to the master when requested
  Wire.write(x/2);  // Sends the current value of x to the master
}

void loop() {
  // If value received is 0, blink LED for 200 ms
  if (x == 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }
  // If value received is 3, blink LED for 400 ms
  if (x == 3) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(400);
    digitalWrite(LED_BUILTIN, LOW);
    delay(400);
  }
}
