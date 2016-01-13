/**
* Stoves control sketch
* Author: Ruben Miguel Corcoba
* Date: 10/01/2016 
**/

const int amb=25; // Temperature constant
const int RELAY2 = 7; // Relay 2 control pin
int AN4=A4; // Analogic pin 4


void setup() {
  Serial.begin(9600);
  pinMode(RELAY2, OUTPUT);
  pinMode(AN4, INPUT);
}

void loop() {
  // LM35 analogic connection 
  AN4=analogRead(A4);
   
  //Calculate temperature in ºC
  AN4=(AN4*500.0)/1024.0; 

  Serial.println(AN4);
  
  // Check temperature
  if(AN4<amb) {
    // Enable stove
    digitalWrite(RELAY2,HIGH); 
  }
  else {
    // Disable stove
    digitalWrite(RELAY2,LOW); 
  }
  
  // 1 minute delay between temperature checks
  delay(60000); 
}
