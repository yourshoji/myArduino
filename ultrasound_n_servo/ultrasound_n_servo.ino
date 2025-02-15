#include <ESP32Servo.h>

#define trigPin 27
#define echoPin 26
#define servoPin 14

Servo myServo;

int default_pos = 90;
int active_pos = -180;

long duration;
int distance;
int threshold = 10; // detect 5cm

void setup(){
  pinMode(trigPin, OUTPUT); // send a pulse
  pinMode(echoPin, INPUT); // receive the pulse
  myServo.attach(servoPin);
  myServo.write(default_pos); // default pos

  Serial.begin(115200);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // send a short pulse to warm up the sensor

  // saves the pulse for further use
  duration = pulseIn(echoPin, HIGH);

  // calculate the distance in cm, divided by 2 cuz we dont want the roundtrip
  distance = (duration/2) / 29.1; 

  if(distance<=threshold){
    Serial.println("Object Detected: " + String(distance) + " cm.");
    myServo.write(active_pos);
    }
  }
  else{
    Serial.println("Distance: " + String(distance) + " cm.");
    myServo.write(default_pos);
  }

  delay(500);
}

