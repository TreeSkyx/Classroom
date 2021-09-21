#define B1 12
#define B2 11
#define B3 10
#define L1 4
#define L2 3
#define L3 2
// Prototype Function
void redLED(int);
void greenLED(int);
void yellowLED(int);

// Debug Var.
int gState = 0, yState = 0, rState = 0;
int debug = 0;
int light;

//Timer
unsigned long L1delay = 3000, L2delay = 2000, L3delay = 3000;
unsigned long L1past = 0, L2past = 0, L3past = 0, L2b;

// Debounce Var.
int RledState = LOW, GledState = LOW, YledState = LOW;
int RbuttonState, GbuttonState, YbuttonState;
int RlastButtonState = LOW, GlastButtonState = HIGH, YlastButtonState = HIGH;
long RlastDebounceTime = 0, GlastDebounceTime = 0, YlastDebounceTime = 0;
long RdebounceDelay = 50, GdebounceDelay = 50, YdebounceDelay = 50;

void setup() {
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  pinMode(B3, INPUT_PULLUP);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
}
void loop() {
  redLED(digitalRead(B1));
  if (RledState == LOW) {
    greenLED(digitalRead(B3));
  }
  if (RledState == LOW && GledState == LOW) {
    yellowLED(digitalRead(B2));
  }
}
void redLED(int R_reading) {
  if (R_reading != RlastButtonState) {
    RlastDebounceTime = millis();
  }
  if ((millis() - RlastDebounceTime) > RdebounceDelay) {
    if (R_reading != RbuttonState) {
      RbuttonState = R_reading;
      if (RbuttonState == HIGH) {
        L1past = millis();
        RledState = !RledState;
      }
    }
  }
  RlastButtonState = R_reading;
  digitalWrite(L1, RledState);
  if (RledState == HIGH) {
    rState = 1;
  }
  if ((millis() - L1past) >= L1delay) {
    digitalWrite(L1, LOW);
    RledState = LOW;
    rState = 0;
    debug = 0;
  }
}
void greenLED(int G_reading) {
  if (G_reading != GlastButtonState) {
    GlastDebounceTime = millis();
  }
  if ((millis() - GlastDebounceTime) > GdebounceDelay) {
    if (G_reading != GbuttonState) {
      GbuttonState = G_reading;
      if (GbuttonState == LOW) {
        L3past = millis();
        GledState = !GledState;
      }
    }
  }
  GlastButtonState = G_reading;
  digitalWrite(L3, GledState);
  if (GledState == HIGH) {
    gState = 1;
  }
  if (millis() - L3past >= L3delay) {
    digitalWrite(L3, LOW);
    GledState = LOW;
    gState = 0;
  }
}
void yellowLED(int Y_reading) {
  if (Y_reading != YlastButtonState) {
    YlastDebounceTime = millis();
  }
  if ((millis() - YlastDebounceTime) > YdebounceDelay) {
    if (Y_reading != YbuttonState) {
      YbuttonState = Y_reading;
      if (YbuttonState == LOW) {
        YledState = !YledState;
        L2past = millis();
        L2b = millis();
        light = HIGH;
      }
    }
  }
  YlastButtonState = Y_reading;
  if (YledState == HIGH) {
    yState = 1;
  }
  if (yState == 1) {
    digitalWrite(L2, light);
    if ((millis() - L2past) <= 2000) {
      if ((millis() - L2b) >= 500) {
        L2b = millis();
        light = !light;
      }
    }
    else {
      light = HIGH;
      digitalWrite(L2, LOW);
      yState = 0;
      YledState = LOW;
    }
  }
}
