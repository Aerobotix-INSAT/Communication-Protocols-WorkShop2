#include <Wire.h>

int x = 0;
int slaveData = 0;  // Variable to store data received from slave

void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  // Request data from slave (address 9)
  Wire.requestFrom(9, 1);  // Request 1 byte from slave with address 9
  if (Wire.available()) {
    slaveData = Wire.read();  // Read the received byte
  }
  
  // Transmit data to slave
  Wire.beginTransmission(9);  // Transmit to device #9
  Wire.write(x);              // Sends x 
  Wire.endTransmission();     // Stop transmitting
  x++; // Increment x
  if (x > 5) x = 0; // Reset x once it gets 6

  // Optionally, you can print the data received from the slave
  Serial.print("Received from slave: ");
  Serial.println(slaveData);

  delay(1000); // Wait for 1 second
}
