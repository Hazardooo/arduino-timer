int anodPins[] = { A1, A2, A3, A4 };
int segmentsPins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int buttonPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(anodPins[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(segmentsPins[i], OUTPUT);
  }
}

//{A, B, C, D, E, F, G,DP} - распиновка сегментов
int seg[10][8] = {
  { 1, 1, 1, 0, 1, 1, 1, 0 },  //Цифра 0
  { 0, 0, 1, 0, 0, 0, 1, 0 },  //Цифра 1
  { 0, 1, 1, 1, 1, 1, 0, 0 },  //Цифра 2
  { 0, 1, 1, 1, 0, 1, 1, 0 },  //Цифра 3
  { 1, 0, 1, 1, 0, 0, 1, 0 },  //Цифра 4
  { 1, 1, 0, 1, 0, 1, 1, 0 },  //Цифра 5
  { 0, 0, 1, 1, 1, 1, 1, 0 },  //Цифра 6
  { 0, 1, 1, 0, 0, 0, 1, 0 },  //Цифра 7
  { 1, 1, 1, 1, 1, 1, 1, 0 },  //Цифра 8
  { 1, 1, 1, 1, 0, 1, 1, 0 }   //Цифра 9
};

int digid = 0;

void loop() {
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  for (int i = 0; i < 4; i++) {    // Каждый разряд по очереди
    for (int k = 0; k < 8; k++) {  // Каждый сегмент по очереди - исходя из заданной карты
      digitalWrite(segmentsPins[k], !seg[digid][k]);
    }
    digitalWrite(anodPins[i], HIGH);
    delay(250);
    digitalWrite(anodPins[i], LOW);
  }
  NextDigid();
}

void NextDigid() {
  if (digid > 9) {
    digid = 0;
  }
  digid++;
}s