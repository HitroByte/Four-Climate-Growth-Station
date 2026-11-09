# 🌱 Smart Climate-Controlled Multi-Zone Farming System

### While farmers may have a basic understanding of how to plant a particular crop, diverse climatic conditions in different places can significantly impact plant health. To solve this problem, I developed this project: an Arduino-based smart farming project that monitors and controls environmental conditions across four simulated climatic regions—Tropical, Dry, Temperate, and Polar—to demonstrate how crops can be grown under optimal conditions regardless of external weather. The system continuously measures soil moisture, air temperature, humidity, and light intensity using a combination of sensors. Based on these readings, it automatically activates an irrigation pump and suggests lighting, ventilation, and climate installations to recreate the desired environment for each climate zone.
<br><br>

## ✨ Features


* 🌡️ Real-time temperature and humidity monitoring using the DHT sensor
* 💧 Automatic irrigation based on soil moisture levels
* ☀️ Ambient light detection using an LDR
* 🔄 Intelligent relay control for pump
* ⏱️ Pump cycling (ON/OFF intervals) to allow water to soak into the soil efficiently
* 📊 Serial Monitor output for live environmental data
* 🖥️ 16×2 I²C LCD display for real-time system status and sensor readings
* 🌍 Independent configurations for Tropical, Dry, Temperate, and Polar climate zones
* 🌱 Demonstrates practical applications of precision agriculture and climate-smart farming

<br><br>

## 🛠️ Hardware

* Arduino Uno
* DHT11/DHT22 Temperature & Humidity Sensor
* Capacitive Soil Moisture Sensor
* LDR (Light Dependent Resistor)
* 1-Channel Relay Module
* Mini Water Pump
* 16×2 I²C LCD Display
* Jumper Wires & Breadboard

<br><br>

## Hardware Connections

### 1. Soil Moisture Sensor

| Sensor Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| AOUT | A0 |

### 2. DHT22 Temperature and Humidity Sensor

| Sensor Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| DATA | D9 |

### 3. LDR Module (Digital Output)

| Sensor Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| DO | D10 |

> **Note:** The LDR module provides a digital HIGH/LOW signal based on its adjustable light threshold. It does not provide a continuous light-intensity reading through the digital output.

### 4. 16×2 I²C LCD

| LCD Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

- I²C address: `0x27`
- Library: `LiquidCrystal_I2C` by Frank de Brabander

### 5. Relay Module

| Relay Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| IN | D8 |

### 6. Water Pump and Power Supply

| Component Connection | Connected To |
|---|---|
| Buck Converter OUT+ | Relay COM |
| Relay NO | Pump Positive (+) |
| Pump Negative (−) | Buck Converter OUT− |

**Important:**
- Adjust the LM2596 buck converter to the required pump voltage before connecting the pump.
- Do not power the pump directly from an Arduino GPIO pin.
- Ensure the sensor, Arduino and relay grounds share a common ground where required.
- Check whether your relay module is active-HIGH or active-LOW before programming its control logic.

<br><br>
  
## 📂 Repository Structure

* README.md
* Tropical Region Code
* Dry Region Code
* Temperate Region Code 
* Polar Region Code

### Each sketch is optimised with climate-specific thresholds and control logic while maintaining a consistent system architecture.

<br><br>

## 🎯 Purpose

This project was developed as a STEM competition model - which won 3rd place -  to demonstrate how low-cost electronics and automation can help farmers monitor and regulate growing conditions across diverse climates. The design showcases the potential of smart agriculture to improve crop health, conserve resources, and support sustainable farming in different environmental conditions.
