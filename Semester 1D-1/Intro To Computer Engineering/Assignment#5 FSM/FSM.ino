//pin
#define SR 13
#define SY 12
#define SG 11
#define WR 10
#define WY 9
#define WG 8
#define AG 7
#define AR 6
#define S_button 4
#define W_button 3
#define A_button 2
//State
#define goS 0
#define waitS 1
#define walk 2
#define Wblink 3
#define goW 4
#define waitW 5
struct State {
  unsigned long ST_Out;
  unsigned long Time;
  unsigned long Next[8];
};

typedef const struct State SType;

SType FSM[11] = {
  {B00110001, 1500, {goS, waitS, waitS, waitS, goS, waitS, waitS, waitS}}, //goS
  {B01010001, 300, {walk, walk, goW, walk, walk, walk, goW, walk}}, //waitS
  {B10010010, 900, {walk, walk, Wblink, Wblink, Wblink, Wblink, Wblink, Wblink}}, //Walk
  {B10010000, 100, {6, 6, 6, 6, 6, 6, 6, 6}}, //Wblink
  {B10000101, 1500, {goW, waitW, goW, waitW, waitW, waitW, waitW, waitW}}, //goW
  {B10001001, 300, {goS, walk, goS, walk, goS, goS, goS, goS}}, //waitW

  {B10010010, 100, {7, 7, 7, 7, 7, 7, 7, 7}}, //blink1
  {B10010000, 100, {8, 8, 8, 8, 8, 8, 8, 8}}, //blink0
  {B10010010, 100, {9, 9, 9, 9, 9, 9, 9, 9}}, //blink1
  {B10010000, 100, {10, 10, 10, 10, 10, 10, 10, 10}}, //blink0
  {B10010010, 100, {goW, goW, goW, goW, goS, goS, goW, goW}}, //blink1
};

void setup() {
  pinMode(SR, OUTPUT);
  pinMode(SY, OUTPUT);
  pinMode(SG, OUTPUT);

  pinMode(WR, OUTPUT);
  pinMode(WY, OUTPUT);
  pinMode(WG, OUTPUT);

  pinMode(AG, OUTPUT);
  pinMode(AR, OUTPUT);

  pinMode(S_button, INPUT);
  pinMode(W_button, INPUT);
  pinMode(A_button, INPUT);
}
int i1, i2, i3, S = 0;
void loop() {

  digitalWrite(SR, FSM[S].ST_Out & B10000000);
  digitalWrite(SY, FSM[S].ST_Out & B01000000);
  digitalWrite(SG, FSM[S].ST_Out & B00100000);
  digitalWrite(WR, FSM[S].ST_Out & B00010000);
  digitalWrite(WY, FSM[S].ST_Out & B00001000);
  digitalWrite(WG, FSM[S].ST_Out & B00000100);
  digitalWrite(AG, FSM[S].ST_Out & B00000010);
  digitalWrite(AR, FSM[S].ST_Out & B00000001);
  delay(FSM[S].Time);
  i1 = digitalRead(S_button);
  i2 = digitalRead(W_button);
  i3 = digitalRead(A_button);
  S = FSM[S].Next[i1 * 4 + i2 * 2 + i3];
}
