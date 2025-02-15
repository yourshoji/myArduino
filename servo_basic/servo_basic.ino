#include <ESP32Servo.h>

int pos = 0;

Servo myServo;

void setup() {
  Serial.begin(115200);
  myServo.attach(14);

}

void loop() {
  for(pos=0; pos<=180; pos+=1){
    myServo.write(pos);
    delay(10);
  }
    for(pos=180; pos>=0; pos-=1){
    myServo.write(pos);
    delay(10);
  }
  
  Serial.println(pos);
  delay(10);
}
