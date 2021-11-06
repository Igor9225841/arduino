const int POT=0;
unsigned int val=0;
int ledpin=3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
 }

void loop() {
  // put your main code here, to run repeatedly:
  val= analogRead(POT);
  analogWrite(ledpin, val/4);
  Serial.println(val);
  delay(100);
}
