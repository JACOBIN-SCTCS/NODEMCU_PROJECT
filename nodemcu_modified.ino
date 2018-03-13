
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include<string.h>

const int rs = D7, en = D6, d4 = D3, d5 = D2, d6 = D1, d7 = D0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const char *ssid =  "YOUR WIFI SSID";     
const char *pass =  "YOUR WIFI PASSWORD";



const char *fire_host="FIREBASE HOST";
const char *fire_secret="SECRET KEY ";






String response;

WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       delay(10);

       lcd.begin(16, 2);
               
       Serial.println("Connecting to ");
       lcd.print("Connecting to Wifi ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
      lcd.print("Connected to Wifi");
      Serial.println(WiFi.localIP());

      Firebase.begin(fire_host,fire_secret);

     lcd.clear();
      
}
 
void loop() 
{      
  response=Firebase.getString("weather");
  Serial.println(response);
  lcd.print(response);

  delay(1000);
  lcd.clear();
 
  
}





