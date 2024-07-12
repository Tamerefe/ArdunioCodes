#define butonR A0

unsigned long previousMillis = 0; // Zaman takibi için değişken
const long interval = 1000; // 1 saniye aralık
int score = 0; // Kullanıcının puanı

char direction = ' '; // Rastgele yönü tutmak için değişken, boş olarak başlatılır

void setup() {
  Serial.begin(9600); // Seri iletişimi başlat
  randomSeed(analogRead(0)); // Rastgele sayı üreteci için tohum
  Serial.println("Right and Left Falling Arrows Game");
}

void loop() {
  unsigned long currentMillis = millis(); // Geçerli zaman

  if (currentMillis - previousMillis >= interval) {
    // 2 saniye geçtiyse yeni bir yön üret
    previousMillis = currentMillis;
    direction = random(0, 2) == 0 ? 'a' : 'd'; // Rastgele 'a' veya 'd'
    Serial.print("Direction: ");
    Serial.println(direction == 'a' ? "Right" : "Left");
  }

  int buttonValue = analogRead(butonR);

  // Sağ butonu simüle etmek için
  if (buttonValue >= 1000 && direction == 'd') {
    Serial.println("TRUE! You Earned Points.");
    score++;
    Serial.print("Your Score: ");
    Serial.println(score);
    previousMillis = currentMillis; // Zamanı sıfırla
    direction = ' '; // Yönü boşalt
  }
  
  // Sol butonu simüle etmek için
  if (buttonValue > 0 && buttonValue < 40 && direction == 'a') {
    Serial.println("TRUE! You Earned Points.");
    score++;
    Serial.print("Your Score: ");
    Serial.println(score);
    previousMillis = currentMillis; // Zamanı sıfırla
    direction = ' '; // Yönü boşalt
  }

  // Yanlış butona basıldıysa
  if ((buttonValue >= 1000 && direction == 'a') || (buttonValue > 0 && buttonValue < 40 && direction == 'd')) {
    Serial.println("Wrong key! -1 Point.");
    score--;
    Serial.print("Your Score: ");
    Serial.println(score);
    previousMillis = currentMillis; // Zamanı sıfırla
    direction = ' '; // Yönü boşalt
  }

  delay(50); // Gecikme
}
