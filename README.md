# ESP8266 Web Server using SPIFFS

This project demonstrates how to create a web server on an ESP8266 using the SPIFFS (SPI Flash File System) to serve HTML, CSS, and JavaScript files. The web server controls an LED and displays temperature and humidity data.

## Features
- LED control (ON/OFF) through the web interface
- Real-time temperature and humidity display using a DHT11 sensor
- SPIFFS to serve static files (HTML, CSS, JS)

## Project Structure
- `src/`: Contains the main C++ code (Arduino-based).
- `data/`: Contains the HTML, CSS, and JS files.
- `platformio.ini`: PlatformIO configuration file.

## Requirements
- ESP8266 module
- PlatformIO with Visual Studio Code
- DHT11 sensor (optional for temperature and humidity)

## How to Use
- Set your WiFi credentials in `src/main.cpp`.
- Upload the SPIFFS files using the PlatformIO File System Image uploader.
- Upload the main code to the ESP8266.
- Access the web interface via the ESP8266 IP address.
