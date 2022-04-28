#define ENCA 2
#define ENCB 3

#define mt_Rpwm_pin 8
#define mt_Lpwm_pin 9

void forward() {
  analogWrite(mt_Rpwm_pin, 150);
  analogWrite(mt_Rpwm_pin, 0);
}

void backward() {
  analogWrite(mt_Rpwm_pin, 0);
  analogWrite(mt_Rpwm_pin, 150);
}

void still() {
  analogWrite(mt_Rpwm_pin, 0);
  analogWrite(mt_Rpwm_pin, 0);
}

volatile int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(mt_Rpwm_pin, OUTPUT);
  pinMode(mt_Lpwm_pin, OUTPUT);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
}

void loop() {
  forward();
  Serial.print(count);
  Serial.println();
}

void readEncoder() {
  int b = digitalRead(ENCB);
  if (b > 0) {
    count++;
  }
  else {
    count--;
  }
}
