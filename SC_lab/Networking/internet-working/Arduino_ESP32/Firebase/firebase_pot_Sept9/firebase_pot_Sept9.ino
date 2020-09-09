#include <WiFi.h>                                 // esp32 library
#include <FirebaseESP32.h>                        // firebase library

#define FIREBASE_HOST "https://esp32-led01.firebaseio.com/"   // the project name address from firebase id
#define FIREBASE_AUTH "MZYoPuL5wC3jFl3uKHZ8rkwUZYUnYYvMPEL1BEWJ"                          // the secret key generated from firebase
#define WIFI_SSID "Purple Cow 2"                                // input your home or public wifi name
#define WIFI_PASSWORD "indiana0623"                            // password of wifi ssid

int sensorVal = 0;                                           // led status received from firebase
int ledpin = 5;

//Define FirebaseESP32 data object
FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(ledpin, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                          // try to connect with wifi

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
  Serial.println(WiFi.localIP());                                // print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                  // connect to firebase
  Firebase.reconnectWiFi(true);
  Firebase.set(firebaseData, "/Variable_1", 0);              // set initial string of "OFF"
}

void loop() {
  sensorVal = analogRead(33);
  int angle = sensorVal*180/4096;   //map volt to angle.
  Firebase.set(firebaseData, "/Variable_1", angle);                     // get led status input from firebase
  Serial.println(angle);
  
 
  delay(10);                                 // not strictly necessary
}
