
int dir1Pin = 8;
int dir2Pin = 9;
int speedPin = 10; 
int controlPin = 2;
bool toggle = 0;
bool thisSwitch = 0;
bool lastSwitch = 0;



void setup() {
Serial.begin(9600);
//Define L298N Pins
pinMode(dir1Pin,OUTPUT);
pinMode(dir2Pin,OUTPUT);
pinMode(speedPin,OUTPUT);
pinMode(controlPin, INPUT);
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

int inByte;

void loop() {
lastSwitch = thisSwitch;
thisSwitch = digitalRead(controlPin); 
if((thisSwitch == 1) && (lastSwitch == 0))
  toggle = !toggle;
  
  if(toggle) {
    if (Serial.available() > 0) {
        int inByte = Serial.parseInt();
        motor(inByte);
        Serial.println("Motor 1 Forward @"); // Prints out “Motor 1 Forward” on the serial monitor
        Serial.println(inByte);
        Serial.println("   "); // Creates a blank line printed on the serial monitor
    }
  } else {
    motor(0);
  }
}

