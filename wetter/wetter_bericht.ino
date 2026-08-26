void Bericht()
{
  //Temperatur SD18
  tft.setTextFont(7);
  tft.setTextSize(2);
  tft.setCursor(0, 0);
  tft.print(int(temp_i));
  //Temperatur BME 180
  tft.setCursor(180,0);
  tft.print(temp_a);
  //Daten Open Meteo
  /* Wind 65 Pixel
  Luftdruck 106 Pixel
  Zu beachten beim Setzen des Corsors
  */
  tft.setCursor(0,100);
  tft.setTextFont(4);
  tft.setTextSize(1);
  tft.print(hum_o);
  tft.print("%");
  tft.setCursor(110,100);
  tft.print(druck);
  tft.print("hPa");
  tft.setCursor(220,100);
  tft.print(Wind(wind_o));
  tft.print("Bft");

}