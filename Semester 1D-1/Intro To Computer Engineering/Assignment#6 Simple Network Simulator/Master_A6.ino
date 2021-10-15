#include <Wire.h>
byte i = 1;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Wire.beginTransmission(1); // Master -> Slave 1
  Wire.write("Hello");
  Wire.write(i);
  Wire.endTransmission();
}
void loop()
{
  Wire.requestFrom(1,6); // Master <- Slave 1
  Serial.print("From Slave 1 : ");
  while(1 < Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
  i = Wire.read();
  Serial.println(i);

  Wire.beginTransmission(2); // Master -> Slave 2
  Wire.write("Hello");
  Wire.write(i);
  Serial.print("To Slave 2 : Hello");
  Serial.println(i);
  Wire.endTransmission();

  Wire.requestFrom(2,6); // Master <- Slave 2
  Serial.print("From Slave 2 : ");
  while(1 < Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
  i = Wire.read();
  Serial.println(i);
  Wire.beginTransmission(1); // Master -> Slave 1
  Wire.write("Hello");
    if(i==9){
    i=1;
  }
  Wire.write(i);
  Serial.print("To Slave 1 : Hello");
  Serial.println(i);
  Wire.endTransmission();
  
  delay(500);
}
