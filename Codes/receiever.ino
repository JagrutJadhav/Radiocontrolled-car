#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define button 4
RF24 radio(10, 9); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
Servo myServo;
boolean buttonState = 0;

int in1 =8;
int in2 =7;
int motor=6;
int servo=3;

void setup() {
  pinMode(button, INPUT);
  myServo.attach(3);
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(motor,OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    while (radio.available()) {
      int pwm = 0;
      radio.read(&pwm, sizeof(pwm));
      Serial.println(pwm);
      
      analogWrite(motor,pwm);
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
    }
    delay(5);
  }
}
