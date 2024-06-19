#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <Adafruit_NeoPixel.h>
#define PIN1 D1
#define PIN2 D2
#define PIN3 D3
#define PIN4 D4
int i=0;
int k=0;

/************************* WiFi Access Point *********************************/

const char* ssid = "Makers Asylum"; //ssid of the wifi you want to connect with
const char* pass = "Makeithappen"; //password of the wifi


/************************* Adafruit.io Setup *********************************/
#define NUMPIXELS 6 
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "Kritarth08"
#define AIO_KEY         "***"

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(NUMPIXELS, PIN4, NEO_GRBW + NEO_KHZ800);

/****************************** Feeds ***************************************/

// Setup a feed called 'onoff' for subscribing to changes.
Adafruit_MQTT_Subscribe ultrasonic = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/ultrasonic");
Adafruit_MQTT_Subscribe chorda = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/chord-a");
Adafruit_MQTT_Subscribe chordb = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/chord-b");

int PXL1[] = {0,1,2,3,4,5};
int PXL2[] = {0,1,2,3,4,5};
int PXL3[] = {0,1,2,3,4,5};
int PXL4[] = {0,1,2,3,4,5};
/*************************** Sketch Code ************************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void setup() {
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
 
  Serial.begin(115200);
  delay(10);
  pixels1.begin();
  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&ultrasonic);
  mqtt.subscribe(&chorda);
  mqtt.subscribe(&chordb);
  for(int j=0; j<=5;j++){
    pixels1.setPixelColor(PXL1[j],pixels1.Color(0,0,0));
    pixels1.show();
   
    pixels2.setPixelColor(PXL2[j],pixels2.Color(0,0,0));
    pixels2.show();
   
    pixels3.setPixelColor(PXL3[j],pixels3.Color(0,0,0));
    pixels3.show();
   
    pixels4.setPixelColor(PXL4[j],pixels4.Color(0,0,0));
    pixels4.show();
   
  }
}  


void loop() {

  MQTT_connect();

  Adafruit_MQTT_Subscribe *subscription;

  
  
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &ultrasonic) {
      Serial.print(F("Got: "));
      char* read=(char* )ultrasonic.lastread;
      float reading=atoi(read);
      Serial.println(reading);
      
    }
    
    if (subscription == &chorda){
      char* x=(char*)chorda.lastread;
      int n= atoi(x);
      if(n==1){
        i++;
      }  
      int y=i%2;
      if(n==1&&y==1){
        pixels1.setPixelColor(PXL1[2],pixels2.Color(0,0,255));
        pixels1.show();
        pixels2.setPixelColor(PXL2[2],pixels2.Color(0,255,0));
        pixels2.show();
        pixels3.setPixelColor(PXL3[1],pixels2.Color(0,255,0));
        pixels3.show();
        Serial.println("on");
      }else if(n==1&&y==0){
        Serial.println("off");
      }


    }
    if (subscription == &chordb){
      Serial.println("read");
      char* xx=(char*)chordb.lastread;
      int nn= atoi(xx);
      if(nn==1){
        k++;
      }  
      int yy=k%2;
      if(nn==1&&yy==1){
        pixels1.setPixelColor(PXL1[3],pixels2.Color(255,0,0));
        pixels1.show();
        pixels2.setPixelColor(PXL2[2],pixels2.Color(0,0,255));
        pixels2.show();
        pixels3.setPixelColor(PXL3[2],pixels2.Color(0,255,0));
        pixels3.show();
        pixels4.setPixelColor(PXL4[1],pixels2.Color(0,255,0));
        pixels4.show();
        Serial.println("on");
      }else if(nn==1&&yy==0){
        Serial.println("off");
      }
    }
  }

  delay(300);
 
}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}