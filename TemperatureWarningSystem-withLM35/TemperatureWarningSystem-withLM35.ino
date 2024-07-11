int lm35Pin = A0;
int led = 8;
#define buzzer 9
int time = 50;
int value = 0;
float voltage = 0;
float heat = 0;

void setup() {

  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}
 
void loop() {

  value = analogRead(lm35Pin);
  voltage = (value / 1023.0)*5000;
  heat = voltage /10.0; 
  Serial.println(heat);
  

  if(heat >= 20){
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(50);
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
    delay(50);
  }
  else{

    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
    
    
  }
}