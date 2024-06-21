#define ledg 8
#define ledr 7

void setup() {
  pinMode(ledg,OUTPUT);
  pinMode(ledr,OUTPUT);
}

void loop() {
  digitalWrite(ledg,HIGH);
  delay(500);
  digitalWrite(ledg,LOW);
  digitalWrite(ledr,HIGH);
  delay(500);
  digitalWrite(ledr,LOW);

}
