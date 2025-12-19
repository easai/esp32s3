#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_strip.h"

#define LED_GPIO 48
#define LED_COUNT 1

void app_main(void)
{
    // LED strip configuration
    led_strip_config_t strip_config = {
        .strip_gpio_num = LED_GPIO,
        .max_leds = LED_COUNT,
        .led_model = LED_MODEL_WS2812,
        .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB, // fixed macro
    };

    // RMT backend configuration (nested struct requires braces)
    led_strip_rmt_config_t rmt_config = {
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .resolution_hz = 10 * 1000 * 1000, // 10 MHz
        .mem_block_symbols = 64,
    };

    // Create LED strip instance
    led_strip_handle_t strip;
    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &strip));

    // Blink colors
    while (true)
    {
        for (int i = 0; i < 256; i++)
        {
            led_strip_set_pixel(strip, 0, i, 0, 255 - i); // fade from blue to red
            led_strip_refresh(strip);
            vTaskDelay(pdMS_TO_TICKS(20));
        }
    }
}
