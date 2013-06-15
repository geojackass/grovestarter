//CODE

/*
* author Shoichi Otomo
*/

int button1 = 1; //Grove port number for button
int button2 = 2; //Grove port number for button
int touch = 3; // Grove port number for touch sencer

int LED_B = 7; //Grove port number for LED_BLUE
int LED_G = 8; //Grove port number for LED_GREEN
int LED_R = 9; //Grove port number for RED

void setup(){
  pinMode(button1, INPUT); //set button input device
  pinMode(button2, INPUT); //set button input device
  pinMode(touch, INPUT); //set button input touch device
  
  pinMode(LED_B, OUTPUT); //set LED as an OUTPUT
  pinMode(LED_G, OUTPUT); //set LED as an OUTPUT
  pinMode(LED_R, OUTPUT); //set LED as an OUTPUT
}

void loop(){
  blueLED();
  greenLED();
  redLED();
}

void blueLED(){
  int buttonState1 = digitalRead(button1);
  
  if(buttonState1 == 1){
    digitalWrite(LED_B, 1);
  }else{
    digitalWrite(LED_B, 0);
  }
}

void greenLED(){
  int buttonState2 = digitalRead(button2);
  
  if(buttonState2 == 1){
    digitalWrite(LED_G, 1);
  }else{
    digitalWrite(LED_G, 0);
  }
}

void redLED(){
  int touchState = digitalRead(touch);
  //read the status of touch
  if(touchState == 1){
    digitalWrite(LED_R, 1); //turn on the LED
  }else{
    digitalWrite(LED_R, 0); //turn off the LED
  }
}
