void WetterPlus()
{
  tft.setTextFont(4);
  tft.setTextSize(1);
  tft.setCursor(0,10);
  tft.print(hum_o);
  tft.print(" %");
  tft.setCursor(160,10);
  tft.print(druck);
  tft.print(" hPa");
  tft.setCursor(0,60);
  tft.print(temp_o);
  tft.print(" °C");
  tft.setCursor(160,60);
  tft.print(wind_o);
  tft.print(" km/h");
  tft.setCursor(80,120);
  tft.setTextFont(7);
  tft.print(TimeString.substring(11, 16));
}
