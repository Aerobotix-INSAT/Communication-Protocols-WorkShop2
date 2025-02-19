#define BAUDRATE 9600

bool LedState = LOW;

void setup() {
  Serial.begin(BAUDRATE); //init the serial communication
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available()) {  // Check if data is received
    char message = Serial.read(); // Read full input
    Serial.readString(); // remove queued up commands
    switch(message){
      case 'A':
        LedState = true;
        break;
      case 'B':
        LedState = false;
        break;
      case 'C':
        for(int i = 0; i < 5; i++){
          pinMode(LED_BUILTIN, HIGH);
          delay(500);
          pinMode(LED_BUILTIN, LOW);
          delay(500);
        }
        break;
      default:
        Serial.print("Invalid Command, Choose A, B or C Got ");
        Serial.print((char)message);
        Serial.println(" Instead");
        break;
    }
    pinMode(LED_BUILTIN, !LedState);
  }
}
