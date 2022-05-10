#define ENCA 10
#define ENCB 11
#define InterruptA 10
#define InterruptB 11

int32_t count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);
  attachInterrupt(InterruptA, ai10, CHANGE);
  attachInterrupt(InterruptB, ai11, CHANGE);
}

void loop() {
  Serial.print(count);
  Serial.println();
}

void ai10() {
  if (digitalRead(ENCA) == HIGH) {
    if (digitalRead(ENCB) == LOW) {
      count--;
    }
    else {
      count++;
    }
  }
  else {
    if (digitalRead(ENCB) == LOW) {
      count++;
    }
    else {
      count--;
    }
  }
}

void ai11() {
  if (digitalRead(ENCB) == HIGH) {
    if (digitalRead(ENCA) == LOW) {
      count++;
    }
    else {
      count--;
    }
  }
  else {
    if (digitalRead(ENCA) == LOW) {
      count--;
    }
    else {
      count++;
    }
  }
}
