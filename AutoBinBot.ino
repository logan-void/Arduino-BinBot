#include <Servo.h>
#include <NewPing.h>

int motora1 = 2;
int motora2 = 3;
int motorb1 = 5;
int motorb2 = 4;
int enablea = 6;
int enableb = 7;
int const trigPin = 8;
int const echoPin = 9;
Servo servo;
char val;

void setup(){
  
  pinMode(motora1, OUTPUT);
  pinMode(motora2, OUTPUT);
  pinMode(motorb1, OUTPUT);
  pinMode(motorb2, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  servo.attach(10);
  Serial.begin (9600);
}

void loop(){

  int duration, distance;
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  Serial.println(distance);
  
  if (distance <= 5 && distance >= 0){	
  digitalWrite (motora1, LOW);
  digitalWrite (motora2, LOW);
  analogWrite (enablea, 190);
  digitalWrite (motorb1, LOW);
  digitalWrite (motorb2, LOW);
  analogWrite (enableb, 190);
  
  servo.write(70);
  delay(2000);
  } 
  else{		
  servo.write(180);
  }

  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if(val == 'F') // Forward
    {
      digitalWrite (motora1, HIGH);
      digitalWrite (motora2, LOW);
      analogWrite (enablea, 190);
      digitalWrite (motorb1, HIGH);
      digitalWrite (motorb2, LOW);
      analogWrite (enableb, 190);
    }
    
  else if(val == 'B') // Backward
    {
      digitalWrite (motora1, LOW);
      digitalWrite (motora2, HIGH);
      analogWrite (enablea, 190);
      digitalWrite (motorb1, LOW);
      digitalWrite (motorb2, HIGH);
      analogWrite (enableb, 190); 
    }
  
    else if(val == 'L') //Left
    {
      digitalWrite (motora1, LOW);
      digitalWrite (motora2, HIGH);
      analogWrite (enablea, 190);
      digitalWrite (motorb1, HIGH);
      digitalWrite (motorb2, LOW);
      analogWrite (enableb, 190);
    }

    else if(val == 'R') //Right
    {
      digitalWrite (motora1, HIGH);
      digitalWrite (motora2, LOW);
      analogWrite (enablea, 190);
      digitalWrite (motorb1, LOW);
      digitalWrite (motorb2, HIGH);
      analogWrite (enableb, 190); 
    }
    
    else if(val == 'S') //Stop
    {
      digitalWrite (motora1, LOW);
      digitalWrite (motora2, LOW);
      analogWrite (enablea, 190);
      digitalWrite (motorb1, LOW);
      digitalWrite (motorb2, LOW);
      analogWrite (enableb, 190);
    }

    else if(val == 'O') //Open
    {
      servo.write(70);
    }

    else if(val == 'C') //Close
    {
      servo.write(180);
    }
}
