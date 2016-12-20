int dir1PinA = 8;
int dir2PinA = 9;
int speedPinA = 10;
int controlPin = 2;
bool toggle = 0;
bool thisSwitch = 0;
bool lastSwitch = 0;


void setup() { 
//Define L298N Dual H-Bridge Motor Controller Pins
pinMode(dir1PinA,OUTPUT);
pinMode(dir2PinA,OUTPUT);
pinMode(speedPinA,OUTPUT);
pinMode(controlPin, INPUT);

}

void loop() {
  lastSwitch = thisSwitch;
  thisSwitch = digitalRead(controlPin); 

  if((thisSwitch == 1) && (lastSwitch == 0))
    toggle = !toggle;

  if(toggle) {
    analogWrite(speedPinA, 64);//Sets speed variable via PWM 
  } else {
    analogWrite(speedPinA, 0);
  }
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
}
