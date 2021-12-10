/*Este es un comentario para probar la creación de ramas 
Este codígo es realizado por SantiLoz*/
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#ifndef STASSID
#define STASSID "Claro_LOZADASANTIAGO_EXT"
#define STAPSK  "974847937588"
#endif
#define up D1
#define down D2
#define left D3
#define right D5

unsigned int localPort = 8888;   
int comando;
WiFiUDP Udp;

void setup() {
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  Serial.printf("UDP server on port %d\n", localPort);
  Udp.begin(localPort);
}


int lectura(){
int packetSize = Udp.parsePacket();
  if (packetSize) {
    int n=Udp.read();
  }

}

void loop() {
  
comado= lectura();


}
