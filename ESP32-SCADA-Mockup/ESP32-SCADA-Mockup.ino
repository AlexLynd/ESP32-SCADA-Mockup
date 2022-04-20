/* WiFi Nugget SSDP Phishing, 2022
 * https://github.com/HakCat-Tech/Nugget-SSDP
 *  
 * by Alex Lynd & HakCat Hardware
 * https://hakcat.com
 */

// include libraries
#include "ESPAsyncWebServer.h"
#include "webserver.h"

int motorPin = 3;    // Motor analog pin on the ESP32S2

// WiFi credentials
const char* ssid = "WiFi";
const char* password = "password";

// start webserver
AsyncWebServer webserver(80);
extern String index_html;

void setup() {
    Serial.begin(115200);

    // start WiFi!
    Serial.println();
    Serial.println("Starting WiFi...");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    if(WiFi.waitForConnectResult() == WL_CONNECTED) {

        Serial.printf("Starting HTTP...\n");
        
        webserver.on("/index.html", HTTP_GET, [&](AsyncWebServerRequest *request) {
            request->send(200, "text/html", index_html);
        });

        webserver.on("/submit.php", HTTP_POST, [&](AsyncWebServerRequest *request) {
          String speed = request->getParam("speed", true)->value() ;
          
          analogWrite(motorPin, speed.toInt());
          request->send(200, "text/plain", "");
        });
                
        webserver.on("/", HTTP_GET, [&](AsyncWebServerRequest *request) {
            request->redirect("/index.html");
        });
        webserver.begin();

        Serial.printf("Ready!\n");
        Serial.println(WiFi.localIP());
    } else {
        Serial.printf("WiFi Failed\n");
        while(1) {
            delay(100);
        }
    }
}

void loop() {
    delay(1);
}
