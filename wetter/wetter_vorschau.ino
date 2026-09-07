void WetterCode(int code, int tag)
{
  if (code == 0)                         // Volle Sonne
  {
    Sonne(tag);
  }

  else if (code >= 1 && code <= 3)      // Bewölkt
  {
    Sonne(tag);
    Wolke(tag);
  }

  else if (code >= 45 && code <= 48)    // Nebel
  {
    Wolke(tag);
  }

  else if (code >= 51 && code <= 61)    // Niesel / leichter Regen
  {
    Wolke(tag);
    Niesel(tag);
  }

  else if (code >= 63 && code <= 67)    // Starker Regen
  {
    Wolke(tag);
    Regen(tag);
  }

  else if (code >= 71 && code <= 77)    // Leichter Schnee
  {
    Wolke(tag);
    Schnee(tag);
  }

  else if (code >= 80 && code <= 82)    // Starke Regenschauer
  {
    Wolke(tag);
    Regen(tag);
    Niesel(tag);
  }

  else if (code >= 85 && code <= 86)    // Schneeschauer
  {
    Wolke(tag);
    Schnee(tag);
  }

  else if (code >= 95 && code <= 99)    // Gewitter
  {
    Wolke(tag);
    Regen(tag);
    Blitz(tag);
  }

  else                                  // unbekannter Code
  {
    Wolke(tag);
  }
}
void Vorschau()
{
  //Wettersymbole
  WetterCode(wetter_0,0);
  WetterCode(wetter_1,1);
  WetterCode(wetter_2,2);
  //Regenwahrscheinlichkeit
  tft.setCursor(0,220);
  tft.setTextFont(4);
  tft.setTextSize(1);
  tft.print(regen_0);
  tft.print("% ");
  tft.print(regen_m_0);
  tft.print("L");
  tft.setCursor(110,220);
  tft.print(regen_1);
  tft.print("% ");
  tft.print(regen_m_1);
  tft.print("L");
  tft.setCursor(220,220);
  tft.print(regen_2);
  tft.print("% ");
  tft.print(regen_m_2);
  tft.print("L");
}
