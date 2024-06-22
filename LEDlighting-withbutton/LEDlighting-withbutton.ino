#define button 8
#define ledr 7
#define ledg 6

int buttoncounter = 0; 
int lastButtonState = LOW; 
unsigned long lastButtonPressTime = 0;

void setup() {
  pinMode(button, INPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
}

void loop() {
  int buttonstatus = digitalRead(button);
  
  if (buttonstatus == HIGH && lastButtonState == LOW) { 
    buttoncounter++;
    lastButtonPressTime = millis(); 
    delay(50);
  }

  lastButtonState = buttonstatus;

  if (millis() - lastButtonPressTime > 3000) {
    digitalWrite(ledg, LOW);
    digitalWrite(ledr, LOW);
  } else {
    if (buttoncounter % 2 == 0) {
      digitalWrite(ledg, HIGH);
      digitalWrite(ledr, LOW);
    } else {
      digitalWrite(ledr, HIGH);
      digitalWrite(ledg, LOW);
    }
  }
}
