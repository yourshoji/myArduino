int _moisture,sensor_analog;
const int sensor_pin = A0; //SP

void setup(void){
  Serial.begin(115200); 
}

void loop(void){
  sensor_analog = analogRead(sensor_pin); // analog gives improved accuracy more than digital
  //Serial.println(sensor_analog); // prints out the moisture value in ADC value, ranging from 0-4095 (HIGH to LOW)
  _moisture = ( 100 - ((sensor_analog/4095.00) * 100 ) ); // converts the ADC value into Percentage (the lower the wetter)
  Serial.println("Moisture = " + String(_moisture) + "%");
  delay(3000);              
}

/*
[ ADC Value (Analog-to-Digital Converter) ]
- the maximum value is 4095 (12-bit ADC converter)
*/