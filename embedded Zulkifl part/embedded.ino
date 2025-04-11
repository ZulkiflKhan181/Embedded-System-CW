
Uncommented Parts done by zulkifl

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SD.h>  // SD card re-enabled

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27

String lastStatus = "";
int lastPercentage = -1;

const int RELAY_PIN = 2;
const int SOIL_SENSOR_PIN = A0;
const int SD_CS_PIN = 10;

File logFile;  // SD logging re-enabled

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Pump off (relay is active-low)

  lcd.setCursor(0, 0);
  lcd.print(F("IRRIGATION"));
  lcd.setCursor(0, 1);
  lcd.print(F("SYSTEM IS ON"));
  delay(3000);
  lcd.clear();

  /* SD card initialization
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println(F("SD card initialization failed!"));
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("SD Init Failed!"));
    while (true); // Halt if SD init fails
  } else {
    Serial.println(F("SD card ready."));
    lcd.setCursor(0, 0);
    lcd.print(F("SD Init Success"));
    delay(1500);
    lcd.clear();
  }
*/
  /* Create/open the log file and write header if it doesn't exist
  if (!SD.exists("log.csv")) {
    logFile = SD.open("log.csv", FILE_WRITE);
    if (logFile) {
      logFile.println(F("Time(ms),Moisture(%),Status"));
      logFile.close();
    }
  }
}
*/
void loop() {
  int value = analogRead(SOIL_SENSOR_PIN);
  int percentage = map(value, 0, 1023, 100, 0); // Dry = 0%, Wet = 100%

  Serial.print(F("Analog: "));
  Serial.print(value);
  Serial.print(F(" => Moisture: "));
  Serial.print(percentage);
  Serial.println(F("%"));
/*
  String status = "";

  if (percentage > 70) {
    status = "HIGH";
    digitalWrite(RELAY_PIN, HIGH); // Pump OFF
  } else if (percentage > 30) {
    status = "MID";
    digitalWrite(RELAY_PIN, LOW);  // Pump ON
  } else {
    status = "LOW";
    digitalWrite(RELAY_PIN, LOW);  // Pump ON
  }
*/
  if (status != lastStatus || percentage != lastPercentage) {
    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Moist: "));
    lcd.print(percentage);
    lcd.print(F("% "));

    lcd.setCursor(0, 1);
    if (status == "HIGH") {
      lcd.print(F("Pump OFF (Wet)"));
    } else {
      lcd.print(F("Pump ON (Dry)"));
    }

    /* Log to SD card
    logFile = SD.open("log.csv", FILE_WRITE);
    if (logFile) {
      logFile.print(millis());
      logFile.print(F(","));
      logFile.print(percentage);
      logFile.print(F(","));
      logFile.println(status);
      logFile.close();
    } else {
      Serial.println(F("Failed to open log file!"));
    }

    lastStatus = status;
    lastPercentage = percentage;
  }
*/
  delay(1000);
}
