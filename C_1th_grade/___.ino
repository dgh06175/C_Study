#include <Servo.h>

Servo myservo;
int seg[] = {2, 3, 4, 5, 6, 7, 8, 9};

int digitForNum[10][8] = {
  { 1, 1, 1, 1, 1, 1, 0, },/*0*/
  { 0, 1, 1, 0, 0, 0, 0, },/*1*/
  { 1, 1, 0, 1, 1, 0, 1, },/*2*/
  { 1, 1, 1, 1, 0, 0, 1, },/*3*/
  { 0, 1, 1, 0, 0, 1, 1, },/*4*/
  { 1, 0, 1, 1, 0, 1, 1, },/*5*/
  { 1, 0, 1, 1, 1, 1, 1, },/*6*/
  { 1, 1, 1, 0, 0, 1, 0, },/*7*/
  { 1, 1, 1, 1, 1, 1, 1, },/*8*/
  { 1, 1, 1, 1, 0, 1, 1, },/*9*/
  //9
};

void setup() {
  myservo.attach(13);
  for (int i = 0 ; i < 8 ; i++) {
    pinMode(seg[i], OUTPUT);
  }
}

void loop() {
int angle = 90;
myservo.write(angle);
  for (int i = 3 ; i >= 0 ; i--) {
    for (int j = 0 ; j < 8 ; j++) {
      digitalWrite(seg[j], digitForNum[i][j]);
    }
    delay(1000);
  }
  angle =180;
  myservo.write(angle);
  delay(5000);
  }
