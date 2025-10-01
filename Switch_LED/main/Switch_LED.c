#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void app_main(void)
{
    // 0. create variables 
    int SW1_Status = 0;
    int LED1_status = 0;
    int SW2_Status = 0;
    int LED2_status = 0;

    // 1. gpio_set_direction pin 16 and 18 to Output (LED1, LED2)
    gpio_set_direction(16, GPIO_MODE_OUTPUT); // LED1
    gpio_set_direction(18, GPIO_MODE_OUTPUT); // LED2

    // 2. gpio_set_direction pin 15 and 17 to Input (SW1, SW2)
    gpio_set_direction(15, GPIO_MODE_INPUT); // SW1
    gpio_set_direction(17, GPIO_MODE_INPUT); // SW2

    while(1)
    {
        // read level of gpio 15 and store in SW1_Status 
        SW1_Status = gpio_get_level(15);
        LED1_status = SW1_Status; // ถ้ากด SW1 ให้ไฟติด

        gpio_set_level(16, LED1_status);

        // read level of gpio 17 and store in SW2_Status 
        SW2_Status = gpio_get_level(17);
        LED2_status = SW2_Status; // ถ้ากด SW2 ให้ไฟติด

        gpio_set_level(18, LED2_status);

        // Delay
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}