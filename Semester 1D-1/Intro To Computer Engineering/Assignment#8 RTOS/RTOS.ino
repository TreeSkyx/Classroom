#include <Arduino_FreeRTOS.h>
#include "queue.h"
#define RED 8
#define YELLOW 7
#define BLUE 6
#define sw1 3
#define sw2 4
#define sw3 5
QueueHandle_t ledQueue1;
QueueHandle_t ledQueue2;
QueueHandle_t ledQueue3;
bool stateY=0;
void setup() {
  Serial.begin(9600);
  ledQueue1 = xQueueCreate(5,sizeof(int32_t));
  ledQueue2 = xQueueCreate(5,sizeof(int32_t));
  ledQueue3 = xQueueCreate(5,sizeof(int32_t));
  xTaskCreate(Sender1,"Sender1 Task",100,NULL,1,NULL);
  xTaskCreate(Sender2,"Sender2 Task",100,NULL,1,NULL);
  xTaskCreate(Sender3,"Sender3 Task",100,NULL,1,NULL);
  
  xTaskCreate(Receiver1,"Receiver Task1",100,NULL,1,NULL);
  xTaskCreate(Receiver2,"Receiver Task2",100,NULL,1,NULL);
  xTaskCreate(Receiver3,"Receiver Task3",100,NULL,1,NULL);
}

void Sender1(void *pvParameters)
{
  BaseType_t qStatus;
  int32_t   valueToSend = 0;
  pinMode(sw1, INPUT);
  while(1)
  {
    valueToSend= digitalRead(sw1);
    qStatus= xQueueSend(ledQueue1,&valueToSend,0); 
    vTaskDelay(10);
  }
}

void Sender2(void *pvParameters)
{
  BaseType_t qStatus;
  int32_t   valueToSend = 0;
  pinMode(sw2, INPUT);
  while(1)
  {
    valueToSend= digitalRead(sw2);
    qStatus= xQueueSend(ledQueue2,&valueToSend,0); 
    vTaskDelay(10);
  }
}
void Sender3(void *pvParameters)
{
  BaseType_t qStatus;
  int32_t   valueToSend = 0;
  pinMode(sw3, INPUT);
  while(1)
  {
    valueToSend= digitalRead(sw3);
    if(!stateY)
        qStatus= xQueueSend(ledQueue3,&valueToSend,0); 
    vTaskDelay(10);
  }
}
void Receiver1(void *pvParameters)
{
  //Variable for Receiver
  int32_t valueReceived;
  BaseType_t qStatus;
  const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
  
  //Real Code for Functional
  pinMode(RED, OUTPUT);
  int old=0;
  int timer=0;
  unsigned long timeM=0;
  while(1)
  {
    xQueueReceive(ledQueue1,&valueReceived,xTicksToWait);
    if(old==0 && valueReceived==1)
    {
      digitalWrite(RED,1);
      if(millis()-timeM < (timer*3000))
        timer+=1;
      else
      {
        timeM = millis();
        timer=1;
      }
    }
    old = valueReceived;
    if(millis()-timeM > (timer*3000))
      digitalWrite(RED,0);
    vTaskDelay(1);
  }
}

void Receiver2(void *pvParameters)
{
  //Variable for Receiver
  int32_t valueReceived;
  BaseType_t qStatus;
  const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
  
  //Real Code for Functional
  bool state = 0;
  pinMode(YELLOW, OUTPUT);
  int old=0;
  unsigned long timeM=0;
  while(1)
  {
    xQueueReceive(ledQueue2,&valueReceived,xTicksToWait);
    if(old==0 && valueReceived==1)
    {
      digitalWrite(YELLOW,0);
      state^=1;
    }
      
    if(state)
    {
      if(millis()-timeM>100)
      {
        digitalWrite(YELLOW,digitalRead(YELLOW)^1);
        timeM=millis();
      }
    }
    old = valueReceived;
    vTaskDelay(1);
  }
}

void Receiver3(void *pvParameters)
{
  //Variable for Receiver
  int32_t valueReceived;
  BaseType_t qStatus;
  const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
  
  //Real Code for Functional
  pinMode(BLUE, OUTPUT);
  int old=0;
  unsigned long timeM=0;
  while(1)
  {
    xQueueReceive(ledQueue3,&valueReceived,xTicksToWait);
    if(old==0 && valueReceived==1)
      stateY=1;
    if(stateY)
    {
      for(int i=0;i<3;i++)
      {
        digitalWrite(BLUE,1);
        vTaskDelay(50/portTICK_PERIOD_MS);
        digitalWrite(BLUE,0);
        if(i!=2)
          vTaskDelay(50/portTICK_PERIOD_MS);
      }
      stateY=0;
    }
    old = valueReceived;
    vTaskDelay(1);
  }
}
void loop() {
}
