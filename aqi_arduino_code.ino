#include <LiquidCrystal.h>
#include <DHT.h>

const int analogPin = A0;
const int analogPin1 = A1; 
const int analogPin2 = A2;
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float lpgFactor = 0.04;
float smokeFactor = 0.05;
float coFactor = 0.02;
float h2Factor = 0.03;
float ch4Factor = 0.1; 

const float moderateValue = 100;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  readAndDisplaySensorData();
  displayCH4();
  delay(1000); 
}

void readAndDisplaySensorData() {
  float sensorValue = analogRead(analogPin);

  float lpgLevel = sensorValue * lpgFactor;
  float smokeLevel = sensorValue * smokeFactor;
  float coLevel = sensorValue * coFactor;
  float h2Level = sensorValue * h2Factor;

  float maxGasLevel = max(max(lpgLevel, smokeLevel), max(coLevel, h2Level));
  String gasType = determineGasType(lpgLevel, smokeLevel, coLevel, h2Level, maxGasLevel);

  float aqi = (sensorValue / moderateValue) * 100;
  String airQuality = determineAirQuality(aqi);

  displayGasInfo(gasType, maxGasLevel, sensorValue);
  delay(1000);
  displayAirQuality(airQuality, aqi);
  delay(1000);

  displayDHTSensorData();
}

void displayCH4() {
  float ch4Level = analogRead(analogPin1) * ch4Factor; 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CH4: " + String(ch4Level, 2) + " ppm"); 
}

String determineGasType(float lpg, float smoke, float co, float h2, float maxLevel) {
  if (lpg == maxLevel) return "LPG";
  if (smoke == maxLevel) return "Smoke";
  if (co == maxLevel) return "CO";
  if (h2 == maxLevel) return "Hydrogen";
  return "Unknown";
}

String determineAirQuality(float aqi) {
  if (aqi <= 50) return "Good";
  if (aqi <= 100) return "Satisfactory";
  if (aqi <= 200) return "Moderate";
  if (aqi <= 300) return "Poor";
  if (aqi <= 400) return "Very Poor";
  return "Severe";
}

void displayGasInfo(String gasType, float gasLevel, float sensorValue) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(gasType + ": " + String(gasLevel, 2));
}

void displayAirQuality(String quality, float aqi) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air Quality: " + quality);
  lcd.setCursor(0, 1);
  lcd.print("AQI: " + String(aqi, 2));
}

void displayDHTSensorData() {
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    lcd.clear();
    lcd.print("DHT read error");
    return;
  }

  lcd.clear();
  lcd.print("Hum: " + String(humidity, 1) + "%");
  delay(1000);
  lcd.clear();
  lcd.print("Temp: " + String(tempC, 1) + "C");
  delay(1000);
  lcd.clear();
  lcd.print("Temp: " + String(tempF, 1) + "F");
  delay(1000);
}