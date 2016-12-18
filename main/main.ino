int dir1Pin = 2;
int dir2Pin = 3;
int speedPin = 9;

void setup() {
Serial.begin(9600);
//Define L298N Dual H-Bridge Motor Controller Pins
pinMode(dir1Pin,OUTPUT);
pinMode(dir2Pin,OUTPUT);
pinMode(speedPin,OUTPUT);
}

void motor(int reqSpeed) {
  if(reqSpeed >= 0) {
    analogWrite(speedPin, reqSpeed);//Sets speed variable via PWM 
digitalWrite(dir1Pin, LOW);
digitalWrite(dir2Pin, HIGH);
  } else if(reqSpeed < 0) {
    analogWrite(speedPin, reqSpeed);
digitalWrite(dir1Pin, HIGH);
digitalWrite(dir2Pin, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
