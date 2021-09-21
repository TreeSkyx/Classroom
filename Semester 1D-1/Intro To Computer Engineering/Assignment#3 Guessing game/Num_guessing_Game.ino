#define A 5
#define B 4
#define LG 3
#define LR 2
//  Phototype Function
void num_increasing(int);
void guessing(int);
void segmentShow(int);
// Debounce
int buttonStateA, buttonStateB;
int lastButtonStateA = HIGH, lastButtonStateB = HIGH;
unsigned long lastDebounceTimeA = 0, lastDebounceTimeB = 0;
unsigned long debounceDelay = 50;
//  Number and Status
int num = 0;
int gstat = 0;
int randomN;
//  Number Pattern
const int BitPattern[13] = {B11111001, B10100100, B10110000, B10011001, B10010010, B10000010, B11111000, B10000000, B10010000, // 1-9
                            B11000000, B11000111, B11000010, B11111111};  // 0-L-G-OFF
//  7seg. PIN
const int segmentPins[8] = {13, 12, 11, 10, 9, 8, 7, 6}; //  A-G + DP

void setup() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(LR, OUTPUT);
  pinMode(LG, OUTPUT);
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  randomSeed(analogRead(A0));
  randomN = random(1, 10);
}

void loop() {
  num_increasing(digitalRead(A));
  guessing(digitalRead(B));
}
void num_increasing(int reading) {
  if (reading != lastButtonStateA) {
    lastDebounceTimeA = millis();
  }
  if ((millis() - lastDebounceTimeA) > debounceDelay) {
    if (reading != buttonStateA) {
      buttonStateA = reading;

      if (buttonStateA == LOW) {
        num = num + 1;
      }
    }
  }
  lastButtonStateA = reading;
  if (num > 8)num = 0;
  segmentShow(num);
}
void guessing(int reading) {
  if (reading != lastButtonStateB) {
    lastDebounceTimeB = millis();
  }
  if ((millis() - lastDebounceTimeB) > debounceDelay) {
    if (reading != buttonStateB) {
      buttonStateB = reading;

      if (buttonStateB == LOW) {
        gstat = 1;
      }
    }
  }
  lastButtonStateB = reading;
  if (gstat == 1) {
    if (num == randomN) {
      bool isBitSet;
      digitalWrite(LG,HIGH);
      segmentShow(12);
        for (int segment = 0; segment < 8; segment++) {
        isBitSet = bitRead(BitPattern[9], segment);
        digitalWrite(segmentPins[segment], isBitSet);
        delay(150);
        }
      gstat = 0;
      digitalWrite(LG,LOW);
      randomN = random(1, 9);
      num = 0;
    }
    else if (num < randomN) {
      digitalWrite(LR,HIGH);
      segmentShow(10);
      delay(1000);
      digitalWrite(LR,LOW);
      gstat = 0;
    }
    else if (num > randomN) {
      digitalWrite(LR,HIGH);
      segmentShow(11);
      delay(1000);
      digitalWrite(LR,LOW);
      gstat = 0;
    
    } 
  }
}
void segmentShow(int x){
  boolean isBitSet;
  for (int segment = 0; segment < 8; segment++) {
        isBitSet = bitRead(BitPattern[x], segment);
        digitalWrite(segmentPins[segment], isBitSet);
  }
}
