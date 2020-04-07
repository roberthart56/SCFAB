
#include <WiFi.h>                                 // esp32 library
#include <IOXhop_FirebaseESP32.h>                 // firebase library

//#include <ArduinoJson.h>

#define FIREBASE_HOST "https://esp32-led01.firebaseio.com/" // the project name address from firebase id
#define FIREBASE_AUTH "MZYoPuL5wC3jFl3uKHZ8rkwUZYUnYYvMPEL1BEWJ"                          // the secret key generated from firebase
#define WIFI_SSID "Purple Cow 2"                                // input your home or public wifi name
#define WIFI_PASSWORD "indiana0623"                            // password of wifi ssid

String fireStatus = "";                                 // led status received from firebase

int ledpin = 5;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(ledpin, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      //try to connect with wifi

  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                                      //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                                       // connect to firebase
  Firebase.setString("LED_STATUS", "OFF");                                          //send initial string of led status

}

void loop() {

  fireStatus = Firebase.getString("LED_STATUS");                     // get led status input from firebase
  if (fireStatus == "ON") {                         // compare the input of led status received from firebase
    Serial.println("Led Turned ON");
    digitalWrite(ledpin, HIGH);                                                         // make output led ON
  }

  else if (fireStatus == "OFF") {              // compare the input of led status received from firebase
    Serial.println("Led Turned OFF");
    digitalWrite(ledpin, LOW);                                                         // make output led OFF
  }

  else {
    Serial.println("Wrong Credential! Please send ON/OFF");
  }
}
