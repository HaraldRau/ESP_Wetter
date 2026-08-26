void Sonne(int tag)
{
  int x = tag * 110;

  // Sonnenkreis
  tft.fillCircle(x + 25, 160, 20, tft.color565(35, 222, 221));

  // Sonnenstrahlen
  tft.drawLine(x + 25, 160, x + 0, 170, tft.color565(35, 222, 221));
  tft.drawLine(x + 25, 160, x + 0, 190, tft.color565(35, 222, 221));
  tft.drawLine(x + 25, 160, x + 0, 210, tft.color565(35, 222, 221));
  tft.drawLine(x + 25, 160, x + 20, 210, tft.color565(35, 222, 221));
  tft.drawLine(x + 25, 160, x + 40, 210, tft.color565(35, 222, 221));
  tft.drawLine(x + 25, 160, x + 60, 210, tft.color565(35, 222, 221));
  tft.drawLine(x + 25, 160, x + 80, 210, tft.color565(35, 222, 221));
  tft.drawLine(x + 25, 160, x + 100, 210, tft.color565(35, 222, 221));
  tft.drawLine(x + 25, 160, x + 100, 190, tft.color565(35, 222, 221));
  tft.drawLine(x + 25, 160, x + 100, 170, tft.color565(35, 222, 221));
}

void Wolke(int tag)
{
  int x = tag * 110;

  // Wolkenkreise
  tft.fillCircle(x + 30, 160, 15, tft.color565(255, 145, 0));
  tft.fillCircle(x + 50, 155, 20, tft.color565(225, 145, 0));
  tft.fillCircle(x + 70, 160, 15, tft.color565(225, 145, 0));

}

void Regen(int tag)
{
  int x = tag * 110;

  // Regen
  tft.drawLine(x + 70, 170, x + 80, 200, tft.color565(255, 145, 0));
  tft.drawLine(x + 60, 170, x + 70, 200, tft.color565(255, 145, 0));
  tft.drawLine(x + 50, 170, x + 60, 200, tft.color565(255, 145, 0));
  tft.drawLine(x + 40, 170, x + 50, 200, tft.color565(255, 145, 0));
}

void Niesel(int tag)
{
  int x = tag * 110;

  // Regen
  tft.drawLine(x + 65, 170, x + 71, 190, tft.color565(255, 145, 0));
  tft.drawLine(x + 55, 170, x + 61, 190, tft.color565(255, 145, 0));
  tft.drawLine(x + 45, 170, x + 51, 190, tft.color565(255, 145, 0));
  tft.drawLine(x + 35, 170, x + 41, 190, tft.color565(255, 145, 0));
}