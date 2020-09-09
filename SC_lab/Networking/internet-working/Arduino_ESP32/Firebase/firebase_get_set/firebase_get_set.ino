#include <WiFi.h>                                 // esp32 library
#include <FirebaseESP32.h>                        // firebase library

#define FIREBASE_HOST "https://esp32-led01.firebaseio.com/"   // the project name address from firebase id
#define FIREBASE_AUTH "MZYoPuL5wC3jFl3uKHZ8rkwUZYUnYYvMPEL1BEWJ"                          // the secret key generated from firebase
#define WIFI_SSID "Purple Cow 2"                                // input your home or public wifi name
#define WIFI_PASSWORD "indiana0623"                            // password of wifi ssid

String fireString = "";                                          // led status received from firebase
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
  Firebase.set(firebaseData, "/LED_STATUS", "OFF");              // set initial string of "OFF"
}

void loop() {

  Firebase.get(firebaseData, "/LED_STATUS");                     // get led status input from firebase
  fireString = firebaseData.stringData();                        // change to e.g. intData() or boolData()
  Serial.println(fireString);
  
  if (fireString == "ON") {                    // compare the input of led status received from firebase
    Serial.println("Led Turned ON");
    digitalWrite(ledpin, HIGH);                // make output led ON
    Firebase.set(firebaseData, "/LED_STATUS", "OFF");     //toggle
  }

  else if (fireString == "OFF") {              // compare the input of led status received from firebase
    Serial.println("Led Turned OFF");
    digitalWrite(ledpin, LOW);                 // make output led OFF
    Firebase.set(firebaseData, "/LED_STATUS", "ON");
  }

  else {
    Serial.println("Please send ON/OFF");
  }

  delay(1000);                                 // not strictly necessary
}
