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

void Blitz(int tag)
{
  int x = tag * 110;

  for (int i = 0;i < 224;i++)
  {
    tft.drawPixel(blitz[i][0]+x, blitz[i][1], tft.color565(35, 222, 221));
  }
}

void Schnee(int tag)
{
int x = tag * 110;
  // drei Schneesterne unterhalb der Wolke
  // Stern 1
  tft.drawLine(x + 25, 188, x + 25, 202, TFT_WHITE);
  tft.drawLine(x + 19, 195, x + 31, 195, TFT_WHITE);
  tft.drawLine(x + 20, 190, x + 30, 200, TFT_WHITE);
  tft.drawLine(x + 30, 190, x + 20, 200, TFT_WHITE);

  // Stern 2
  tft.drawLine(x + 50, 188, x + 50, 202, TFT_WHITE);
  tft.drawLine(x + 44, 195, x + 56, 195, TFT_WHITE);
  tft.drawLine(x + 45, 190, x + 55, 200, TFT_WHITE);
  tft.drawLine(x + 55, 190, x + 45, 200, TFT_WHITE);

  // Stern 3
  tft.drawLine(x + 75, 188, x + 75, 202, TFT_WHITE);
  tft.drawLine(x + 69, 195, x + 81, 195, TFT_WHITE);
  tft.drawLine(x + 70, 190, x + 80, 200, TFT_WHITE);
  tft.drawLine(x + 80, 190, x + 70, 200, TFT_WHITE);
}

void Schneesturm(int tag)
{
  int x = tag * 110;
  // Stern oben1
  tft.drawLine(x + 37, 171, x + 37, 185, TFT_WHITE);
  tft.drawLine(x + 31, 178, x + 43, 178, TFT_WHITE);
  tft.drawLine(x + 32, 173, x + 42, 183, TFT_WHITE);
  tft.drawLine(x + 42, 173, x + 32, 183, TFT_WHITE);

  // Stern oben2
  tft.drawLine(x + 63, 171, x + 63, 185, TFT_WHITE);
  tft.drawLine(x + 57, 178, x + 69, 178, TFT_WHITE);
  tft.drawLine(x + 58, 173, x + 68, 183, TFT_WHITE);
  tft.drawLine(x + 68, 173, x + 58, 183, TFT_WHITE);
}