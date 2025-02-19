#include<SPI.h>
int x=0;
byte Mastereceive;        
void setup (void)
{
  Serial.begin(9600);
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}
void loop(void)
{
  digitalWrite(SS, LOW);                 //Starts communication with Slave connected to master
  Mastereceive=SPI.transfer(x); //Send the mastersend value to slave also receives value from slave
  digitalWrite(SS, HIGH);
  Serial.println(Mastereceive);
  x += 1;
  if(x > 10)
    x = 0;
  delay(1000);
}