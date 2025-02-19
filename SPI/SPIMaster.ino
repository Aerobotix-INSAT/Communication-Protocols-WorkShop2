#include <SPI.h>

int dataToSend = 0; // Data to send to the slave
int dataReceived = 0; // Data received from the slave

void setup() {
  // Start SPI communication as master
  SPI.begin();
  Serial.begin(9600);
  // Set the SPI settings: Clock speed = 1 MHz, MSB first, SPI Mode 0
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}

void loop() {
  // Send data to slave and receive data simultaneously
  dataReceived = SPI.transfer(dataToSend);

  // Print received data to Serial Monitor
  Serial.print("Sent: ");
  Serial.print(dataToSend);
  Serial.print(" - Received: ");
  Serial.println(dataReceived);

  // Increment the data to send
  dataToSend++;

  if (dataToSend > 5) {
    dataToSend = 0; // Reset to 0 once data reaches 6
  }

  delay(1000); // Wait for 1 second
}
