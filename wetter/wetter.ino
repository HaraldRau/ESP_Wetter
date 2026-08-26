/*
#########################################################################
###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
#########################################################################

#define TFT_WIDTH  240
#define TFT_HEIGHT 320

#define TFT_MOSI 23
#define TFT_SCLK 18

#define TFT_CS   5
#define TFT_DC   4
#define TFT_RST  2



DS18B20
GND  ---------- GND
DQ   ---------- GPIO 27
VDD  ---------- 3,3 V
*/

#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 27
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//Variablen Wetterdaten vorbefüllt mit Datenm vom 25.08.26 
int hum_o = 84;
int wind_o = 9;
int temp_i = 22;
int temp_a = 19;
int wetter_0 = 3;
int wetter_1 = 3;
int wetter_2 = 3;
int regen_0 = 0;
int regen_1 = 3;
int regen_2 = 0;
float regen_open;
int regen_m_0 = 0;
int regen_m_1 = 0;
int regen_m_2 = 0;
int temp_max_0 = 24;
int temp_min_0 = 13;
int temp_max_1 = 24;
int temp_min_1 = 14;
int temp_max_2 = 26;
int temp_min_2 = 14;
int druck = 1014;
uint8_t fehlercode[100];
uint8_t fehler_ID = 0;
String TimeString = "2026-08-24T14:00";

TFT_eSPI tft = TFT_eSPI();
Adafruit_BME280 bme; // I2C
const char* ssid = "PDP-1";
const char* password = "3314#7640@8613*6319+";
const char wetter_meteo[] = "https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&current=relative_humidity_2m,wind_speed_10m,surface_pressure&daily=weathercode,temperature_2m_max,temperature_2m_min,precipitation_probability_max,precipitation_sum&timezone=auto";


void setup() {
  tft.init();
  tft.setRotation(1);      // 1 und 3 Querformat (2 und 4 Hochformat)
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextFont(2);

  pinMode(25, INPUT_PULLUP);
  sensors.begin();
  Serial.begin(115200);
  
  tft.println("Wetter 0.8 Bootvorgang ...");

  delay(500);// Version anzeigen

  if (!bme.begin(0x76))
  {
    Serial.println("BME280 nicht gefunden!");
    }
  else
  {
    tft.println("Innensensor BME 280 gefunden!");
    }

  delay(500);// Innensensor initialisieren

  if (sensors.getDeviceCount() > 0)
  {
    tft.println("Aussensensor DS18B20 gefunden!");
    }
  else
  {
    tft.println("Aussensensor nicht gefunden!");
    }

  delay(500);// Aussensensor initialisieren

  WiFi.begin(ssid, password);
  int versuch = 0;
  while (WiFi.status() != WL_CONNECTED && versuch < 10)
  {
    delay(500);
    tft.print("# ");
    versuch++;
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    tft.println("Mit PDP1 verbunden...");
  }
  else
  {
    tft.println("Demomodus...");
    }

  delay(500);// WLAN verbinden

  tft.print("Bootvorgang abgeschlossen ...");

  delay(500);// Bootvorgang abschließen

}
void loop()
{
  tft.fillScreen(TFT_BLACK);
  //WLANCheck();
  BME180();
  SD18();
  WetterOpen();
  MinMax();
  delay(5000);
  tft.fillScreen(TFT_BLACK);
  Bericht();
  Vorschau();
  delay(1000);
  debug();
  delay(3000);
  esp_sleep_enable_timer_wakeup(3600000000ULL);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_25, 0);
  esp_light_sleep_start();
}