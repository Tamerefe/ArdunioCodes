#define ledr 7
#define ledb 6

void setup() {
  pinMode(ledb,OUTPUT);
  pinMode(ledr,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(A0);
  Serial.println(light);
  if(light < 60){
    digitalWrite(ledr,HIGH);
    digitalWrite(ledb,HIGH);
  }else{
    digitalWrite(ledr,LOW);
    digitalWrite(ledb,LOW);
  }

}
