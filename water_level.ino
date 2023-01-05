int level_1   = 7;
int level_2   = 8;
int level_3   = 9;
int motor     = 2;
int red       = 6;
int yellow    = 5;
int green     = 4;
int beep     = 3;
int state = 1;

int low;
int medium;
int high;

void setup()
{
  Serial.begin(9600);
  pinMode(level_1, INPUT_PULLUP);
  pinMode(level_2, INPUT_PULLUP);
  pinMode(level_3, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(beep, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);

} void loop()
{
  low = digitalRead(level_1);
  medium = digitalRead(level_2);
  high = digitalRead(level_3);

  if (low == LOW) {
    digitalWrite(red, HIGH);
    digitalWrite(motor, HIGH);
    if(medium==LOW){
      if (state == 1) {
      for (int i = 0; i < 5; i++) {
        digitalWrite(beep, HIGH);
        delay(300);
        digitalWrite(beep, LOW);
      }
      state = 2;
    }}
  }
  else {
    digitalWrite(red, LOW);
    digitalWrite(motor, LOW);

  }
  if (medium == LOW) {
    digitalWrite(yellow, HIGH);


  }   else {
    digitalWrite(yellow, LOW);

  } if (high == LOW) {
    digitalWrite(green, HIGH);
    digitalWrite(motor, LOW);

    if (state == 2) {
      for (int i = 0; i < 2; i++) {
        digitalWrite(beep, HIGH);
        delay(600);
        digitalWrite(beep, LOW);
      }
      state = 1;
    }
  } else {
    digitalWrite(green, LOW);

  }




  Serial.print("low =");
  Serial.print(low);
  Serial.print("    medium =");
  Serial.print(medium);
  Serial.print("    high =");
  Serial.println(high);
  delay(100);

}
