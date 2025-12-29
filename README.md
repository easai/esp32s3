# ESP32-S3 onboard NeoPixel

<img src="https://github.com/easai/esp32s3/blob/main/IMG_2664.jpeg" width="300" alt="ESP32-S3"/>

This project provides control of the onboard WS2812 and WS2818 addressable LEDs using the ESP-IDF framework. 
It is configured for the ESP32-S3 development board and uses the official Espressif LED Strip driver with RMT backend support. 
The implementation cycles through colors on the single onboard LED and can be extended to external LED strips by adjusting configuration parameters.

## Features
- Integration with ESP-IDF LED Strip driver
- RMT peripheral used for precise timing
- Configurable GPIO pin and LED count
- Example application that cycles through red, green, and blue states

## Project Structure
- `src/` contains the application entry point
- `components/led_strip/` contains the LED Strip driver
- `platformio.ini` defines PlatformIO environment settings
- `.gitignore` excludes build artifacts and temporary files

## Requirements
- ESP32-S3 development board
- PlatformIO with ESP-IDF framework enabled
- USB connection for flashing and monitoring

## Usage
Build and upload the project with PlatformIO. The onboard LED will cycle through colors. Adjust the configuration to connect and control external WS2812 or WS2818 LED strips.
