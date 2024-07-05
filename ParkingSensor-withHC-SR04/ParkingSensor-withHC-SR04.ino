#define echoPin 6
#define trigPin 7
#define buzzerPin 4

int maxRange = 50;
int minRange = 0;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  
  int measure = range(maxRange,minRange);
  melodyRedDay(measure*10);

}

int range(int maxRange,int minRange){
  
  long duration,distance;
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);
  distance = duration / 58.2;
  delay(50);

  if(distance >= maxRange || distance <= minRange)
  return 0;
  return distance;
}

int melodyRedDay(int dly){

  tone(buzzerPin,660);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
