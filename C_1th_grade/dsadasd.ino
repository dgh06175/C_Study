#include <Servo.h>

Servo myservo;
int seg[] = {2, 3, 4, 5, 6, 7, 8, 9};
int cds1 = A0;
int cds2 = A1;
int cds3 = A2;

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
   Serial.begin(9600);  
  myservo.attach(13);
  for (int i = 0 ; i < 8 ; i++) {
    pinMode(seg[i], OUTPUT);
  }
}

void loop() {
int cdsValue1 = analogRead(cds1);
int cdsValue2 = analogRead(cds2);
int cdsValue3 = analogRead(cds3);
int angle = 90;
int occupied = 0;

 Serial.print("\n\n\n\n\n\n\n\n\ncds1 =  ");
  Serial.println(cdsValue1);
   Serial.print("\ncds2 =  ");
  Serial.println(cdsValue2);
   Serial.print("\ncds3 =  ");
  Serial.println(cdsValue3);

if(cdsValue1 > 1000)
occupied++;
if(cdsValue2 > 1000)
occupied++;
if(cdsValue3 > 1000)
occupied++;

if(occupied == 0)
{
  angle =90;
  for(int i = 0; i<8; i++)
  digitalWrite(seg[i], digitForNum[3][i]);
}

if(occupied == 1)
{
  angle =90;
  for(int i = 0; i<8; i++)
  digitalWrite(seg[i], digitForNum[2][i]);
}

if(occupied == 2)
{
  angle =90;
  for(int i = 0; i<8; i++)
  digitalWrite(seg[i], digitForNum[1][i]);
}

if(occupied == 3)
{
  angle =160;
  for(int i = 0; i<8; i++)
  digitalWrite(seg[i], digitForNum[0][i]);
}
 myservo.write(angle);
  delay(100);
  }
