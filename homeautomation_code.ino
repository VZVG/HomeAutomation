
#include<Servo.h>
#define fan LED_BUILTIN
#define bulb1 8
#define bulb2 10
Servo Gate;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  Gate.attach(9);
pinMode (bulb1, OUTPUT);
pinMode (bulb2, OUTPUT);
pinMode (fan, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() == 1)
  {
    String val = Serial.readString();
    Serial.println(val);
    if(val == "fan on")
    {
      digitalWrite(fan, HIGH);
    }  
    if(val == "fan off")
    {
      digitalWrite(fan, LOW);
    }
 if(val == "bulb1 on")
    {
      digitalWrite(bulb1, HIGH);
    }
    if(val == "bulb1 off")
    {
      digitalWrite(bulb1, LOW);
    }
  if(val == "bulb2 on")
    {
      digitalWrite(bulb2, HIGH);
    }
    if(val == "bulb2 off")
    {
      digitalWrite(bulb2, LOW);
    }
  if(val == "Gate Open")
    {
      Gate.write(0);
    }
    if(val == "Gate close")
    {
      Gate.write(90);
    }
        
 if(val == "open all")
    {
      digitalWrite(fan, HIGH);
      digitalWrite(bulb1, HIGH);
      digitalWrite(bulb2, HIGH);
      Gate.write(0);
    }
    if(val == "close all")
    {
      digitalWrite(bulb1, LOW);
      digitalWrite(bulb2, LOW);
      digitalWrite(fan, LOW);
      Gate.write(90);
    }
  }
}
