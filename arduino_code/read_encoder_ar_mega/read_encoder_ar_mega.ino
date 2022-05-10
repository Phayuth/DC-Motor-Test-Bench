#define ENCA 2
#define ENCB 3

volatile int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
}

void loop() {
  Serial.print(count);
  Serial.println();
}

void readEncoder(){
  int b = digitalRead(ENCB);
  if (b>0){
    count++;
  }
  else{
    count--;
  }
}
