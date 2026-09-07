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



DS18AussenB20
GND  ---------- GND
DQ   ---------- GPIO 27
VDD  ---------- 3,3 V

DS18InnenB20
GND  ---------- GND
DQ   ---------- GPIO 26
VDD  ---------- 3,3 V

*/

#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <OneWire.h>
#include <DallasTemperature.h>
//#include <esp_system.h>

const int blitz[][2] = {
  {33, 161},  {32, 162},  {33, 162},  {34, 162},  {31, 163},  {32, 163},  {33, 163},  {34, 163},  {30, 164},  {31, 164},  {32, 164},  {33, 164},  {34, 164},  {31, 165},  {32, 165},  {33, 165},
  {34, 165},  {31, 166},  {32, 166},  {33, 166},  {34, 166},  {35, 166},  {31, 167},  {32, 167},  {33, 167},  {34, 167},  {35, 167},  {32, 168},  {33, 168},  {34, 168},  {35, 168},  {32, 169},
  {33, 169},  {34, 169},  {35, 169},  {32, 170},  {33, 170},  {34, 170},  {35, 170},  {36, 170},  {33, 171},  {34, 171},  {35, 171},  {36, 171},  {45, 171},  {33, 172},  {34, 172},  {35, 172},
  {36, 172},  {44, 172},  {45, 172},  {46, 172},  {33, 173},  {34, 173},  {35, 173},  {36, 173},  {37, 173},  {43, 173},  {44, 173},  {45, 173},  {46, 173},  {34, 174},  {35, 174},  {36, 174},
  {37, 174},  {42, 174},  {43, 174},  {44, 174},  {45, 174},  {46, 174},  {47, 174},  {34, 175},  {35, 175},  {36, 175},  {37, 175},  {41, 175},  {42, 175},  {43, 175},  {44, 175},  {45, 175},
  {46, 175},  {47, 175},  {35, 176},  {36, 176},  {37, 176},  {38, 176},  {40, 176},  {41, 176},  {42, 176},  {43, 176},  {46, 176},  {47, 176},  {35, 177},  {36, 177},  {37, 177},  {38, 177},
  {39, 177},  {40, 177},  {41, 177},  {42, 177},  {46, 177},  {47, 177},  {48, 177},  {35, 178},  {36, 178},  {37, 178},  {38, 178},  {39, 178},  {40, 178},  {41, 178},  {47, 178},  {48, 178},
  {49, 178},  {35, 179},  {36, 179},  {37, 179},  {38, 179},  {39, 179},  {47, 179},  {48, 179},  {49, 179},  {36, 180},  {37, 180},  {38, 180},  {48, 180},  {49, 180},  {37, 181},  {48, 181},
  {49, 181},  {50, 181},  {49, 182},  {50, 182},  {49, 183},  {50, 183},  {51, 183},  {50, 184},  {51, 184},  {50, 185},  {51, 185},  {52, 185},  {51, 186},  {52, 186},  {51, 187},  {52, 187},
  {53, 187},  {52, 188},  {53, 188},  {52, 189},  {53, 189},  {54, 189},  {60, 189},  {53, 190},  {54, 190},  {59, 190},  {60, 190},  {54, 191},  {55, 191},  {58, 191},  {59, 191},  {60, 191},
  {54, 192},  {55, 192},  {57, 192},  {58, 192},  {59, 192},  {60, 192},  {54, 193},  {55, 193},  {56, 193},  {57, 193},  {58, 193},  {59, 193},  {60, 193},  {54, 194},  {55, 194},  {56, 194},
  {57, 194},  {58, 194},  {59, 194},  {60, 194},  {54, 195},  {55, 195},  {56, 195},  {57, 195},  {58, 195},  {59, 195},  {60, 195},  {53, 196},  {54, 196},  {55, 196},  {56, 196},  {57, 196},
  {58, 196},  {59, 196},  {60, 196},  {52, 197},  {53, 197},  {54, 197},  {55, 197},  {56, 197},  {57, 197},  {58, 197},  {59, 197},  {60, 197},  {51, 198},  {52, 198},  {53, 198},  {54, 198},
  {55, 198},  {56, 198},  {57, 198},  {58, 198},  {59, 198},  {60, 198},  {50, 199},  {51, 199},  {52, 199},  {53, 199},  {54, 199},  {55, 199},  {56, 199},  {57, 199},  {58, 199},  {59, 199},
  {60, 199},};


OneWire oneWireAussen(27);
DallasTemperature Aussen(&oneWireAussen);

OneWire oneWireInnen(26);
DallasTemperature Innen(&oneWireInnen);

//Variablen Wetterdaten vorbefüllt mit Daten vom 25.08.26 
int temp_o = 20;
int hum_o = 84;
int wind_o = 9;
float temp_i = 22;
float temp_a = 19;
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
const char* ssid = "PDP-1";
const char* password = "3314#7640@8613*6319+";
const char wetter_meteo[] = "https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&current=temperature_2m,relative_humidity_2m,wind_speed_10m,surface_pressure&daily=weathercode,temperature_2m_max,temperature_2m_min,precipitation_probability_max,precipitation_sum&timezone=auto";


void setup() {
  //Serial.print("Reset-Grund: ");
  //Serial.println(esp_reset_reason());
  tft.init();
  tft.setRotation(1);      // 1 und 3 Querformat (2 und 4 Hochformat)
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextFont(2);

  pinMode(25, INPUT_PULLUP);
  Innen.begin();
  Aussen.begin();
  Serial.begin(115200);
  
  tft.println("Wetter 0.9 Bootvorgang ...");

  delay(500);// Version anzeigen

  if (Aussen.getDeviceCount() > 0)
  {
    tft.println("Aussensensor DS18InnenB20 gefunden!");
    }
  else
  {
    tft.println("Aussensensor nicht gefunden!");
    }

  delay(500);// Innensensor initialisieren

  if (Innen.getDeviceCount() > 0)
  {
    tft.println("Innensensor DS18InnenB20 gefunden!");
    }
  else
  {
    tft.println("Innensensor nicht gefunden!");
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
  DS18Aussen();
  DS18Innen();
  delay(1000);
  WetterOpen();
  MinMax();
  delay(5000);
  tft.fillScreen(TFT_BLACK);
  Bericht();
  Vorschau();
  debug();
  delay(2000);
  esp_sleep_enable_timer_wakeup(3600000000ULL);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_25, 0);
  esp_light_sleep_start();
}