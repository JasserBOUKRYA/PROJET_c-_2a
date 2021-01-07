int pinLED1, pinLED2, pinLED3,pinLED4; 
const int pinbouton1 = A0;
const int pinbouton2 = A1;
int buttonstate1=0;
int buttonstate2=0;
void setup()
{

  //initialisation des variables
  pinLED1 = 2;
  pinLED2 = 4;
  pinLED3 = 5;
  pinLED4 = 6;
  //initialisation des modes
  pinMode(pinbouton1, INPUT_PULLUP);
  pinMode(pinbouton2, INPUT_PULLUP);
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinLED4, OUTPUT);
  //mise à 0V de chaque pin
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, LOW);
  Serial.begin(9600);
}
void loop()
{
  //test allumage et repérage des lEDs
  buttonstate1=digitalRead (pinbouton1);
  buttonstate2=digitalRead (pinbouton2);
  if (buttonstate1== HIGH)
  {
    for (int i = 0; i <= 255; i++)
  {
  digitalWrite(pinLED1, HIGH);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, LOW);
  delay(300);
  digitalWrite(pinLED2, HIGH);
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, LOW);
  delay(300);
  digitalWrite(pinLED3, HIGH);
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED4, LOW);
  delay(300);
  digitalWrite(pinLED4, HIGH);
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
  delay(300);
     digitalWrite(pinLED3, HIGH);
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED4, LOW);
  delay(300);
    digitalWrite(pinLED2, HIGH);
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, LOW);
  delay(300);
      digitalWrite(pinLED1, HIGH);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, LOW);
  delay(300);
  
    }
    digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, LOW);
  }
  else if (buttonstate2== HIGH)
  {
    for (int i = 0; i <= 255; i++)
    {
  digitalWrite(pinLED1, HIGH);
  digitalWrite(pinLED2, HIGH);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, LOW);
  delay(600);
  digitalWrite(pinLED1,LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, HIGH);
  digitalWrite(pinLED4, HIGH);
  delay(600);
    digitalWrite(pinLED1, HIGH);
  digitalWrite(pinLED2, HIGH);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, LOW);
  delay(600);
  
    }
    digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, LOW);
  }
  else 
  Serial.println("OFF");
}
