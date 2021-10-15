#include "LedControl.h"
#define POT_PIN A1
#define Default_speed 250
LedControl lc = LedControl(11, 13, 10, 2); // CLK,DIN,CS,Numberof LED Module
//speaker var.
int speakerPin = 3;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//  mid C  C#   D    D#   E    F    F#   G    G#   A
//game var.
bool play = true;
int score=0;
int lastscore=0;
//player's pad
int potenR = 0; //direct from poten
int lastPos = 8;
int val; //coverted int
int AIpad;
//ball direction
int add = 0;
char direct;
int ballSpeed = Default_speed;
struct ballPos {
  int row;
  int col;
}; ballPos bPos;

void setup() {
  int devices = lc.getDeviceCount(); // find no of LED modules
  Serial.begin(9600);
  for (int address = 0; address < devices; address++) { // set up each device
    lc.shutdown(address, false);
    lc.setIntensity(address, 1);
    lc.clearDisplay(address);
  }
  start();
  randomSeed(analogRead(A0));
}

void loop() {
  clr_screen();//clear screen
  init_ball();//random ball position
  AI_line();// AI's pad
  while (play) {
    int devices = lc.getDeviceCount(); // find no of LED modules
    potenR = analogRead(POT_PIN);
    if (potenVal(potenR) != lastPos) {
      lc.setLed(0, potenVal(potenR) - 1, 7, true); //address,row,col
      lc.setLed(0, potenVal(potenR), 7, true);
      lc.setLed(0, potenVal(potenR) + 1, 7, true);
      if (potenVal(potenR) > lastPos) {
        for (int i = 2; i <= 6; i++) {
          lc.setLed(0, potenVal(potenR) - i, 7, false);
        }
      } else {
        for (int i = 2; i <= 6; i++) {
          lc.setLed(0, potenVal(potenR) + i, 7, false);
        }
      }
      lastPos = potenVal(potenR);
    } else { // in-case of restart and didn't change lastPos
      lc.setLed(0, potenVal(potenR) - 1, 7, true); //address,row,col
      lc.setLed(0, potenVal(potenR), 7, true);
      lc.setLed(0, potenVal(potenR) + 1, 7, true);
    }
    changeDis();// ball jump btw. display 0&1
    ballMove(direct);// movement of the ball
    hitCheck(bPos.col, bPos.row);// collision check
    changeSpeed();
    Serial.println(ballSpeed);
  }
  lose();
  delay(3000);
  play = true;
}
int potenVal(int poten) { // convert 0-1024 to 1-6
  if (poten > 0 && poten <= 256) {val = 1;}
  else if (poten > 256 && poten <= 384) {val = 2;}
  else if (poten > 384 && poten <= 512) {val = 3;}
  else if (poten > 512 && poten <= 640) {val = 4;}
  else if (poten > 640 && poten <= 768) {val = 5;}
  else if (poten > 768 && poten <= 1024) {val = 6;}
  return val;
}
void start() { // display when start the game
  int devices = lc.getDeviceCount();
  Serial.println("Pong game -> Start");
  for (int row = 0; row < 8; row++)
  {
    tone(speakerPin, tones[row]);
    for (int col = 0; col < 8; col++)
    {
      for ( int address = 0; address < devices; address++) {
        delay(50);
        lc.setLed(address, row, col, true);
      }
    }
  }
  noTone(speakerPin);
}
void lose() { // display when lose the game
  clr_screen();
  Serial.println("Your lose!");
  Serial.print("Score : ");
  Serial.println(score);
  int devices = lc.getDeviceCount();
  int count = 0;
  for (int i = 0; i < 8; i++)
  {
    for ( int address = 0; address < devices; address++) {
      delay(50);
      lc.setLed(address, i, i, true);
    }
  }
  for (int row = 7; row >= 0; row--)
  {
    tone(speakerPin, tones[row]);
    delay(50);
    noTone(speakerPin);
    for ( int address = 0; address < devices; address++) {
      delay(50);
      lc.setLed(address, row, count, true);
    }
    count++;
  }
  score=0;
  lastscore=0;
  ballSpeed = Default_speed;
}
void clr_screen() { // clear all display
  lc.clearDisplay(0);
  lc.clearDisplay(1);
}
void init_ball() {
  bPos.row = random(1, 7); //min,max-1
  bPos.col = random(1, 7);
  int ranDir = random(1, 3);
  if (ranDir == 1) {direct = '7';}
  else {direct = '1';}
}
void ballMove(char dir) {
  if (dir == 'W') {
    lc.setLed(add, bPos.row, bPos.col, false);
    bPos.col--;
    lc.setLed(add, bPos.row, bPos.col, true);
    delay(ballSpeed);
  }
  if (dir == 'S') {
    lc.setLed(add, bPos.row, bPos.col, false);
    bPos.col++;
    lc.setLed(add, bPos.row, bPos.col, true);
    delay(ballSpeed);
  }
  if (dir == '7') {
    lc.setLed(add, bPos.row, bPos.col, false);
    bPos.col--;
    bPos.row++;
    lc.setLed(add, bPos.row, bPos.col, true);
    delay(ballSpeed);
  }
  if (dir == '9') {
    lc.setLed(add, bPos.row, bPos.col, false);
    bPos.col++;
    bPos.row--;
    lc.setLed(add, bPos.row, bPos.col, true);
    delay(ballSpeed);
  }
  if (dir == '3') {
    lc.setLed(add, bPos.row, bPos.col, false);
    bPos.col++;
    bPos.row++;
    lc.setLed(add, bPos.row, bPos.col, true);
    delay(ballSpeed);
  }
  if (dir == '1') {
    lc.setLed(add, bPos.row, bPos.col, false);
    bPos.col--;
    bPos.row--;
    lc.setLed(add, bPos.row, bPos.col, true);
    delay(ballSpeed);
  }
}
void hitCheck(int col, int row) {
  if (col == 1 && add == 1) {
    AIpad = 1;
    if(row==0) {direct = '9';}
      else if(row ==7) {direct = '3';}
      else{
      int ranDir = random(1, 4);
      if (ranDir == 1) {direct = '3';}
      else if(ranDir == 2){direct = '9';}
      else {direct = 'S';}
      tone(speakerPin, 370);
      delay(50);
      noTone(speakerPin);
      }
}
  if (col == 6 && add == 0) {
    AIpad = 0;
    if (padCheck() == 1) {
      if(row==7){direct = '7';}
      else if(row==0){direct = '1';}
      else{
         int ranDir = random(1, 4);
         if (ranDir == 1){direct = '7';}
         else if(ranDir == 2){direct = '1';}
         else {direct = 'W';}
      }
      score+=1;
      tone(speakerPin, 440);
      delay(50);
      noTone(speakerPin);
    }
    if (padCheck() == 0) {
      play = false;
      direct = '7';
    }
  }
  if (row == 7) {
    if (direct == '3') {direct = '9';}
    else if (direct == '1') {direct = '7';}
    else if (direct == '7') {direct = '1';}
    tone(speakerPin, 370);
    delay(50);
    noTone(speakerPin);
  }
  if (row == 0) {
    if (direct == '9') {direct = '3';}
    else if (direct == '7') {direct = '1';}
    else if (direct == '1') {direct = '7';}
    tone(speakerPin, 370);
    delay(50);
    noTone(speakerPin);
  }
}
int padCheck() { // check collision of ball and player's pad
  if((potenVal(potenR) == bPos.row) || (potenVal(potenR) + 1 == bPos.row) || (potenVal(potenR) - 1 == bPos.row)) {return 1;}
  else {return 0;}
}
void changeDis() {
  lc.setLed(add, bPos.row, bPos.col, false);
  if (bPos.col == 0 && add == 0 && AIpad == 0) {
    add++;
    bPos.col = 8;
  }
  if (bPos.col == 0 && add == 0 && AIpad == 0) {
    add++;
    bPos.col = 8;
  }
  if (bPos.col == 7 && add == 1 && AIpad == 1) {
    add--;
    bPos.col = (-1);
  }
  if (bPos.col == 7 && add == 1 && AIpad == 1) {
    add--;
    bPos.col = (-1);
  }
}
void AI_line(){
  for(int i=0;i<8;i++){
    lc.setLed(1,i,0,true);
  }
}
void changeSpeed(){
  if((score-lastscore)>=5){
    if(ballSpeed<=50){
      ballSpeed-=10;
    }
    else if(ballSpeed<10){
      ballSpeed=10;
    }
    else{
    ballSpeed-=50;
    }
    lastscore = score;
  }
}
