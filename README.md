# Smart Workspace Environmental Monitor (SWEM)

## About the Project

The Smart Workspace Environmental Monitor (SWEM) is an Arduino-based embedded system that monitors the temperature and humidity of a workspace using a DHT22 sensor.

The measured values are displayed on a 16×2 I2C LCD, while an RGB LED and buzzer provide visual and audible alerts based on the surrounding environmental conditions.

This project was built to strengthen my understanding of embedded systems, sensor interfacing, GPIO programming, and I2C communication.

---

## Features

- Displays real-time temperature
- Displays real-time humidity
- Shows system status on LCD
- RGB LED indicates environmental condition
- Buzzer warning for high temperature
- Startup boot screen
- Sensor error detection

---

## Components Used

- Arduino UNO R3
- DHT22 Temperature & Humidity Sensor
- 16×2 LCD with I2C Module
- RGB LED
- Passive Buzzer
- Breadboard
- Jumper Wires
- 220Ω Resistors

---

## Pin Connections

| Component | Pin |
|-----------|-----|
| DHT22 | D2 |
| Buzzer | D8 |
| Red LED | D11 |
| Green LED | D12 |
| Blue LED | D13 |
| LCD SDA | A4 |
| LCD SCL | A5 |

---

## Temperature Status

- Below 18°C → Cold
- 18°C – 22°C → Cool
- 22°C – 30°C → Comfortable
- 30°C – 35°C → Warm
- 35°C – 40°C → High Temperature
- Above 40°C → Critical

---
## Skills Learned

Through this project, I gained hands-on experience with:

- Embedded C Programming
- Arduino Programming
- Sensor Interfacing
- DHT22 Temperature & Humidity Sensor
- I2C Communication
- LCD Interfacing
- GPIO Programming
- RGB LED Control
- Buzzer Interfacing
- Real-Time Data Monitoring
- Conditional Logic
- Hardware Troubleshooting
- Circuit Prototyping
- Breadboard Wiring
- Arduino IDE

## Future Improvements

- Add humidity-based alerts
- Add fan control using relay
- Store data on SD card
- Add Wi-Fi using ESP32
- Build a mobile dashboard

---

## Author

**Yash Doke**

B.Tech Electronics & Communication Engineering
