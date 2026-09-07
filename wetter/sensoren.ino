void DS18Aussen()//Daten vom DS18Aussen abrufen
{
  Aussen.requestTemperatures();
  delay(500);
  temp_a = Aussen.getTempCByIndex(0);
  if (temp_a == DEVICE_DISCONNECTED_C)
  {
  temp_a = Innen.getTempCByIndex(0);
  }
}

void DS18Innen()//Daten vom DS18Innen abrufen
{
  Innen.requestTemperatures();
  delay(500);
  temp_i = Innen.getTempCByIndex(0)-2;
  if (temp_i == DEVICE_DISCONNECTED_C)
  {
  temp_i = Innen.getTempCByIndex(0)-2;
  }
}