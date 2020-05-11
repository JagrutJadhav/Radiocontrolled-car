#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define led 12
RF24 radio(10, 9); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
boolean buttonState = 0;
void setup() {
  pinMode(12, OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00002
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
  Serial.begin(9600);
}
void loop() {
  delay(2);
  radio.stopListening();
  int potValue = analogRead(A0);
  int x=analogRead(A1);
  int y=analogRead(A2);
  int pot = map(potValue, 0, 885, 0, 255);
  //Serial.println(pot);
  //radio.write(&pot, sizeof(pot));

 if(y>=430 && y<= 470 && x>=420 && x<= 470)
 {
  pot = 1234;//c
 radio.write(&pot, sizeof(pot));
  Serial.println(pot);

 }
 else if(y>=471 && x>=100 && x<= 670)
 {
  pot = 4312;//L
 //radio.write(&pot, sizeof(pot));
  Serial.println(pot);

 }
 else if(y<= 429 && x>=100 && x<= 670)
 {
  pot = 2341;//r
 radio.write(&pot, sizeof(pot));
  Serial.println(pot);
 }
 else if(x>= 471 && y>=100 && y<= 670)
 {
 pot = 3214;//b
 radio.write(&pot, sizeof(pot));
 Serial.println(pot);
 }
  //Serial.println(y);
  
  delay(2);
  
  
}
