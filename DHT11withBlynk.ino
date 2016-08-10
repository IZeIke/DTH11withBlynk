#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN D2

DHT dht(DHTPIN,DHTTYPE,30);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "xxxxxxxxxxxxxxxxxxxxx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "xxxxxxxxxx";
char pass[] = "xxxxxxxxxx";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  
}
  
void loop()
{
  Blynk.run();
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if(!isnan(t)&&!isnan(h))
  {
    Blynk.virtualWrite(V1,t);
    Blynk.virtualWrite(V2,h);
  }
}

