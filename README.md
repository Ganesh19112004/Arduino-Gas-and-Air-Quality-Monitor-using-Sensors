# Arduino Gas and Air Quality Monitor with DHT11 Sensor

This project demonstrates how to build a gas and air quality monitoring system using an Arduino, various gas sensors, a DHT11 temperature and humidity sensor, and an LCD display. The system detects gases like LPG, smoke, carbon monoxide (CO), hydrogen (H2), and methane (CH4) and displays the corresponding levels and air quality index (AQI) on an LCD screen.

## Components Required
- Arduino Uno or compatible board
- LiquidCrystal LCD (16x2)
- DHT11 Temperature and Humidity Sensor
- MQ-2 Gas Sensor (for detecting LPG, smoke, CO, H2)
- MQ-4 Gas Sensor (for detecting CH4)
- Jumper wires
- Breadboard
- Power source (e.g., USB or battery)

## Pin Connections

### DHT11 Sensor:
- DHT11 Data Pin → Pin 7 on Arduino
- DHT11 VCC → 5V on Arduino
- DHT11 GND → GND on Arduino

### Gas Sensors:
- Gas Sensor 1 (LPG, Smoke, CO, H2) Analog Pin → A0 on Arduino
- Gas Sensor 2 (CH4) Analog Pin → A1 on Arduino

### LCD:
- LCD RS → Pin 12 on Arduino
- LCD E → Pin 11 on Arduino
- LCD D4 → Pin 5 on Arduino
- LCD D5 → Pin 4 on Arduino
- LCD D6 → Pin 3 on Arduino
- LCD D7 → Pin 2 on Arduino
- LCD VCC → 5V on Arduino
- LCD GND → GND on Arduino

## Software Requirements
- Arduino IDE
- DHT sensor library for DHT11
- LiquidCrystal library (pre-installed in Arduino IDE)

## Features
- **Gas Detection**: Measures the levels of LPG, smoke, CO, hydrogen, and methane.
- **Air Quality**: Displays the Air Quality Index (AQI) based on gas levels.
- **Temperature and Humidity**: Reads and displays the temperature and humidity using the DHT11 sensor.
- **LCD Display**: Outputs real-time data about gas levels, air quality, temperature, and humidity on a 16x2 LCD screen.

## How It Works

### Gas Detection:
The gas sensors (MQ-2 and MQ-4) are used to detect the presence of gases in the environment. The sensor values are read from analog pins on the Arduino, which are then scaled using predefined factors (lpgFactor, smokeFactor, etc.) to calculate the gas levels.

### Air Quality Calculation:
The system computes the Air Quality Index (AQI) by using the gas sensor values and classifies the air quality as "Good", "Satisfactory", "Moderate", "Poor", "Very Poor", or "Severe".

### Temperature and Humidity:
The DHT11 sensor measures the temperature (in Celsius and Fahrenheit) and humidity in the surrounding environment. These readings are displayed on the LCD.

### LCD Output:
The LCD shows the gas type and level, the calculated AQI, and the temperature and humidity readings in real-time.

## Circuit Diagram
Here is the wiring diagram for connecting the sensors and LCD:

[DHT11 Sensor] → [Pin 7 on Arduino]
[Gas Sensors] → [Analog Pins A0 and A1 on Arduino]
[LCD] → [Pins 2 to 12 on Arduino]


## Code Overview
The code is structured as follows:
- **Sensor Initialization**: The DHT11 sensor and LCD are initialized in the `setup()` function. Serial communication is also started for debugging.
- **Main Loop**: The main loop (`loop()`) continuously reads the sensor values and updates the display every second. It calls functions to display gas readings, air quality, and DHT sensor data.
- **Gas Detection**: The function `readAndDisplaySensorData()` reads analog values from the gas sensors, calculates gas concentrations, and determines the air quality.
- **Displaying Data**: Functions such as `displayGasInfo()`, `displayAirQuality()`, and `displayDHTSensorData()` handle displaying information on the LCD.

## Example Output on LCD
**Gas Levels**: Displays the gas concentration levels in ppm.
LPG: 1.25
Smoke: 0.85
CO: 0.35
Hydrogen: 0.02

**Air Quality**: Displays the air quality status.
Air Quality: Good
AQI: 35

**Temperature and Humidity**:
Temp: 22.5°C
Hum: 45.6%

## Troubleshooting
- **DHT Sensor Error**: If the temperature or humidity readings show an error, ensure that the DHT11 sensor is properly connected and the wiring is correct.
- **Incorrect Gas Readings**: Calibrate the gas sensors properly as each sensor type (MQ-2, MQ-4) has different sensitivity. Adjust the scaling factors (lpgFactor, smokeFactor, etc.) if necessary.

## Conclusion
This project provides an easy-to-follow example of building a gas and air quality monitor using Arduino and a variety of sensors. It is a great way to learn about environmental sensing and air quality monitoring systems. The project can be expanded with more sensors, alerts, or data logging features.
