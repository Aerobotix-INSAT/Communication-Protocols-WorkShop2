#include <SPI.h>

volatile int dataReceived = 0; // Data received from the master
int dataToSend = 0; // Data to send to the master

void setup() {
  // Start SPI communication as slave
  pinMode(MISO, OUTPUT); // Set MISO pin as output for sending data
  SPI.begin();
  Serial.begin(9600);

  // Attach the SPI interrupt to trigger when data is received
  SPI.attachInterrupt(); 
}

void loop() {
  // Wait for the SPI communication
  // Print the received data
  Serial.print("Received: ");
  Serial.println(dataReceived);
  
  // Send the data to master
  dataToSend++;
  if (dataToSend > 5) {
    dataToSend = 0; // Reset to 0 once data reaches 6
  }

  delay(1000); // Wait for 1 second
}

// SPI interrupt function to handle data reception
ISR(SPI_STC_vect) {
  dataReceived = SPDR; // Read the received data from the SPI Data Register
  SPDR = dataToSend; // Write the data to the SPI Data Register to send it back to the master
}
