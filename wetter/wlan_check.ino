void WLANCheck()
{
    delay(500);
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("WLAN ist aktiv...");
        return;
    }
    WiFi.reconnect();
    delay(1500);
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("WLAN ist getrennt...");
        fehlercode[fehler_ID]=3;
        if (fehler_ID < 99)
        {
            fehler_ID++;
        }
        else
        {
            fehler_ID = 0;
        }
    }
}