#define trigPin 27
#define echoPin 26
#define buzzer 25

long duration;
int distance;
int threshold = 10; // detect 5cm

void setup(){
  pinMode(trigPin, OUTPUT); // send a pulse
  pinMode(echoPin, INPUT); // receive the pulse

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
    tone(buzzer, 4000, 5000); // pin, hz, duration
  }
  else{
    Serial.println("Distance: " + String(distance) + " cm.");
  }

  delay(500);
}

