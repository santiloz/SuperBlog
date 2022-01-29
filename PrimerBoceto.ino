/*Este es un comentario para probar la creación de ramas 
Este codígo es realizado por SantiLoz*/
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#ifndef STASSID
#define STASSID "Claro_LOZADASANTIAGO_EXT"
#define STAPSK  "974847937588"
#endif
#define in1 D1
#define in2 D2
#define in3 D3
#define in4 D4
#define ena D5
#define enb D6

unsigned int localPort = 8888;   
int n;
WiFiUDP Udp;
int velocidad;
void setup() {
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
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  velocidad=125;
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
}

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
      n=Udp.read();

     if(n==97){//avanzar
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
            if (velocidad<255){velocidad=velocidad+1;}
            anlogWrite(ena,velocidad);
      }

      if(n==98){//retroceder
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      velocidad=155;
      anlogWrite(ena,155)
      }

      if(n==100){//derecha
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      }

      if(n==99){//derecha
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
      }

      
      
  }

}