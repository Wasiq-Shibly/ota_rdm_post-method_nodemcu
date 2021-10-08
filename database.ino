void database()
{

 //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
      WiFiClient client;
      HTTPClient http;

      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);

      // Specify content-type header
      // http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      // Data to send with HTTP POST
      //String httpRequestData = "card_number=12000020";
      // Send HTTP POST request
      //  int httpResponseCode = http.POST(httpRequestData);

      // If you need an HTTP request with a content type: application/json, use the following:
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      //   http.addHeader("Content-Type", "application/json");
      http.addHeader("authorization", "api_pi_123");
      int httpResponseCode = http.POST("card_number=12000020");

      // If you need an HTTP request with a content type: text/plain
      //http.addHeader("Content-Type", "text/plain");
      //int httpResponseCode = http.POST("Hello, World!");


      payload = http.getString();
      DynamicJsonDocument DeSerial(100);
      //deserialization
      DeserializationError err = deserializeJson(DeSerial, payload);
      String tmp = DeSerial["status"];
      Serial.println(tmp);
      if (tmp) {
        Serial.println("OK");
      } else {
        Serial.println(tmp);
        Serial.println("Not OK");
      }
      Serial.print(tmp);

      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);


      Serial.print("Body Side: ");
      Serial.println(payload);


      if (httpResponseCode == 200)
      {
        String status = "";

        int last = payload.length();


        Serial.println(last);


      }


      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }




    lastTime = millis();
  }



  
}
