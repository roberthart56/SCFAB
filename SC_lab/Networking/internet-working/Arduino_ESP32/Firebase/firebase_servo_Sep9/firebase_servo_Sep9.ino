#include <WiFi.h>                                 // esp32 library
#include <FirebaseESP32.h>                        // firebase library
#include <ESP32Servo.h>

#define FIREBASE_HOST "https://esp32-led01.firebaseio.com/"   // the project name address from firebase id
#define FIREBASE_AUTH "MZYoPuL5wC3jFl3uKHZ8rkwUZYUnYYvMPEL1BEWJ"                          // the secret key generated from firebase
#define WIFI_SSID "Purple Cow 2"                                // input your home or public wifi name
#define WIFI_PASSWORD "indiana0623"                            // password of wifi ssid

Servo myservo;  // create servo object to control a servo

int firebaseInt = 0;                                          // led status received from firebase
int ledpin = 5;
int servo_pin = 21; 

//Define FirebaseESP32 data object
FirebaseData firebaseData;

void setup() {
  pinMode(ledpin, OUTPUT);
  
  Serial.begin(9600);
  delay(10);
  
  myservo.attach(servo_pin);  // attaches the servo to the servo object
  
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
  Firebase.set(firebaseData, "/Variable_1", 90);              // set initial string of "OFF"
}

void loop() {

  Firebase.get(firebaseData, "/Variable_1");                     // get led status input from firebase
  firebaseInt = firebaseData.intData();                        // change to e.g. intData() or boolData()
  Serial.println(firebaseInt);
  myservo.write(firebaseInt);
 
  delay(10);                                 // not strictly necessary
}
