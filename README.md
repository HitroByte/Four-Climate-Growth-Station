### 🌱 Smart Climate-Controlled Multi-Zone Farming System
<br><br>/
# An Arduino-based smart farming project that monitors and controls environmental conditions across four simulated climatic regions—Tropical, Dry, Temperate, and Polar—to demonstrate how crops can be grown under optimal conditions regardless of external weather. The system continuously measures soil moisture, air temperature, humidity, and light intensity using a combination of sensors. Based on these readings, it automatically activates an irrigation pumps and suggests lighting, ventilation, and climate installations to recreate the desired environment for each climate zone.
<br><br>/

## ✨ Features
<br><br>/

* 🌡️ Real-time temperature and humidity monitoring using the DHT sensor
* 💧 Automatic irrigation based on soil moisture levels
* ☀️ Ambient light detection using an LDR
* 🔄 Intelligent relay control for pump
* ⏱️ Pump cycling (ON/OFF intervals) to allow water to soak into the soil efficiently
* 📊 Serial Monitor output for live environmental data
* 🖥️ 16×2 I²C LCD display for real-time system status and sensor readings
* 🌍 Independent configurations for Tropical, Dry, Temperate, and Polar climate zones
* 🌱 Demonstrates practical applications of precision agriculture and climate-smart farming

<br><br>/

## 🛠️ Hardware
<br><br>/
* Arduino Uno
* DHT11/DHT22 Temperature & Humidity Sensor
* Capacitive Soil Moisture Sensor
* LDR (Light Dependent Resistor)
* 1-Channel Relay Module
* Mini Water Pump
* 16×2 I²C LCD Display
* Jumper Wires & Breadboard

<br><br>/

## 📂 Repository Structure
<br><br>/

* README.md
* Tropical Region Code
* Dry Region Code
* Temperate Region Code 
* Polar Region Code

<br><br>/

# Each sketch is optimized with climate-specific thresholds and control logic while maintaining a consistent system architecture.

<br><br>/

## 🎯 Purpose
<br><br>/

This project was developed as a STEM competition model - which won 3rd place -  to demonstrate how low-cost electronics and automation can help farmers monitor and regulate growing conditions across diverse climates. The design showcases the potential of smart agriculture to improve crop health, conserve resources, and support sustainable farming in different environmental conditions.
