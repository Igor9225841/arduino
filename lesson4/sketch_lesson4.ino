const int SER=8;     //Выход данных (14)
const int LATCH=9;   //Выход защелка (12)
const int CLK=10;    //Выход тактового сигнала (11)
unsigned int randNumber=0;   //случайное число
int pwm = 6;         //Выход ШИМ к OE 74hc595 (13)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(pwm, OUTPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  randNumber= random (255);
  digitalWrite (LATCH, LOW);
  shiftOut (SER, CLK, MSBFIRST, randNumber);
  digitalWrite (LATCH, HIGH);
  randNumber= random (255);
  for (int i=0; i < randNumber; i++)
  {
    analogWrite (pwm, i);
    delay (2);
  }
  Serial.println(randNumber);
  
}
