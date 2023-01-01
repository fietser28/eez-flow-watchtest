
#include <Arduino.h>
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "display.h"
#include "ui/vars.h"

bool ledstate;
const TickType_t loopdelay = 1000;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  gui_task_init();
}

void loop()
{
  ledstate = !ledstate;
  digitalWrite(LED_BUILTIN, ledstate);

  vTaskDelay(loopdelay);
}