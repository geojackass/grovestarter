//CODE

/*
* author Shoichi Otomo
*/

#include <Servo.h>

Servo groveServo;

int potentialmeter = 0; //Grove analogIn0
int shaft;
int button1 = 1; //Grove port number for button
int touch = 3; // Grove port number for touch sencer

int LED_B = 7; //Grove port number for LED_BLUE
int LED_G = 8; //Grove port number for LED_GREEN
int LED_R = 9; //Grove port number for RED

void setup(){
  groveServo.attach(2); //prepare for servo
  pinMode(potentialmeter, INPUT); //set potentialmeter input
  
  pinMode(button1, INPUT); //set button input device
  pinMode(touch, INPUT); //set button input touch device
  
  pinMode(LED_B, OUTPUT); //set LED as an OUTPUT
  pinMode(LED_G, OUTPUT); //set LED as an OUTPUT
  pinMode(LED_R, OUTPUT); //set LED as an OUTPUT
}

void loop(){
  blueLED();
  greenLED();
  redLED();
  servo();
}


void blueLED(){
  int touchState = digitalRead(touch);
  
  if(touchState == 1){
    digitalWrite(LED_B, 1);
  }else{
    digitalWrite(LED_B, 0);
  }
}


void greenLED(){
  int buttonState1 = digitalRead(button1);
  
  if(buttonState1 == 1){
    digitalWrite(LED_G, 1);
  }else{
    digitalWrite(LED_G, 0);
  }
}

void redLED(){
  int buttonState1 = digitalRead(button1);
  //read the status of button
  if(buttonState1 == 0){
    digitalWrite(LED_R, 1); //button OFF -> turn on the LED
  }else{
    digitalWrite(LED_R, 0); //button ON -> turn off the LED
  }
}


void servo(){
  shaft = analogRead(potentialmeter);
  shaft = map(shaft, 0, 1023, 0, 179);
  groveServo.write(shaft);
  delay(15);
}

