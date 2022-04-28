#define mt_Rpwm_pin 8
#define mt_Lpwm_pin 9

void forward(){
  analogWrite(mt_Rpwm_pin, 150);
  analogWrite(mt_Rpwm_pin, 0);
}

void backward(){
  analogWrite(mt_Rpwm_pin, 0);
  analogWrite(mt_Rpwm_pin, 150);
}

void still(){
  analogWrite(mt_Rpwm_pin, 0);
  analogWrite(mt_Rpwm_pin, 0);
}

void setup() {
  pinMode(mt_Rpwm_pin,OUTPUT);
  pinMode(mt_Lpwm_pin,OUTPUT);
}

void loop() {
 forward();
 delay(10000);
 still();
 delay(2000);
 backward();
 delay(10000);
}
