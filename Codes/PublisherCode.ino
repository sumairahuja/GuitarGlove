#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"


 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

 
// WiFi parameters
const char* WLAN_SSID = "Makers Asylum"; //ssid of the wifi you want to connect with
const char* WLAN_PASS = "Makeithappen"; //password of the wifi
 
 
// Adafruit IO
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
//Enter the username and key from the Adafruit IO
#define AIO_USERNAME    "Kritarth08"
#define AIO_KEY         "***" 


WiFiClient client;
// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish ultrasonic = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/ultrasonic");


float duration; //to store the temperature value
float distance; // to store the humidity value


void setup() {
  Serial.begin(115200);
  
 
  pinMode(D6, OUTPUT);
  pinMode(D5, INPUT);
  Serial.println(F("Adafruit IO Example"));
  // Connect to WiFi access point.

  delay(2000);
  
  delay(10);
  Serial.print(F("Connecting to "));
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
    
  }
  Serial.println();
  Serial.println(F("WiFi connected"));
  Serial.println(F("IP address: "));
  Serial.println(WiFi.localIP());
 
  // connect to adafruit io
  connect();
 
}
 
// connect to adafruit io via MQTT
void connect() {
  Serial.print(F("Connecting to Adafruit IO... "));
  int8_t ret;
  while ((ret = mqtt.connect()) != 0) {
    switch (ret) {
      case 1: Serial.println(F("Wrong protocol")); break;
      case 2: Serial.println(F("ID rejected")); break;
      case 3: Serial.println(F("Server unavail")); break;
      case 4: Serial.println(F("Bad user/pass")); break;
      case 5: Serial.println(F("Not authed")); break;
      case 6: Serial.println(F("Failed to subscribe")); break;
      default: Serial.println(F("Connection failed")); break;
    }
 
    if(ret >= 0)
      mqtt.disconnect();
 
    Serial.println(F("Retrying connection..."));
    delay(10000);
  }
  Serial.println(F("Adafruit IO Connected!"));
}
 
void loop() {
  // ping adafruit io a few times to make sure we remain connected
  
 
  if(! mqtt.ping(3)) {
    // reconnect to adafruit io
    if(! mqtt.connected())
      connect();
  }
  digitalWrite(D6, LOW);
  delayMicroseconds(2);
  digitalWrite(D6, HIGH);
  delayMicroseconds(10);
  digitalWrite(D6, LOW);

  duration = pulseIn(D5, HIGH);
  distance = (duration * .0343) / 2;

  Serial.print("");
  Serial.println(distance);
 
  delay(2000);
   
   if (! ultrasonic.publish(distance)) {                     //Publish to Adafruit
      Serial.println(F("Failed"));
    } else {
      Serial.println(F("Sent!"));
    }    
}
    
