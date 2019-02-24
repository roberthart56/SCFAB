void setup() 
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
    Serial.print ("Counterclockwise");
    Serial.println();
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(3000);  
    
    Serial.print ("Clockwise");
    Serial.println();
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    delay(3000);
}
