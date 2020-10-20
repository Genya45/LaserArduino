/*
  //sound1
  //#define note0 82
  //#define note1 98
  //#define note2 110
  //#define note3 117
  //#define note4 0

  //sound2
  //#define note0 330
  //#define note1 415
  //#define note2 440
  //#define note3 494
  //#define note4 523

  //sound3
  //#define note0 247
  //#define note1 262
  //#define note2 294
  //#define note3 196
  //#define note4 220

*/

#define tonePin 13
#define lightLevel 200

int sensorValue[5];
int note[] = {82, 98, 110, 117, 1000}; //sound1
//int note[] = {330,415,440,494,523}; //sound2
//int note[] = {247,262,294,196,220}; //sound3

void setup() {
  Serial.begin(9600);
  pinMode(tonePin, 1);
}

void loop() {

  sensorValue[0] = analogRead(A0);
  sensorValue[1] = analogRead(A1);
  sensorValue[2] = analogRead(A2);
  sensorValue[3] = analogRead(A3);
  sensorValue[4] = analogRead(A4);

  for (int i = 0; i < 5; i++) {
    Serial.print(sensorValue[i]);
    Serial.print("    ");
  }
  Serial.println("");

  /*
    if (sensorValue0 > 200) {
      tone(tonePin, note[0]);
    }
    else if (sensorValue[1] > lightLevel) {
      tone(tonePin, note[1]);
    }
    else if (sensorValue[2] > lightLevel) {
      tone(tonePin, note[2]);
    }
    else if (sensorValue[3] > lightLevel) {
      tone(tonePin, note[3]);
    }
    else  if (sensorValue[4] > lightLevel) {
      tone(tonePin, note[4]);
    }
    else {
      noTone(tonePin);
    }
  */


  boolean flagLevel = false;
  for (int i = 0; i < 5; i++) {
    if (sensorValue[i] > lightLevel)
      flagLevel = true;
  }
  if (flagLevel) {
    if (sensorValue[0] > 200) {
      tone(tonePin, note0);
    }
    if (sensorValue[1] > lightLevel) {
      tone(tonePin, note1);
    }
    if (sensorValue[2] > lightLevel) {
      tone(tonePin, note2);
    }
    if (sensorValue[3] > lightLevel) {
      tone(tonePin, note3);
    }
    if (sensorValue[4] > lightLevel) {
      tone(tonePin, note4);
    }
  }
  else {
    noTone(tonePin);
  }
}
