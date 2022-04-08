// /* Handle Task with FreeRTOS */

// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>

// // FreeRTOS Practice

// void Task_LED1(void *param);
// void Task_LED2(void *param);

// TaskHandle_t Task_Handle1;
// TaskHandle_t Task_Handle2;

// void setup()
// {
  
//   pinMode(0, OUTPUT);
//   pinMode(1, OUTPUT);
//   pinMode(2, OUTPUT);
//   pinMode(3, OUTPUT);
//   pinMode(4, OUTPUT);
//   pinMode(5, OUTPUT);
//   pinMode(6, OUTPUT);
//   pinMode(7, OUTPUT);

//   /* Create two tasks with priorities 1 and 2. An idle task is also created, 
//      which will be run when there are no tasks in RUN state */

//   xTaskCreate(Task_LED1, "Task1", 100, NULL, 1, &Task_Handle1);
//   xTaskCreate(Task_LED2, "Task2", 100, NULL, 1, &Task_Handle2);
// }

// void loop()
// {
//   // DO nothing
// }

// void Task_LED1(void *param)
// {
//   (void) param;

//   while(1)
//   {
//     digitalWrite(6, HIGH);
//     vTaskDelay(200/portTICK_PERIOD_MS);
//     digitalWrite(6, LOW);
//     vTaskDelay(200/portTICK_PERIOD_MS);
//   }
// }

// void Task_LED2(void *param)
// {
//   (void) param;

//   while(1)
//   {
//     digitalWrite(4, HIGH);
//     vTaskDelay(100/portTICK_PERIOD_MS);
//     digitalWrite(4, LOW);
//     vTaskDelay(100/portTICK_PERIOD_MS);
//   }
// }


/* More Accurate Delay with FreeRTOS
   Before use vTaskDelayUntil() function,
   please command "if" function outside that function
 */
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

// FreeRTOS Practice

void Task_LED1(void *param);
void Task_LED2(void *param);
void Task_Print(void *param);

TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;
TaskHandle_t Task_Handle3;

void setup()
{
  Serial.begin(9600);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  /* Create two tasks with priorities 1 and 2. An idle task is also created, 
     which will be run when there are no tasks in RUN state */

  xTaskCreate(Task_LED1, "Task1", 100, NULL, 1, &Task_Handle1);
  xTaskCreate(Task_LED2, "Task2", 100, NULL, 1, &Task_Handle2);
  xTaskCreate(Task_Print, "Task3", 100, NULL, 1, &Task_Handle3);
}

void loop()
{
  // DO nothing
}

void Task_LED1(void *param)
{
  (void) param;
  TickType_t getTick;
  getTick = xTaskGetTickCount();      // the getTick will get time from systick of OS
  
  while(1)
  {
    digitalWrite(6, HIGH);
    vTaskDelayUntil(&getTick,200 / portTICK_PERIOD_MS);
    digitalWrite(6, LOW);
    vTaskDelayUntil(&getTick,200 / portTICK_PERIOD_MS);
  }
}

void Task_LED2(void *param)
{
  (void) param;
  TickType_t getTick;
  getTick = xTaskGetTickCount();      // the getTick will get time from systick of OS

  while(1)
  {
    digitalWrite(4, HIGH);
    vTaskDelayUntil(&getTick,100 / portTICK_PERIOD_MS);
    digitalWrite(4, LOW);
    vTaskDelayUntil(&getTick,100 / portTICK_PERIOD_MS);
  }
}

void Task_Print(void *param)
{
  (void) param;
  TickType_t getTick;
  getTick = xTaskGetTickCount();      // the getTick will get time from systick of OS

  while(1)
  {
    Serial.println("Hai, I am Alfian");
    vTaskDelayUntil(&getTick,50 / portTICK_PERIOD_MS);
  }
}