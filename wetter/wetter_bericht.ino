void Bericht()
{
  //Temperatur DS18Innen
  tft.setTextFont(7);
  tft.setTextSize(2);
  tft.setCursor(0, 0);
  tft.print(int(round(temp_i)));
  //Temperatur BME 180
  tft.setCursor(192,0);
  if (temp_a < 0)
  {
    tft.setCursor(128,0);
  }
  tft.print(int(round(temp_a)));
  //Daten Open Meteo
  tft.setCursor(0,100);
  tft.setTextFont(4);
  tft.setTextSize(1);
  tft.print(temp_min_0);
  tft.print("|");
  tft.print(temp_max_0);
  tft.setCursor(110,100);
  //zweiter Tag MinMax
  tft.print(temp_min_1);
  tft.print("|");
  tft.print(temp_max_1);
  tft.setCursor(220,100);
  tft.print(temp_min_2);
  tft.print("|");
  tft.print(temp_max_2);

}