
//#include <WiFiClient.h>
//#include <WiFi.h>
//#include <WiFiUdp.h>
//#include <WiFiServer.h>


#include "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"
#include "NTPClient.h"
#include "WiFiUdp.h"

const char* ssid = "martajavi_2.4"; //Enter SSID
const char* password = "cafecafe00#"; //Enter Password
String url = "http://www.google.com";

WiFiUDP ntpUDP;
// By default 'pool.ntp.org' is used with 60 seconds update interval and
// no offset
//NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;


// You can specify the time server pool and the offset, (in seconds)
// additionaly you can specify the update interval (in milliseconds).
// NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();

  
  Serial.print(timeClient.getHours());
  Serial.println(timeClient.getMinutes());

  delay(1000);
}
