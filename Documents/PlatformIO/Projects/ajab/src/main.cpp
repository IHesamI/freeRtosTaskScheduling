#include <Arduino.h>

// put function declarations here:
int count=0 ;
int count2=0;
void task1(void * parameters){
  for(;;){
    Serial.print("hello from task1");
    Serial.println(count++);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void task2(void * parameters){
  for(;;){
    Serial.print("hello from task2");
    Serial.println(count2++);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(9600);
  xTaskCreate(task1,"Task 1",1000,NULL,1,NULL);
  xTaskCreate(task2,"Task 2",1000,NULL,1,NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
}
