#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_sleep.h"

// Define as variáveis na memória RTC
RTC_DATA_ATTR static int contador = 0;

void app_main(void)
{

    while(1)
    {
    if(contador>=5)
    {
    // Reinicia o ESP32
    printf("Entrei\n");
    ESP_LOGI("RTC_COUNTER", "Reiniciando o ESP32");
    esp_restart();

    }
    ESP_LOGI("RTC_COUNTER", "Inicializando o app_main");

    // Incrementa o contador
    contador++;

    // Exibe o valor atual do contador
    ESP_LOGI("RTC_COUNTER", "Contador: %d", contador);

    // Adiciona um delay para que o valor possa ser visualizado no log
    vTaskDelay(pdMS_TO_TICKS(1000));
    esp_sleep_enable_timer_wakeup(5000);
    esp_deep_sleep_start();



    }
    





}
