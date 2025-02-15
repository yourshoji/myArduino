#define bt 34
#define led 26
byte ledState = LOW;
byte lastState = LOW;

void setup(){
  pinMode(bt, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(115200);
}

void loop(){
  delay(10);
  int buttonInput = digitalRead(bt); // save the button input
  if(buttonInput != lastState){
    lastState = buttonInput; // save the last button state
    if(buttonInput==LOW){ // the section where on and off occurs
      ledState = (ledState==HIGH) ? LOW: HIGH; // ledState saves the states if ledState is HIGH, if true LED off, if false LED on;
      digitalWrite(led, ledState);
    }
  }
}