/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

int TIMEOUT = 300;

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pinPresenceSensor = 2;
int led = 3;
int count = TIMEOUT;
String message = "";


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pinPresenceSensor, INPUT);
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  if (presenceDetected()){
    message = "Um filho da puta entrou na sala: ";
    digitalWrite(led,HIGH);
  } else {
     message = "Sala vazia:";
     digitalWrite(led,LOW);
  }  
  
  Serial.println(message + count);
 
  delay(50); // delay in between reads for stability
}


boolean presenceDetected(){
  int presenceState = digitalRead(pinPresenceSensor);
  
  //presence
  if (presenceState == 1) {
     count = TIMEOUT;
    return true;
  }
  
  //timeout control
  if (count > 0) { 
     count--;
     return true;
  }
    
  return false;
}

