const int led = 32;
const int pot = 25; // ADC Pin required

void setup(){
  Serial.begin(115200);

  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
}
void loop(){
  delay(10);

  int potIndex = analogRead(pot);
  int brightness = map(potIndex, 0, 4095, 0, 255); // 0-255 (8-bit PWM analog range)
  //int brightness = potIndex/4; // Not the best approach but this works similar to "Mapping", (4095 -> 1023)

  Serial.println("BRIGHTNESS: " + String(brightness));
  //delay(1000);

  analogWrite(led, brightness);
}