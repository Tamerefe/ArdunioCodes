#define potpin A0
#define led 3

void setup() {
 
}

void loop() {  
  
  int value = analogRead(potpin);
  value = map(value,0,1023,0,255);
  analogWrite(led,value);

}
