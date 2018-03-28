#include <WiFi.h>

void event(WiFiEvent_t event){
  switch(event) {
    case SYSTEM_EVENT_AP_STACONNECTED:
    Serial.println("WIFI - AP STACONNECTED");
    break;
    case SYSTEM_EVENT_AP_START:
    Serial.println("WIFI - AP START");
    break;
    case SYSTEM_EVENT_AP_STOP:
    Serial.println("WIFI - AP STOP");
    break;
    case SYSTEM_EVENT_AP_STADISCONNECTED:
    Serial.println("WIFI - AP STADISCONNECTED");
    break;
    case SYSTEM_EVENT_STA_START:
    Serial.println("WIFI - STA START");
    break;
    case SYSTEM_EVENT_STA_STOP:
    Serial.println("WIFI - STA STOP");
    break;
    case SYSTEM_EVENT_STA_LOST_IP:
    Serial.println("WIFI - STA LOST IP");
    break;
    case SYSTEM_EVENT_WIFI_READY:
    Serial.println("WIFI - WIFI READY");
    break;
    case SYSTEM_EVENT_ETH_GOT_IP:
    Serial.println("WIFI - ETH GOT IP");
    break;
    case SYSTEM_EVENT_STA_GOT_IP:
    Serial.println("WIFI - STA GOT IP");
    break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
    Serial.println("WIFI - STA DISCONNECTED");
    break;
  }
}



void setup(){
  Serial.begin(9600);
  WiFi.mode(WIFI_MODE_APSTA);
  WiFi.onEvent(event);
  WiFi.begin("xyz","password");
  WiFi.softAP("AccesPoint", "accesPointpassword");
  WiFi.setAutoConnect(true);
  WiFi.setAutoReconnect(true);
}


void loop(){


  if(millis() > 10000){
  Serial.println("WIFI - ACCESS POINT");
  Serial.println("HOSTNAME:   " + String(WiFi.softAPgetHostname()));
  // Serial.println("STATIONS:   " + WiFi.softAPgetStationNum());
  // Serial.println("IP:         " + WiFi.softAPIP());
  // Serial.println("MAC ADRESS: " + WiFi.softAPmacAddress());

  Serial.println("WIFI - STATION");
  Serial.println("HOSTNAME:    " + String(WiFi.getHostname()));
  Serial.println("BSSID:       " + WiFi.BSSIDstr());
  Serial.println("CHANNEL:     " + WiFi.channel());
  Serial.println("SSID:        " + WiFi.SSID());
  Serial.println("IP:          " + WiFi.localIP().toString());
  Serial.println("MAC ADDRESS: " + WiFi.macAddress());
  Serial.println("SUBNET MASK: " + WiFi.subnetMask().toString());
  Serial.println("GATEWAY:     " + WiFi.gatewayIP().toString());


  long days=0;
  long hours=0;
  long mins=0;
  long secs=0;
  secs = millis()/1000;
  mins=secs/60;
  hours=mins/60;
  days=hours/24;
  secs=secs-(mins*60);
  mins=mins-(hours*60);
  hours=hours-(days*24);
  Serial.println("UPTIME:      " + String(days) +  ":days " + String(hours) + ":hours " + String(mins) + ":minutes " + String(secs) + ":seconds");
  /**
  * @TODO add uptime
  */
}
delay(20000);
}
