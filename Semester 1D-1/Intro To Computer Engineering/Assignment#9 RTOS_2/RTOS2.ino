#include <Arduino_FreeRTOS.h>
#include "queue.h"
#include "semphr.h"
#define sw1 3
#define sw2 4
#define sw3 5
#define R 8
#define Y 7
#define G 6
SemaphoreHandle_t Handle;
void setup()
{
  Serial.begin(9600);
  if ( Handle == NULL)
  {
    Handle = xSemaphoreCreateCounting(2, 1);
    if ((Handle) != NULL)
      xSemaphoreGive((Handle));
  }
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  xTaskCreate(Task1, "Text", 100, NULL, 1, NULL);
  xTaskCreate(Task2, "Text", 100, NULL, 1, NULL);
  xTaskCreate(Task3, "Text", 100, NULL, 1, NULL);
}
void Task1(void *pv)
{
  int old = 0;
  unsigned long timer = 0;
  bool state = false;
  while (1)
  {
    int data = digitalRead(sw1);
    if (data == 1 && old == 0)
    {
      timer = millis();
      if (!state)
        xSemaphoreTake(Handle, (TickType_t)5);
      if (xSemaphoreTake(Handle, (TickType_t)5) == pdTRUE)
      {
        xSemaphoreGive(Handle);
        state ^= 1;
        old = 1;
        if (state)
        {
          timer = millis();
          digitalWrite(G, 1);
        }
        else
        {
          digitalWrite(G, 0);
          xSemaphoreGive(Handle);
        }
      }
      else if (!state)
        xSemaphoreGive(Handle);
    }
    if (millis() - timer > 3000)
    {
      if (state != false)
      {
        state = false;
        digitalWrite(G, 0);
        xSemaphoreGive(Handle);
      }
    }
    if (millis() - timer > 50)
      old = data;
  }
}
void Task2()
{
  int old = 0;
  unsigned long timer = 0;
  while (1)
  {
    int data = digitalRead(sw2);
    if (data == 1 && old == 0)
    {
      timer = millis();
      old = 1;
      if (xSemaphoreTake(Handle, (TickType_t)5) == pdTRUE)
      {
        if (xSemaphoreTake(Handle, (TickType_t)5) == pdTRUE)
        {
          xSemaphoreGive(Handle);
          xSemaphoreGive(Handle);
          digitalWrite(Y, 1);
          vTaskDelay(250 / portTICK_PERIOD_MS);
          digitalWrite(Y, 0);
          vTaskDelay(250 / portTICK_PERIOD_MS);
          digitalWrite(Y, 1);
          vTaskDelay(250 / portTICK_PERIOD_MS);
          digitalWrite(Y, 0);
          vTaskDelay(250 / portTICK_PERIOD_MS);
          digitalWrite(Y, 1);
          vTaskDelay(250 / portTICK_PERIOD_MS);
          digitalWrite(Y, 0);
          vTaskDelay(250 / portTICK_PERIOD_MS);
          digitalWrite(Y, 1);
          vTaskDelay(250 / portTICK_PERIOD_MS);
          digitalWrite(Y, 0);
          vTaskDelay(250 / portTICK_PERIOD_MS);
        }
        else
          xSemaphoreGive(Handle);
      }
    }
    if (millis() - timer > 50)
      old = data;
  }
}
void Task3(void *pv)
{
  bool state = false;
  unsigned long timer = 0;
  int old = 0;
  while (1)
  {
    int data = digitalRead(sw3);
    if (data == 1 && old == 0)
    {
      timer = millis();
      state ^= 1;
      old = 1;
      if (state)
      {
        xSemaphoreTake(Handle, (TickType_t)5);
        timer = millis();
        digitalWrite(R, 1);
      }
      else
      {
        digitalWrite(R, 0);
        xSemaphoreGive(Handle);
      }
    }
    if (millis() - timer > 3000)
    {
      if (state != false)
      {
        state = false;
        digitalWrite(R, 0);
        xSemaphoreGive(Handle);
      }
    }
    if (millis() - timer > 50)
      old = data;
  }
}
void loop() {}
