#include "LedControl.h"
#include <EEPROM.h>
#define SETTING_B 2
#define HOUR_B 4
#define MINUTE_B 3
#define LDR_PIN A0 
LedControl lc = LedControl(11, 13, 10, 4); // DIN,CLK,CS,Number of LED Module

// Time
unsigned int second = 0,minute = 0,hour=0;
int timer1_counter;
unsigned int aMinute=0,aHour=0;
int se = 0,ho = 0,mi = 0;
int set=0;
int sS =0;
int sH =0;
int sM =0;

// Alarm & State
bool ring = false, alarm = false, stopp = true;

// Debounce
int lastSetting;
int lastHour;
int lastMin;

// Speaker
int speakerPin = 6;

// EEPROM 
int eeAddress = 0;

// LED Matrix Display {0-9,S,E,T,A,L,M,clock,bell,I}
const uint64_t IMAGES[]{ 
  0x1c2222222222221c,
  0x1c08080808080c08,
  0x3e0408102020221c,
  0x1c2220201820221c,
  0x20203e2224283020,
  0x1c2220201e02023e,
  0x1c2222221e02221c,
  0x040404081020203e,
  0x1c2222221c22221c,
  0x1c22203c2222221c,
  0x3c66603c06663c00,
  0x7e06063e06067e00,
  0x18181818185a7e00,
  0x6666667e66663c00,
  0x7e06060606060600,
  0x6363636b7f776300,
  0x7f41594949417f00,
  0x187e3c3cbd994200,
  0x7e5a1818185a7e00
};
const int IMAGES_LEN = sizeof(IMAGES)/8;

void SettingB(int reading) // Setting button debounce
{
  if(reading!=se)
      lastSetting=millis();

    if(millis()-lastSetting>25)
    {
      if(sS!=reading){
          sS=reading;
        if(sS==1)
        {
          if(stopp)
          {
          Serial.println("Setting"); // set change
          set++;
          Serial.println(set);
          if(set==1){ // Time Setting 
            lc.clearDisplay(2);
            tone(speakerPin, 294);
            displayNumber(IMAGES[10],3);
            displayNumber(IMAGES[11],2);
            displayNumber(IMAGES[12],1);
            displayNumber(IMAGES[16],0);
            delay(1000);
            noTone(speakerPin);
            dot();
          }
          if(set==2){ // Alarm Setting
            lc.clearDisplay(2);
            tone(speakerPin, 349);
            displayNumber(IMAGES[13],3);
            displayNumber(IMAGES[14],2);
            displayNumber(IMAGES[15],1);
            displayNumber(IMAGES[17],0);
            delay(1000);
            noTone(speakerPin);
            dot();
          }
          if(set==3){ // Normal Time
            lc.clearDisplay(2);
            tone(speakerPin, 392);
            displayNumber(IMAGES[12],3);
            displayNumber(IMAGES[18],2);
            displayNumber(IMAGES[15],1);
            displayNumber(IMAGES[11],0);
            delay(1000);
            noTone(speakerPin);
            dot();
            set=0;
            EEPROM.put(eeAddress, hour);
            EEPROM.put(sizeof(hour), minute);
            EEPROM.put(sizeof(hour)+sizeof(minute), aHour);
            EEPROM.put(sizeof(hour)+sizeof(minute)+sizeof(aHour), aMinute);
            Serial.println("Written Time & Alarm to EEPROM!");
          }
            
          }
          else
          {
            ring=false;
            stopp=true;
          }
        }
      }
    }
  se=reading;
}
void HourB(int reading) // Hour button debounce
{
  if(reading!=ho)
      lastHour=millis();
      
    if(millis()-lastHour>25)
    {
      if(sH!=reading)
      {
          sH=reading;
        if(sH==1&&set==1)
        {
          hour++;
          second=0;
          if(hour>=25)
            hour=0;
          Serial.print("Set Hour ");
          Serial.print(hour);
          Serial.print(" Min ");
          Serial.println(minute);
        }
        if(sH==1&&set==2)
        {
          alarm = true;
          aHour++;
          if(aHour>=25)
            aHour=0;
          Serial.print("Set Alarm Hour ");
          Serial.print(aHour);
          Serial.print(" Min ");
          Serial.println(aMinute);
        }
      }
    }
  ho=reading;
}
void MinB(int reading) // Minute buttton debounce
{
  if(reading!=mi)
      lastMin=millis();
      
    if(millis()-lastMin>25)
    {
      if(sM!=reading)
      {
          sM=reading;
        if(sM==1&&set==1)
        {
          minute++;
          second=0;
          if(minute>=60)
            minute=0;
          Serial.print("Set Hour ");
          Serial.print(hour);
          Serial.print(" Min ");
          Serial.println(minute);
        }
        if(sM==1&&set==2)
        {
          alarm = true;
          aMinute++;
          if(aMinute>=60)
            aMinute=0;
          Serial.print("Set Alarm Hour ");
          Serial.print(aHour);
          Serial.print(" Min ");
          Serial.println(aMinute);
        }
      }
    }
  mi=reading;
}

void setup(){
  Serial.begin(9600);
  Serial.print("Read Time & Alarm from EEPROM: "); // Read Time from EEPROM
  EEPROM.get(eeAddress, hour);
  EEPROM.get(sizeof(hour), minute);
  EEPROM.get(sizeof(hour)+sizeof(minute), aHour);
  EEPROM.get(sizeof(hour)+sizeof(minute)+sizeof(aHour), aMinute);

  // Timer Debug
  Serial.print("Time : ");
  Serial.print(hour);
  Serial.print(":");
  Serial.println(minute);
  Serial.print("Alarm : ");
  Serial.print(aHour);
  Serial.print(":");
  Serial.println(aMinute);
 
  pinMode(SETTING_B,INPUT); 
  pinMode(HOUR_B,INPUT);
  pinMode(MINUTE_B,INPUT);
  
  int devices = lc.getDeviceCount(); // LED Matrix Setting
  for(int address=0; address < devices; address++){
    lc.shutdown(address,false);
    lc.setIntensity(address,1);
    lc.clearDisplay(address);
  }
  dot(); // dot function (: btw. Hour & Minute)
  
  // initialize timer1
  noInterrupts(); // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  timer1_counter = 3036; // preload timer 65536-16MHz/256/1Hz
  TCNT1 = timer1_counter; // preload timer
  TCCR1B |= (1 << CS12); // 256 prescaler
  TIMSK1 |= (1 << TOIE1); // enable timer overflow interrupt
  interrupts(); // enable all interrupts
}
 ISR(TIMER1_OVF_vect) // interrupt service routine
{
  TCNT1 = timer1_counter; // preload timer
  second++;
  
  if(second == 60){ // minute change
    second = 0;
    minute++;
    EEPROM.put(eeAddress, hour);
    EEPROM.put(sizeof(hour), minute);
    Serial.println("Written Time to EEPROM!");
  }
  if(minute == 60){ // hour change
    minute = 0;
    hour++;
  }
  Serial.print(hour); // Time Monitor (Debug)
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);
}
void loop(){
  if(set==2){ // Display Alarm Time in Setting
  displayNumber(IMAGES[aMinute%10],0);
  displayNumber(IMAGES[(aMinute%100)/10],1);
  displayNumber(IMAGES[(aHour%10)],2);
  displayNumber(IMAGES[(aHour%100)/10],3);
  }else{ // Display Time
  displayNumber(IMAGES[minute%10],0);
  displayNumber(IMAGES[(minute%100)/10],1);
  displayNumber(IMAGES[(hour%10)],2);
  displayNumber(IMAGES[(hour%100)/10],3);
  }
  SettingB(digitalRead(SETTING_B));
  HourB(digitalRead(HOUR_B));
  MinB(digitalRead(MINUTE_B));
  if(hour==aHour && minute == aMinute and alarm and stopp) // Alarm Checker
  {
    ring=true;
    stopp=false;
  }
  if(ring){
    if(se==1){
      ring=false;
      alarm=false;
    }
    Serial.println("Wakey Wakey it's Time for School, Come on Wake Up");
    tone(speakerPin, 440);
    delay(500);
    noTone(speakerPin);
  }
  LDR_Brightness_Change();
}
void displayNumber(uint64_t image,int unit){ // Display Number & Text on LED Matrix
  int maxN = 8;
  for(int i=0;i<8;i++){
    if(unit==2){maxN = 7;}
    byte row = (image >> i * 8) & 0xFF;
    for(int j=0;j<maxN;j++){
      lc.setLed(unit,i,j,bitRead(row,j)); // address,row,column
      delay(5);
    }
  }
}
void dot(){ // Dot btw. Hour & Minute
  lc.setLed(2,1,7,true);
  lc.setLed(2,2,7,true);
  lc.setLed(2,5,7,true);
  lc.setLed(2,6,7,true);
}
void LDR_Brightness_Change(){ // Change LED Matrix brightness via LDR Sensor
  int devices = lc.getDeviceCount();
  int sensor_val = analogRead(LDR_PIN);
  int val;
  if (sensor_val > 0 && sensor_val <= 128) {val = 7;}
  else if (sensor_val > 128 && sensor_val <= 256) {val = 6;}
  else if (sensor_val > 256 && sensor_val <= 384) {val = 5;}
  else if (sensor_val > 384 && sensor_val <= 512) {val = 4;}
  else if (sensor_val > 512 && sensor_val <= 640) {val = 3;}
  else if (sensor_val > 640 && sensor_val <= 768) {val = 2;}
  else if (sensor_val > 768 && sensor_val <= 896) {val = 1;}
  else if (sensor_val > 896 && sensor_val <= 1024) {val = 0;}
  for(int address=0; address < devices; address++){
    lc.setIntensity(address,val);
  }
}
