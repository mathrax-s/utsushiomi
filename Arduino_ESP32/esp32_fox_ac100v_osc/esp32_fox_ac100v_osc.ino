#include <WiFi.h>
#include <WiFiUdp.h>
#include <WiFiMulti.h>
#include <ArduinoOSC.h>

WiFiMulti wifiMulti;

IPAddress ip(192, 168, 11, 200);
IPAddress gateway(192, 168, 11, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress DNS(192, 168, 11, 1);

const int port = 10000;
String osc_address = "/ac100v";

int SSR = 18;


void setup() {
  Serial.begin(115200);
  pinMode(SSR, OUTPUT);
  digitalWrite(SSR, LOW);
  delay(10);

  WiFi.disconnect(true, true);
  delay(1000);
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP("ssid", "passwd");
  WiFi.config(ip, gateway, subnet, DNS);

  Serial.println("Connecting Wifi...");
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }

  OscWiFi.subscribe(port, "/ac100v",
                    [&](const float & f)
  { 
    if (f == 1) {
      digitalWrite(SSR, HIGH);
    } else if (f == 0) {
      digitalWrite(SSR, LOW);
    }
    Serial.print("/ac100v ");
    Serial.print(f);
    Serial.println();
  }
                   );
}

void loop() {
  // OSC
  OscWiFi.update();
  //  delay(50);
}
