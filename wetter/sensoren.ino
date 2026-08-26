void BME180()//Daten vom BME280 abrufen
{
  temp_i = int(bme.readTemperature());
  druck = int(bme.readPressure() / 100);
}

void SD18()//Daten vom SD18 abrufen
{
  sensors.requestTemperatures();
  delay(1000);
  temp_a = sensors.getTempCByIndex(0);
  if (temp_a == DEVICE_DISCONNECTED_C)
  {
    temp_a = sensors.getTempCByIndex(0);
  }
}