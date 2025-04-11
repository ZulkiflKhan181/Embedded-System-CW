 Advanced Soil Moisture–Based Irrigation System 💧

An embedded system project that automates irrigation based on real-time soil moisture levels using sensors, relay control, and user-selectable modes via a push button interface. Developed using Arduino Uno.

---

 Features

- **Soil Moisture Monitoring**
  - Reads real-time moisture levels using analog sensors
-  **Finite State Machine (FSM) Based Control**
  - DRY / MOIST / WET / CUSTOM modes
-  **LED Indicators**
  - Visual feedback for irrigation state (DRY = Red, MOIST = Yellow, WET = Green)
-  **Relay-Controlled Water Pump**
  - Automates irrigation when DRY
- 🖥 **LCD Display**
  - Displays current mode and moisture percentage
-  **Custom Thresholds**
  - Set via Serial Monitor and stored in EEPROM
-  **Data Logging**
  - Moisture data logged every minute to Serial
- 🛠 **Manual Mode Switching**
  - Push-button controlled state changes with debounce

---

##  Project Demo

![FSM Diagram](docs/fsm-diagram.png)  
![Circuit Setup](docs/circuit-setup.jpg)

---

## 🛠 Tech Stack

| Component        | Description                         |
|------------------|-------------------------------------|
| Arduino Uno      | Microcontroller                     |
| Soil Sensor      | Capacitive analog moisture sensor   |
| LCD (16x2)       | I2C-based display                   |
| Relay Module     | 1-channel 5V                        |
| LEDs             | Red, Yellow, Green for indication   |
| EEPROM           | Used for storing custom thresholds  |
| Push Button      | Mode switching                      |




