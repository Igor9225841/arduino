const int POT=0;
unsigned int val=0, val_led=0;
int led_pin1=2, led_pin2=3, led_pin3=4, led_pin4=5, led_pin5=6;
int    led_pin6=7, led_pin7=8, led_pin8=9, led_pin9=10, led_pin10=11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT);
  pinMode(led_pin7, OUTPUT);
  pinMode(led_pin8, OUTPUT);
  pinMode(led_pin9, OUTPUT);
  pinMode(led_pin10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val= analogRead(POT);
  val_led= map(val, 0, 1023, 0, 9);
  switch (val_led)
  {
    case 0:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, LOW);
     digitalWrite(led_pin3, LOW);
     digitalWrite(led_pin4, LOW);
     digitalWrite(led_pin5, LOW);
     digitalWrite(led_pin6, LOW);
     digitalWrite(led_pin7, LOW);
     digitalWrite(led_pin8, LOW);
     digitalWrite(led_pin9, LOW);
     digitalWrite(led_pin10, LOW);
    break;
    case 1:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, HIGH);
     digitalWrite(led_pin3, LOW);
     digitalWrite(led_pin4, LOW);
     digitalWrite(led_pin5, LOW);
     digitalWrite(led_pin6, LOW);
     digitalWrite(led_pin7, LOW);
     digitalWrite(led_pin8, LOW);
     digitalWrite(led_pin9, LOW);
     digitalWrite(led_pin10, LOW);
    break;
    case 2:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, HIGH);
     digitalWrite(led_pin3, HIGH);
     digitalWrite(led_pin4, LOW);
     digitalWrite(led_pin5, LOW);
     digitalWrite(led_pin6, LOW);
     digitalWrite(led_pin7, LOW);
     digitalWrite(led_pin8, LOW);
     digitalWrite(led_pin9, LOW);
     digitalWrite(led_pin10, LOW);
    break;
    case 3:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, HIGH);
     digitalWrite(led_pin3, HIGH);
     digitalWrite(led_pin4, HIGH);
     digitalWrite(led_pin5, LOW);
     digitalWrite(led_pin6, LOW);
     digitalWrite(led_pin7, LOW);
     digitalWrite(led_pin8, LOW);
     digitalWrite(led_pin9, LOW);
     digitalWrite(led_pin10, LOW);
    break;
    case 4:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, HIGH);
     digitalWrite(led_pin3, HIGH);
     digitalWrite(led_pin4, HIGH);
     digitalWrite(led_pin5, HIGH);
     digitalWrite(led_pin6, LOW);
     digitalWrite(led_pin7, LOW);
     digitalWrite(led_pin8, LOW);
     digitalWrite(led_pin9, LOW);
     digitalWrite(led_pin10, LOW);
    break;
    case 5:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, HIGH);
     digitalWrite(led_pin3, HIGH);
     digitalWrite(led_pin4, HIGH);
     digitalWrite(led_pin5, HIGH);
     digitalWrite(led_pin6, HIGH);
     digitalWrite(led_pin7, LOW);
     digitalWrite(led_pin8, LOW);
     digitalWrite(led_pin9, LOW);
     digitalWrite(led_pin10, LOW);
    break;
    case 6:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, HIGH);
     digitalWrite(led_pin3, HIGH);
     digitalWrite(led_pin4, HIGH);
     digitalWrite(led_pin5, HIGH);
     digitalWrite(led_pin6, HIGH);
     digitalWrite(led_pin7, HIGH);
     digitalWrite(led_pin8, LOW);
     digitalWrite(led_pin9, LOW);
     digitalWrite(led_pin10, LOW);
    break;
    case 7:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, HIGH);
     digitalWrite(led_pin3, HIGH);
     digitalWrite(led_pin4, HIGH);
     digitalWrite(led_pin5, HIGH);
     digitalWrite(led_pin6, HIGH);
     digitalWrite(led_pin7, HIGH);
     digitalWrite(led_pin8, HIGH);
     digitalWrite(led_pin9, LOW);
     digitalWrite(led_pin10, LOW);
    break;
    case 8:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, HIGH);
     digitalWrite(led_pin3, HIGH);
     digitalWrite(led_pin4, HIGH);
     digitalWrite(led_pin5, HIGH);
     digitalWrite(led_pin6, HIGH);
     digitalWrite(led_pin7, HIGH);
     digitalWrite(led_pin8, HIGH);
     digitalWrite(led_pin9, HIGH);
     digitalWrite(led_pin10, LOW);
    break;
    case 9:
     digitalWrite(led_pin1, HIGH);
     digitalWrite(led_pin2, HIGH);
     digitalWrite(led_pin3, HIGH);
     digitalWrite(led_pin4, HIGH);
     digitalWrite(led_pin5, HIGH);
     digitalWrite(led_pin6, HIGH);
     digitalWrite(led_pin7, HIGH);
     digitalWrite(led_pin8, HIGH);
     digitalWrite(led_pin9, HIGH);
     digitalWrite(led_pin10, HIGH);
    break;
  }
  Serial.println(val);
  delay(100);
}
