#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

RH_ASK rf_driver;

int ledState1 = LOW;
int ledState2= LOW;
int ledState3 = LOW;
int ledState4 = LOW;

int toBuzzg = false;
int toBuzzr = false;
int toBuzzb = false;
int toBuzzy = false;


int buzzerPin = 7;
int RedPin = 8;
int GreenPin = 9;
int BluePin = 10; 

void setup() {
  // put your setup code here, to run once:
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
    // Initialize ASK Object
    if (! rf_driver.init()) {
      Serial.println("initialize fail");
    } else {
      Serial.println("success");
    }
}

void loop() {

  uint8_t buf[3];
  uint8_t buflen = sizeof(buf);
  if (rf_driver.recv(buf, &buflen))
    {
     Serial.println((char*)buf); 
     if(!(strcmp(((char*)buf), "gre"))){
        ledState1 = !ledState1;
        toBuzzg = !toBuzzg;
        Serial.println("green");
        green();
        
 
      }
      if(!(strcmp(((char*)buf), "blu"))){
        ledState2 = !ledState2;
        toBuzzb = !toBuzzb;
        Serial.println("blue");
        blue();
      }
      if(!(strcmp(((char*)buf), "yel"))){
        ledState3 = !ledState3;
        toBuzzy = !toBuzzy;
        Serial.println("ytellow");
        yellow();

      }
      if(!(strcmp(((char*)buf), "red"))){
        ledState4 = !ledState4;
        toBuzzr = !toBuzzr;
        Serial.println("red");
        red();
      }
    }
}

void red () {
  digitalWrite(RedPin, ledState4);
  digitalWrite(GreenPin, LOW);
  digitalWrite(BluePin, LOW);
  if(toBuzzr){
    tone(buzzerPin, ledState4);
  }else{
    noTone(buzzerPin);
  }
  //set the LED pins to values that make red
  
}
void yellow () {
  digitalWrite(RedPin, ledState3);
  digitalWrite(GreenPin, LOW);
  digitalWrite(BluePin, ledState3);
  
  if(toBuzzy){
      tone(buzzerPin, ledState3);
   }else{
      noTone(buzzerPin);
   }
  //set the LED pins to values that make yellow
  
}
void green () {
    digitalWrite(RedPin, LOW);
    digitalWrite(GreenPin, ledState1);
    digitalWrite(BluePin, LOW);
  if(toBuzzg){
    tone(buzzerPin, ledState1);
  }else{
    noTone(buzzerPin);
  }
  //set the LED pins to values that make green
    
 
}
void blue () {
  digitalWrite(RedPin, LOW);
  digitalWrite(GreenPin, LOW);
  digitalWrite(BluePin, ledState2);
  if(toBuzzb){
    tone(buzzerPin, ledState2);
  }else{
    noTone(buzzerPin);
  }
  //set the LED pins to values that make blue
  
}
