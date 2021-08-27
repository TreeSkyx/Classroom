/* 
 *  Arduino Charlieplexing 3 pin with 6 LED
 *  + LED pattern 1-2-3-4-5-6-5-4-3-2-1
 */
#define R1 11 // Digital pin 11
#define R2 10 // Digital pin 10
#define R3 9  // Digital pin 9
void LED(int n){
  switch(n){
    case 1 :  pinMode(R1,OUTPUT); //LED 1
              pinMode(R2,OUTPUT);
              pinMode(R3,INPUT);
              digitalWrite(R1,LOW);
              digitalWrite(R2,HIGH);
              digitalWrite(R3,LOW); break;
    case 2 :  pinMode(R1,OUTPUT); //LED 2
              pinMode(R2,OUTPUT);
              pinMode(R3,INPUT);
              digitalWrite(R1,HIGH);
              digitalWrite(R2,LOW);
              digitalWrite(R3,LOW); break;
    case 3 :  pinMode(R1,INPUT); //LED 3
              pinMode(R2,OUTPUT);
              pinMode(R3,OUTPUT);
              digitalWrite(R1,LOW);
              digitalWrite(R2,LOW);
              digitalWrite(R3,HIGH); break;
    case 4 :  pinMode(R1,INPUT); //LED 4
              pinMode(R2,OUTPUT);
              pinMode(R3,OUTPUT);
              digitalWrite(R1,LOW);
              digitalWrite(R2,HIGH);
              digitalWrite(R3,LOW); break;
    case 5 :  pinMode(R1,OUTPUT); //LED 5
              pinMode(R2,INPUT);
              pinMode(R3,OUTPUT);
              digitalWrite(R1,LOW);
              digitalWrite(R2,LOW);
              digitalWrite(R3,HIGH); break;
    case 6 :  pinMode(R1,OUTPUT); //LED 6
              pinMode(R2,INPUT);
              pinMode(R3,OUTPUT);
              digitalWrite(R1,HIGH);
              digitalWrite(R2,LOW);
              digitalWrite(R3,LOW);break;
  }
}
void setup() {
}
void loop() {
  int i,x=1;
  for(i=1;i>0;i=i+x){
    LED(i);           //LED light on & off
    if(i==6)x=-1;     //reverse
    if(x==-1&&i==1)break;
    delay(500);
  }
  return 0;
}
