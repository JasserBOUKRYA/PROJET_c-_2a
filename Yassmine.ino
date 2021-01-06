int bouton = 2;
int led = 3;

int etatbouton = 0; 
int dernieretatbouton = 0;
int etatled = 0;
char data;
void setup() {

  pinMode(bouton, INPUT_PULLUP);
  digitalWrite(led, LOW);
  pinMode(led, OUTPUT);
  Serial.begin (9600);
}

void loop() {

  data = Serial.read();

  etatbouton = digitalRead(bouton);

  if (etatbouton != dernieretatbouton) {

    if (!etatbouton) {

      if ((etatled == 1) || (data =='0'))
      {
        etatled = 0;
        Serial.write('0');
      }
      else
      {
        etatled = 1;
        Serial.write('1');
      }
    }
    dernieretatbouton = etatbouton;
  }
  Serial.println (etatled);
  digitalWrite(led, etatled);
  delay(20);
}
