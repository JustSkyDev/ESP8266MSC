// =================================================================================
// Copyright (c) 2024 JustSkyDev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =================================================================================

// Import the ESP8266MSC.
#include <ESP8266MSC.h>

// Import the WiFi.
#include <ESP8266WiFi.h>

// Create instance of ESP8266MSC class.
ESP8266MSC Conn;

void setup() {
  // Serial.
  // Serial.begin(115200);

  // Set the WiFi to STA (Station).
  WiFi.mode(WIFI_STA);

  // Init the communication.
  if (Conn.init() != 0) {
    // This is called when the initialization failed.
    // Serial.println("\n Failed initializing."");
  }
}

void loop() {
  // User code loop begin.

  // User code loop end.
}
