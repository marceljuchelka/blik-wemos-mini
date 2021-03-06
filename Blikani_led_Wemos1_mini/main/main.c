/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "driver/uart_select.h"
#include "driver/uart.h"
#include "driver/adc.h"
#include "portmacro.h"

#include "FreeRTOSConfig.h"
#include "..\build\include\sdkconfig.h"



#define led_pin_mb		GPIO_Pin_2
#define led_pin_red		GPIO_Pin_0
#define led_pin_yellow	GPIO_Pin_12
#define led_pin_green	GPIO_Pin_14


#define led_mb		GPIO_NUM_2
#define led_red		GPIO_NUM_0
#define led_yellow	GPIO_Pin_0
#define led_green	led_pin_green

gpio_config_t	gpio_cfg;
adc_config_t	adc_cfg;



void app_main()
{

	uint8_t uroven = 0;
	gpio_cfg.pin_bit_mask = GPIO_Pin_2 | GPIO_Pin_0 | GPIO_Pin_12 | GPIO_Pin_14;
	gpio_cfg.mode = GPIO_MODE_DEF_OUTPUT;
	gpio_config(&gpio_cfg);
	adc_cfg.mode = ADC_READ_TOUT_MODE;

//	gpio_set_direction(led_mb, GPIO_MODE_OUTPUT);
	while(1){
		uroven^= 1;
		gpio_set_level(led_green, uroven);
		vTaskDelay(300/portTICK_PERIOD_MS);
		gpio_set_level(led_red, uroven);
		vTaskDelay(200/portTICK_PERIOD_MS);
		gpio_set_level(led_pin_yellow, uroven);
		vTaskDelay(300/portTICK_PERIOD_MS);
		gpio_set_level(led_mb, uroven);
		vTaskDelay(200/portTICK_PERIOD_MS);
	}

}
