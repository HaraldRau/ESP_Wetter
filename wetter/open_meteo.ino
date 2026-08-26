void WetterOpen()//Daten von Open Meteo abrufen
{
  HTTPClient http;
  http.begin(wetter_meteo);
  // http initialisieren

  uint8_t versuch = 0;
  uint8_t httpCode = -1;

  while (httpCode != HTTP_CODE_OK && versuch < 5)
  {
    httpCode = http.GET();
    versuch++;

    if (httpCode == HTTP_CODE_OK)
    {
      // Daten erfolgreich erhalten

      String payload = http.getString();

      // Json-Daten übergeben
      JsonDocument daten;
      deserializeJson(daten, payload);

      // Daten auf die Variablen aufteilen
      hum_o = daten["current"]["relative_humidity_2m"];
      wind_o = daten["current"]["wind_speed_10m"];

      wetter_0 = daten["daily"]["weathercode"][0];
      wetter_1 = daten["daily"]["weathercode"][1];
      wetter_2 = daten["daily"]["weathercode"][2];

      regen_0 = daten["daily"]["precipitation_probability_max"][0];
      regen_1 = daten["daily"]["precipitation_probability_max"][1];
      regen_2 = daten["daily"]["precipitation_probability_max"][2];

      temp_max_0 = daten["daily"]["temperature_2m_max"][0];
      temp_min_0 = daten["daily"]["temperature_2m_min"][0];

      temp_max_1 = daten["daily"]["temperature_2m_max"][1];
      temp_min_1 = daten["daily"]["temperature_2m_min"][1];

      temp_max_2 = daten["daily"]["temperature_2m_max"][2];
      temp_min_2 = daten["daily"]["temperature_2m_min"][2];

      regen_open = daten["daily"]["precipitation_sum"][0];
      regen_m_0 = round(regen_open);

      regen_open = daten["daily"]["precipitation_sum"][1];
      regen_m_1 = round(regen_open);

      regen_open = daten["daily"]["precipitation_sum"][2];
      regen_m_2 = round(regen_open);

      TimeString = daten["current"]["time"].as<String>();

      Serial.print("Open Meteo aktualisiert! ");
      fehlercode[fehler_ID]=0;
      if (fehler_ID < 99)
      {
        fehler_ID++;
      }
      else
      {
        fehler_ID = 0;
      }
      //TimeString.substring(0, 10) -> Datum
      Serial.println(TimeString.substring(11, 16));
      Serial.print(fehler_ID+1);
      Serial.println(" Werte im Fehlerspeicher");
    }
    else
    {
      if (versuch ==1)
      {
        fehlercode[fehler_ID] = 1;

        if (fehler_ID < 99)
        {
          fehler_ID++;
        }
        else
        {
          fehler_ID = 0;
        }
      }   
      Serial.printf("HTTP Fehler: %d\n ", httpCode);
      Serial.println(http.errorToString(httpCode));
      delay(1000);      
    }
  }

  http.end();

  if (httpCode != HTTP_CODE_OK)
  {
    Serial.println("Open Meteo nach 5 Versuchen nicht erreichbar!");
    // Hier Fehlermeldung auf dem Display
    fehlercode[fehler_ID]=2;
    if (fehler_ID < 99)
      {
        fehler_ID++;
      }
      else
      {
        fehler_ID = 0;
      }
  }
}
int Wind(float kmh)//Umrechnung von Wind km/h in Windstärke
{
  if (kmh < 1)
    return 0;
  else if (kmh < 6)
    return 1;
  else if (kmh < 12)
    return 2;
  else if (kmh < 20)
    return 3;
  else if (kmh < 29)
    return 4;
  else if (kmh < 39)
    return 5;
  else if (kmh < 50)
    return 6;
  else if (kmh < 62)
    return 7;
  else if (kmh < 75)
    return 8;
  else if (kmh < 89)
    return 9;
  else if (kmh < 103)
    return 10;
  else if (kmh < 118)
    return 11;
  else
    return 12;
}