#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Anojan.T";
const char* password = "anojan876";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected");
}

void loop() {
  // Your RFID code and logic here...

  // Assuming you have the RFID data in the 'rfidData' variable
  long int rfidData = 1234567890;

  sendRfidLog(rfidData);

  delay(5000);
}

void sendRfidLog(long int rfidData) {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // Replace "http://localhost/phpmyadmin/index.php?route=/database/structure&db=test005" 
    // with your server URL
    const char* serverURL = "http://localhost/phpmyadmin/index.php?route=/database/structure&db=test005";

    http.begin(client, serverURL);

    // You can add headers if needed, such as authorization tokens or custom headers
    // http.addHeader("Authorization", "Bearer your_token");

    // Assuming you want to send the RFID data as a parameter named 'rfid'
    String postData = "rfid=" + String(rfidData);

    int httpResponseCode = http.POST(postData);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error in sending request. HTTP Response code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi not connected");
  }
}
