void MinMax()
{
  tft.setTextFont(4);
  tft.setTextSize(2);
  tft.setCursor(0,0);
  tft.print(temp_min_0);
  tft.setCursor(110,0);
  tft.print(temp_min_1);
  tft.setCursor(220,0);
  tft.println(temp_min_2);
  tft.setCursor(0,60);
  tft.print(temp_max_0);
  tft.setCursor(110,60);
  tft.print(temp_max_1);
  tft.setCursor(220,60);
  tft.println(temp_max_2);
  tft.setTextFont(7);
  tft.setTextSize(1);
  tft.setCursor(80,150);
  tft.print(TimeString.substring(11, 16));
}