#include <Wire.h>
byte num;
void setup()
{
  Wire.begin(1); // Slave 1
  //Wire.begin(2); // Slave 2
  Wire.onReceive(receiveData);
  Wire.onRequest(requestData);
  Serial.begin(9600); // serial monitor output
}

void loop()
{
  delay(100);
}
void receiveData(int howMany)
{
  Serial.print("From Master : ");
  while(1 < Wire.available()) 
  {
    char c = Wire.read(); // read character
    Serial.print(c);         // print the character
  }
  num = Wire.read();    // read an integer
  Serial.println(num);         // print the integer
  num+=1;
}
void requestData(){
  Wire.write("Hello");
  Wire.write(num);
  Serial.print("Slave 1 To Master : Hello");
  Serial.println(num);
}
