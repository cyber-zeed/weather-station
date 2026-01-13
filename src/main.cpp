#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal.h>

// Define pins
#define DHT_PIN 2          // DHT22 sensor connected to digital pin 2
#define DHT_TYPE DHT22     // DHT 22 (AM2302)

// Initialize DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

// Initialize the library with the numbers of the interface pins
// RS, Enable, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize DHT sensor
  dht.begin();
  
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  
  // Print initial message
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read humidity and temperature from DHT22
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius
  
  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    delay(1000);
    return;
  }
  
  // Display temperature on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223); // Degree symbol
  lcd.print("C");
  
  // Display humidity on LCD
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print("%");
  
  // Print to serial monitor as well
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  Serial.println();
  
  // Wait before next reading (DHT22 needs at least 2 seconds between readings)
  delay(2000);
}