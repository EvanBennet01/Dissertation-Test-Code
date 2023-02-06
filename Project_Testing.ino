#include <LiquidCrystal.h> //libary used for LCD Screen
int speakerpin = 12; // pin for PWM output   
int freq = 1000;  //freq start value
LiquidCrystal lcd(8, 7, 6, 5, 4, 3); //initate pins for LCD screen

void setup() {
  Serial.begin(9600);
  Serial.println("Begin"); //For Serial Moniter
  pinMode(9, OUTPUT);   // 
  lcd.begin(16, 2);    //start 16*2 display
}
void loop() {
  freqChange(); 
  lcdscreen();
  outputSelection();
}

void freqChange(){

int b1 = digitalRead(10); //check for button press
int b2 = digitalRead(11); //check for button press

if(b1 == HIGH){
      if(freq !=20000){
          freq += 1000;
          Serial.print("Up ");
      }
 }

  if(b2 == HIGH){
      if(freq != 1000){
          freq -= 1000;
          Serial.print("Down");
      }
  }
  tone(speakerpin, freq); //PWM 50% duty output at freq
   Serial.println(freq);
   delay (200); //delay for debounce
}

void outputSelection(){
  digitalWrite(9, HIGH); //Channel 1 select
  Serial.print("Channel 1 (Headphones) " );
  delay (1000); //1 second delay
  digitalWrite(9, LOW); //Channel 0 Select
  Serial.print("Channel 0 (Speaker)  ");
  delay(1000);
}
void lcdscreen(){
  lcd.clear(); //clear last shown
  lcd.print(freq/1000); //display freq in KHz
  lcd.print("KHz ");
}
