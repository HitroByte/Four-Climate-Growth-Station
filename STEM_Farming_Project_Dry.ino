#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <DHT.h>
#include <DHT_U.h>


// ---------- Pin Definitions ----------
#define DHTPIN 9
#define DHTTYPE DHT22

#define MOISTURE_PIN A0
#define LDR_PIN 10
#define RELAY_PIN 8

DHT dht(DHTPIN, DHTTYPE);

// ---------- Moisture Calibration ----------
const int DRY_VALUE = 1000;  // <-- Change after calibration
const int WET_VALUE = 200;   // <-- Change after calibration

// ---------- Pump Thresholds ----------
const int PUMP_ON_LEVEL = 20;
const int PUMP_OFF_LEVEL = 40;

bool pumpState = false;

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);  // Change to HIGH if your relay is active LOW

  lcd.init();
  lcd.backlight();

  Serial.println("========================================");
  Serial.println(" SMART IRRIGATION SYSTEM");
  Serial.println("========================================");
}

void loop() {

  //---------------- Soil Moisture ----------------

  int rawMoisture = analogRead(MOISTURE_PIN);

  int moisture = map(rawMoisture,
                     DRY_VALUE,
                     WET_VALUE,
                     0,
                     100);

  moisture = constrain(moisture, 0, 100);

  //---------------- DHT22 ----------------

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  //---------------- LDR ----------------

  int light = digitalRead(LDR_PIN);

  //---------------- Print Results ----------------

  Serial.println("----------------------------------------");

  // Moisture

  Serial.print("Soil Moisture: ");
  Serial.print(moisture);
  Serial.print("% ");

  if (moisture < PUMP_ON_LEVEL)
    Serial.println("(LOW)");
  else if (moisture <= PUMP_OFF_LEVEL)
    Serial.println("(OK)");
  else
    Serial.println("(HIGH)");

  // Temperature

  if (!isnan(temperature)) {

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C ");

    if (temperature < 25)
      Serial.println(" | LOW, install Polytunnel / Thermal Mass / Water Drum");
    else if (temperature <= 35)
      Serial.println(" | OK, Good Conditions");
    else
      Serial.println(" | HIGH, install Shade Net / Vent / Water Drum ");
  }

  // Humidity

  if (!isnan(humidity)) {

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("% ");

    if (humidity < 20)
      Serial.println(" | LOW, install Pebble Tray / Spray Mist");
    else if (humidity <= 40)
      Serial.println(" | OK, Good Conditions");
    else
      Serial.println(" | HIGH, install Roof Vent / Increase Spacing");
  }

  // Light

  Serial.print("Light Level: ");

  if (light == HIGH)
    Serial.println(" LOW, Good Conditions");
  else
    Serial.println(" HIGH, install Shade Net / Louvre");

  delay(5000);

  //---------------- Pump Logic ----------------

  if (moisture < PUMP_ON_LEVEL && !pumpState) {
    Serial.println("Pump ON");

    digitalWrite(RELAY_PIN, HIGH);  // Change to LOW if relay is active LOW
    pumpState = true;
    delay(2000);

    digitalWrite(RELAY_PIN, LOW);
    pumpState = false;
    delay(10000);

    // Recheck moisture after soaking
    rawMoisture = analogRead(MOISTURE_PIN);

    moisture = map(rawMoisture,
                   DRY_VALUE,
                   WET_VALUE,
                   0,
                   100);

    moisture = constrain(moisture, 0, 100);

  }

  else if (moisture > PUMP_OFF_LEVEL && pumpState) {
    Serial.println("Pump OFF");

    digitalWrite(RELAY_PIN, LOW);  // Change to HIGH if relay is active LOW
    pumpState = false;
  }

  //-------------- LCD Display ------------------

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("M:");
  lcd.print(moisture);
  lcd.print("%");

  lcd.setCursor(8, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  lcd.setCursor(8,1);
  lcd.print("L:");
  if (light == HIGH)
    lcd.print(" LOW");
  else
    lcd.print(" HIGH");

}
