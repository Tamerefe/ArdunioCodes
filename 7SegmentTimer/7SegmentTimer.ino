// Define the pins for the segments of the 7-segment display
int PinA = 3;
int PinB = 7;
int PinC = 10;
int PinD = 12;
int PinE = 13;
int PinF = 4;
int PinG = 9;

// Define the pins for each digit of the 4-digit display
int Segment1 = 2;
int Segment2 = 5;
int Segment3 = 6;
int Segment4 = 8;

int number;
int thousands = 0;
int hundreds = 0;
int tens = 0;
int units = 0;
int delayTime = 5;

void setup() {
  // Set the segment pins as outputs
  pinMode(PinA, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(PinC, OUTPUT);
  pinMode(PinD, OUTPUT);
  pinMode(PinE, OUTPUT);
  pinMode(PinF, OUTPUT);
  pinMode(PinG, OUTPUT);
  
  // Set the digit pins as outputs
  pinMode(Segment1, OUTPUT);
  pinMode(Segment2, OUTPUT);
  pinMode(Segment3, OUTPUT);
  pinMode(Segment4, OUTPUT);
}

void loop() {
  // Turn off all digits
  digitalWrite(Segment1, LOW);
  digitalWrite(Segment2, LOW);
  digitalWrite(Segment3, LOW);
  digitalWrite(Segment4, LOW);

  // Loop through numbers from 0 to 9999
  for (int number = 0; number < 10000; number++) {
    // Extract each digit
    units = number % 10;
    tens = (number / 10) % 10;
    hundreds = (number / 100) % 10;
    thousands = (number / 1000) % 10;

    // Display units place
    digitalWrite(Segment4, HIGH);
    displayDigit(units);
    delay(delayTime);
    digitalWrite(Segment4, LOW);

    // Display tens place
    digitalWrite(Segment3, HIGH);
    displayDigit(tens);
    delay(delayTime);
    digitalWrite(Segment3, LOW);

    // Display hundreds place
    digitalWrite(Segment2, HIGH);
    displayDigit(hundreds);
    delay(delayTime);
    digitalWrite(Segment2, LOW);

    // Display thousands place
    digitalWrite(Segment1, HIGH);
    displayDigit(thousands);
    delay(delayTime);
    digitalWrite(Segment1, LOW);
  }
}

// Function to display a digit on the 7-segment display
void displayDigit(int x) {
  switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    default: zero(); break;
  }
}

void one() {
  digitalWrite(PinA, HIGH);
  digitalWrite(PinB, LOW);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, HIGH);
  digitalWrite(PinE, HIGH);
  digitalWrite(PinF, HIGH);
  digitalWrite(PinG, HIGH);
}

void two() {
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
  digitalWrite(PinC, HIGH);
  digitalWrite(PinD, LOW);
  digitalWrite(PinE, LOW);
  digitalWrite(PinF, HIGH);
  digitalWrite(PinG, LOW);
}

void three() {
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, LOW);
  digitalWrite(PinE, HIGH);
  digitalWrite(PinF, HIGH);
  digitalWrite(PinG, LOW);
}

void four() {
  digitalWrite(PinA, HIGH);
  digitalWrite(PinB, LOW);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, HIGH);
  digitalWrite(PinE, HIGH);
  digitalWrite(PinF, LOW);
  digitalWrite(PinG, LOW);
}

void five() {
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, HIGH);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, LOW);
  digitalWrite(PinE, HIGH);
  digitalWrite(PinF, LOW);
  digitalWrite(PinG, LOW);
}

void six() {
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, HIGH);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, LOW);
  digitalWrite(PinE, LOW);
  digitalWrite(PinF, LOW);
  digitalWrite(PinG, LOW);
}

void seven() {
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, HIGH);
  digitalWrite(PinE, HIGH);
  digitalWrite(PinF, HIGH);
  digitalWrite(PinG, HIGH);
}

void eight() {
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, LOW);
  digitalWrite(PinE, LOW);
  digitalWrite(PinF, LOW);
  digitalWrite(PinG, LOW);
}

void nine() {
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, LOW);
  digitalWrite(PinE, HIGH);
  digitalWrite(PinF, LOW);
  digitalWrite(PinG, LOW);
}

void zero() {
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, LOW);
  digitalWrite(PinE, LOW);
  digitalWrite(PinF, LOW);
  digitalWrite(PinG, HIGH);
}