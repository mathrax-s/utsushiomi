#include <WiFi.h>
#include <WiFiUdp.h>
#include <WiFiMulti.h>
#include <ArduinoOSC.h>

WiFiMulti wifiMulti;

IPAddress ip(192, 168, 11, 28);
IPAddress gateway(192, 168, 11, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress DNS(192, 168, 11, 1);

const char* raspberrypi = "192.168.11.113";
const int port1 = 30000;
const int port2 = 30001;
String osc_address = "/pd";

int RX_PIN = 16;
int TX_PIN = 17;
int RS485 = 18;
int slider = 0;


void setup() {
  Serial.begin(115200);
  Serial2.begin(57600);

  pinMode(RS485, OUTPUT);
  delay(10);

  WiFi.disconnect(true, true);
  delay(1000);
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP("ssid", "password");
  WiFi.config(ip, gateway, subnet, DNS);

  Serial.println("Connecting Wifi...");
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void loop() {
  int buf_a, buf_b;
  digitalWrite(RS485, HIGH);
  Serial2.write('a');
  delayMicroseconds(173);
  digitalWrite(RS485, LOW);
  while (Serial2.available()) {
    buf_a = Serial2.read();
  }
  delay(5);
  digitalWrite(RS485, HIGH);
  Serial2.write('b');
  delayMicroseconds(173);
  digitalWrite(RS485, LOW);
  while (Serial2.available()) {
    buf_b = Serial2.read();
  }
  delay(5);
  if (buf_a > 0) {
    slider = buf_a + 8;
  } else {
    slider = buf_b;
  }
  Serial.println(slider);


  // OSC
  OscWiFi.parse();
  if (buf_b > 0) {
    OscWiFi.send(raspberrypi, port1, osc_address, buf_b);
  }
  if (buf_a > 0) {
    OscWiFi.send(raspberrypi, port2, osc_address, buf_a);
  }
  delay(2);
}
