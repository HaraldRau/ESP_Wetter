void WetterCode(int code, int tag)
{
  if (code < 3)//volle Sonne
{
  Sonne(tag);
}
else if (code < 48)//leicht Bewölkt
{
  Sonne(tag);
  Wolke(tag);
}
else if (code < 64)//leichter Regen
{
  Wolke(tag);
  Niesel(tag);
}
else if (code < 65)//Regen
{
  Wolke(tag);
  Regen(tag);
}
else if (code < 64)//starker Regen
{
  Wolke(tag);
  Niesel(tag);
  Regen(tag);
}
else
{
  Wolke(tag);
  Niesel(tag);
  Regen(tag);
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
