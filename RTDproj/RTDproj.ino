//Global Variables
String input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  readSerial();
  delay(1000);
}

void readSerial(){
    while(Serial.available()) {
      input = Serial.readString();// read the incoming data as string
    }
    Serial.println(input);
}


