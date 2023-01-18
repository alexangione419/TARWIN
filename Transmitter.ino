#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

RH_ASK rf_driver;

int button[] = {0, 1, 2, 3};
int pressedButton = 4;
int lastButtonState1;    // the previous state of button
int lastButtonState2;
int lastButtonState3;
int lastButtonState4;
int currentButtonState1 = HIGH; // the current state of button
int currentButtonState2 = HIGH;
int currentButtonState3 = HIGH;
int currentButtonState4 = HIGH;

void setup() {
  pinMode(button[0], INPUT_PULLUP);
  pinMode(button[1], INPUT_PULLUP);
  pinMode(button[2], INPUT_PULLUP);
  pinMode(button[3], INPUT_PULLUP);
  
  Serial.begin(9600);
    // Initialize ASK Object
  if (! rf_driver.init()) {
    Serial.println("initialize fail");
  } else {
    Serial.println("success");
  }
}

void loop() {
  lastButtonState1    = currentButtonState1;      // save the last state
  currentButtonState1 = digitalRead(button[0]);
  
  if (lastButtonState1 == HIGH && currentButtonState1 == LOW){ 
    const char *msg = "gre";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
  }
  
  lastButtonState2    = currentButtonState2;      // save the last state
  currentButtonState2 = digitalRead(button[1]);
  
  if (lastButtonState2 == HIGH && currentButtonState2 == LOW){ 
    const char *msg = "blu";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
  }

  lastButtonState3    = currentButtonState3;      // save the last state
  currentButtonState3 = digitalRead(button[2]);
  
  if (lastButtonState3 == HIGH && currentButtonState3 == LOW){ 
    const char *msg = "yel";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
  }
  
  lastButtonState4    = currentButtonState4;      // save the last state
  currentButtonState4 = digitalRead(button[3]);
  

  if (lastButtonState4 == HIGH && currentButtonState4 == LOW){ 
    const char *msg = "red";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
  }
  
}
