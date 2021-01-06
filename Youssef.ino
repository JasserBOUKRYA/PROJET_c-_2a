char data;
int pinBouton;
int etatbouton = 0;
int led = 3;


void setup() {
  // put your setup code here, to run once:
  digitalWrite(led, LOW);
  pinMode(led, OUTPUT);;

  Serial.begin(9600);
}

void loop() {

  if (Serial.available())
  {
    data = Serial.read();
    if (data == '1')
    {
      digitalWrite(led, HIGH);
      Serial.write('1');
    }
    else if (data == '0')
    {
      digitalWrite(led, LOW);
      Serial.write('0');
    }

  }

}
