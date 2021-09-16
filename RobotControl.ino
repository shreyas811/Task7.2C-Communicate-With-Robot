#include <AFMotor.h>

AF_DCMotor leftBack(1); //Back Left wheel
AF_DCMotor rightBack(2); //Back right wheel
AF_DCMotor rightFront(3); //Right Front Wheel
AF_DCMotor leftFront(4); //Left Front Wheel

const int MAX_SPEED = 255;



//Stops all motors
void roverStop(){
  leftBack.run(RELEASE);
  rightBack.run(RELEASE);
  rightFront.run(RELEASE);
  leftFront.run(RELEASE);
  delay(2000);
}

//runs all motors in the forward direction
void roverForward(){
  speedSet(MAX_SPEED);
  leftBack.run(FORWARD);
  rightBack.run(FORWARD);
  rightFront.run(FORWARD);
  leftFront.run(FORWARD);
  delay(2000);
}

//runs all motors in the backward direction
void roverReverse(){
  speedSet(MAX_SPEED);
  leftBack.run(BACKWARD);
  rightBack.run(BACKWARD);
  rightFront.run(BACKWARD);
  leftFront.run(BACKWARD);
  delay(2000);
}

//runs only the left wheels forward
void roverTurnRight(){
  speedSet(MAX_SPEED);
  leftBack.run(FORWARD);
  rightBack.run(RELEASE);
  rightFront.run(RELEASE);
  leftFront.run(FORWARD);
  delay(4000);
}

//runs only the right wheels forward
void roverTurnLeft(){
  speedSet(MAX_SPEED);
  leftBack.run(RELEASE);
  rightBack.run(FORWARD);
  rightFront.run(FORWARD);
  leftFront.run(RELEASE);
  delay(4000);
}

//sets the speed of the motors
void speedSet(int num){
  leftBack.setSpeed(num);
  rightBack.setSpeed(num);
  rightFront.setSpeed(num);
  leftFront.setSpeed(num);
  delay(500);
}


unsigned char terminal_value;
void Robot_Control()
{
  while (terminal_value != 'E') 
  {
    if (Serial.available()) 
    {
      terminal_value = Serial.read();
      switch (terminal_value)
      {
        case 'f': roverForward(); Serial.print("\n Robot Forward "); 
          break;
        case 'b': roverReverse();   Serial.print("\n Robot Reverse "); 
          break;
        case 'l': roverTurnLeft();   Serial.print("\n Robot Turn Left"); 
          break;
        case 'r': roverTurnRight();   Serial.print("\n Robot Turn Right "); 
          break;
        case 's': roverStop();   Serial.print("\n Robot Stop "); 
          break;
        default: roverStop();
          break;
      }
    }
  }
  roverStop();
}

void setup() {
  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  speedSet(MAX_SPEED);
  roverStop();
  delay(2000);
}

void loop() {
 


if(Serial.available()){//Is bluetooth able to receive values?
  Robot_Control();
}else{
  digitalWrite(LED_BUILTIN,HIGH);
  }

}
