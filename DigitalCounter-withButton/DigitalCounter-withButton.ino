int topright = 2;
int topright2 = 4;
int topleft = 5;
int toprleft2 = 6;

#define button 7

int bottomright = 8;
int bottomright2 = 9;
int bottomleft = 12;
int bottomleft2 = 13;
int count = 0;

unsigned long lastDebounceTime = 0; // Son debouncing zamanı
unsigned long debounceDelay = 50; // Debouncing için bekleme süresi
int lastButtonState = LOW; // Butonun önceki durumu

void setup() {
  pinMode(button, INPUT);
  pinMode(topright, OUTPUT);
  pinMode(topright2, OUTPUT);
  pinMode(topleft, OUTPUT);
  pinMode(toprleft2, OUTPUT);
  pinMode(bottomright, OUTPUT);
  pinMode(bottomright2, OUTPUT);
  pinMode(bottomleft, OUTPUT);
  pinMode(bottomleft2, OUTPUT);
}

void loop() {
  int reading = digitalRead(button);
  
  // Eğer buton durumu değiştiyse (yükselen kenar)
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  // Eğer debouncing süresi geçtiyse ve buton durumu değiştiyse
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == HIGH) {
      count++;
      if (count > 9) {
        count = 0;
      }
    }
  }

  lastButtonState = reading; // Butonun önceki durumu güncelleniyor

  switch(count) {
    case 0:
      digitalWrite(topright, LOW);
      digitalWrite(topright2, LOW);
      digitalWrite(topleft, LOW);
      digitalWrite(toprleft2, HIGH);
      digitalWrite(bottomright, HIGH);
      digitalWrite(bottomright2, LOW);
      digitalWrite(bottomleft, LOW);
      digitalWrite(bottomleft2, LOW);
      break;
    case 1:
      digitalWrite(topright, LOW);
      digitalWrite(topright2, HIGH);
      digitalWrite(topleft, HIGH);
      digitalWrite(toprleft2, HIGH);
      digitalWrite(bottomright, HIGH);
      digitalWrite(bottomright2, LOW);
      digitalWrite(bottomleft, HIGH);
      digitalWrite(bottomleft2, HIGH);
      break;
    case 2:
      digitalWrite(topright, LOW);
      digitalWrite(topright2, LOW);
      digitalWrite(topleft, HIGH);
      digitalWrite(toprleft2, LOW);
      digitalWrite(bottomright, HIGH);
      digitalWrite(bottomright2, HIGH);
      digitalWrite(bottomleft, LOW);
      digitalWrite(bottomleft2, LOW);
      break;
    case 3:
      digitalWrite(topright, LOW);
      digitalWrite(topright2, LOW);
      digitalWrite(topleft, HIGH);
      digitalWrite(toprleft2, LOW);
      digitalWrite(bottomright, LOW);
      digitalWrite(bottomright2, LOW);
      digitalWrite(bottomleft, LOW);
      digitalWrite(bottomleft2, HIGH);
      break;
    case 4:
      digitalWrite(topright, LOW);
      digitalWrite(topright2, HIGH);
      digitalWrite(topleft, LOW);
      digitalWrite(toprleft2, LOW);
      digitalWrite(bottomright, LOW);
      digitalWrite(bottomright2, LOW);
      digitalWrite(bottomleft, HIGH);
      digitalWrite(bottomleft2, HIGH);
      break;
    case 5:
      digitalWrite(topright, HIGH);
      digitalWrite(topright2, LOW);
      digitalWrite(topleft, LOW);
      digitalWrite(toprleft2, LOW);
      digitalWrite(bottomright, LOW);
      digitalWrite(bottomright2, LOW);
      digitalWrite(bottomleft, LOW);
      digitalWrite(bottomleft2, HIGH);
      break;
    case 6:
      digitalWrite(topright, HIGH);
      digitalWrite(topright2, LOW);
      digitalWrite(topleft, LOW);
      digitalWrite(toprleft2, LOW);
      digitalWrite(bottomright, LOW);
      digitalWrite(bottomright2, LOW);
      digitalWrite(bottomleft, LOW);
      digitalWrite(bottomleft2, LOW);
      break;
    case 7:
      digitalWrite(topright, LOW);
      digitalWrite(topright2, LOW);
      digitalWrite(topleft, LOW);
      digitalWrite(toprleft2, HIGH);
      digitalWrite(bottomright, HIGH);
      digitalWrite(bottomright2, LOW);
      digitalWrite(bottomleft, HIGH);
      digitalWrite(bottomleft2, HIGH);
      break;
    case 8:
      digitalWrite(topright, LOW);
      digitalWrite(topright2, LOW);
      digitalWrite(topleft, LOW);
      digitalWrite(toprleft2, LOW);
      digitalWrite(bottomright, LOW);
      digitalWrite(bottomright2, LOW);
      digitalWrite(bottomleft, LOW);
      digitalWrite(bottomleft2, LOW);
      break;
    case 9:
      digitalWrite(topright, LOW);
      digitalWrite(topright2, LOW);
      digitalWrite(topleft, LOW);
      digitalWrite(toprleft2, LOW);
      digitalWrite(bottomright, LOW);
      digitalWrite(bottomright2, LOW);
      digitalWrite(bottomleft, LOW);
      digitalWrite(bottomleft2, HIGH);
      break;
    default:
      break;
  }
}
