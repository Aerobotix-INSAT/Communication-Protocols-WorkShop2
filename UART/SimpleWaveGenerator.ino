#define BAUDRATE 9600;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 20; i++){
    Serial.println(i);
    delay(50);
  }
  for(int i = 20; i > 0; i--){
    Serial.println(i);
    delay(50);
  }
}
