//Global Variables
const char* ssid = "CU Denver";
const char* password = "";

#include <WiFi.h>
#include <HTTPClient.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupWifi();
}

void loop() {
  // put your main code here, to run repeatedly:
    if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    http.begin("http://jsonplaceholder.typicode.com/comments?id=10"); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(10000);
}

void setupWifi(){
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to the wifi network!");
  Serial.println(WiFi.localIP());
}

