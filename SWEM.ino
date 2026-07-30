#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// DHT22 sensor configuration
#define DHTPIN 2
#define DHTTYPE DHT22

// Initialize LCD and DHT sensor
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

// Output pin definitions
#define redPin 11
#define greenPin 12
#define bluePin 13
#define BUZZER 8

void setup() {

  // Configure LED and buzzer pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Turn everything OFF during startup
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(BUZZER, LOW);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize DHT22 sensor
  dht.begin();

  // Boot screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SWEP");
  lcd.setCursor(0, 1);
  lcd.print("Booting..");
  delay(2000);

  // Startup message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INITIALIZING..");
  lcd.setCursor(0, 1);
  lcd.print("Please Wait!!");

  // Startup beep
  tone(BUZZER, 1000);
  delay(1500);
  noTone(BUZZER);

  delay(1500);
  lcd.clear();
}

void loop() {

  // Read temperature and humidity from DHT22
  float temp = dht.readTemperature();
  int hum = dht.readHumidity();

  // Display error if sensor reading fails
  if (isnan(temp) || isnan(hum)) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");

    delay(2000);
    return;
  }

  // Display current temperature
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print(char(223));     // Degree symbol
  lcd.print("C");

  // Display current humidity
  lcd.setCursor(10, 0);
  lcd.print("H:");
  lcd.print(hum);
  lcd.print("%");

  // ----- Temperature Status -----

  // Cold condition
  if (temp < 18) {

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Cold");
  }

  // Cool condition
  else if (temp >= 18 && temp <= 22) {

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Cool");
  }

  // Comfortable temperature
  else if (temp >= 22 && temp <= 30) {

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Comfortable");
  }

  // Warm condition
  else if (temp >= 30 && temp <= 35) {

    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Warm");

    // Short warning beep
    tone(BUZZER, 1000);
    delay(150);
    noTone(BUZZER);
  }

  // High temperature warning
  else if (temp >= 35 && temp <= 40) {

    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);

    lcd.setCursor(0, 1);
    lcd.print("High Temp");

    // Warning beep
    tone(BUZZER, 1000);
    delay(150);
    noTone(BUZZER);
  }

  // Critical temperature
  else if (temp >= 40 && temp <= 49) {

    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Critical");

    // Double beep alert
    tone(BUZZER, 1000);
    delay(250);

    tone(BUZZER, 2000);
    delay(150);

    noTone(BUZZER);
  }

  // Refresh sensor data every 2 seconds
  delay(2000);
}