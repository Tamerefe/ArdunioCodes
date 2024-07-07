#define pin1 9
#define pin2 10
#define pin3 11
#define pin4 12

int location;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  location = 9;
}

void loop() {
  turnR(500);
  delay(1000);
  turnL(800);
  delay(1000);
  turnR(300);
  delay(1000);
  turnL(1000);
}

void turnR(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(location, HIGH);
    delay(10);
    digitalWrite(location, LOW);
    location++;
    if (location > pin4) {
      location = pin1;
    }
  }
}

void turnL(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(location, HIGH);
    delay(10);
    digitalWrite(location, LOW);
    location--;
    if (location < pin1) {
      location = pin4;
    }
  }
}
