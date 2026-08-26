void debug()
{
  Serial.print("Beginn Fehlercode-");
    for (int i=fehler_ID; i >= 0; i--)
    {
      Serial.print(fehlercode[i]);
    }
  Serial.println("-Ende Fehlercode");
}