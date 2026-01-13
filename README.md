# Arduino DHT22 Temperature and Humidity Monitor

This project reads temperature and humidity from a DHT22 sensor and displays the values on a 16x2 LCD display using an Arduino Uno.

## Components Required

- Arduino Uno
- DHT22 Temperature/Humidity Sensor
- 16x2 LCD Display
- 10kΩ resistor (for DHT22 pull-up)
- Breadboard
- Jumper wires

## Wiring Connections

### DHT22 Sensor:
- VCC → 5V on Arduino
- GND → GND on Arduino
- DATA → Digital Pin 2 on Arduino (with 10kΩ pull-up resistor to VCC)

### 16x2 LCD Display (using 4-bit mode):
- VSS → GND
- VDD → 5V
- V0 → Middle pin of potentiometer (for contrast adjustment)
- RS → Digital Pin 12
- Enable → Digital Pin 11
- D4 → Digital Pin 5
- D5 → Digital Pin 4
- D6 → Digital Pin 3
- D7 → Digital Pin 6
- A → 5V (backlight anode)
- K → GND (backlight cathode)

## Libraries Used

- DHT sensor library by Adafruit
- Adafruit Unified Sensor library
- LiquidCrystal library

## Features

- Real-time temperature and humidity readings
- Displays temperature in Celsius with degree symbol
- Shows humidity percentage
- Serial monitor output for debugging
- Error handling for sensor failures

## Usage

1. Install PlatformIO extension in your IDE (VSCode, Atom, etc.)
2. Open this project folder in PlatformIO
3. Connect your hardware according to the wiring diagram above
4. Upload the code to your Arduino Uno using PlatformIO
5. View the temperature and humidity readings on the LCD display

## Notes

- The DHT22 sensor requires at least 2 seconds between readings
- The LCD is configured in 4-bit mode to save digital pins
- Serial monitor baud rate is set to 9600