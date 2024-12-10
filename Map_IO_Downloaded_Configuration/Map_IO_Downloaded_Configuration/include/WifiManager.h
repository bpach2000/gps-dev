/******************************************************************************
 * Copyright (c) 2024 [Jason Parkinson-Brooke Pacheco]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * SPDX-License-Identifier: MIT
 *****************************************************************************/
//
//#pragma once
//
//#include <string>
//#include <vector>
//
//// Enum for Wi-Fi connection status
//enum class WiFiStatus {
//    DISCONNECTED,
//    CONNECTED,
//    CONNECTING,
//    FAILED,
//};
//
//// Struct to hold network details
//struct WiFiNetwork {
//    std::string ssid;
//    int signalStrength;  // Signal strength in dBm
//    std::string encryptionType; // WPA, WEP, Open, etc.
//};
//
//// WiFi class declaration
//class WiFiManager {
//public:
//    WiFiManager();
//    ~WiFiManager();
//
//    // Initialize the Wi-Fi interface
//    bool init();
//
//    // Scan for available Wi-Fi networks
//    std::vector<WiFiNetwork> scanNetworks();
//
//    // Connect to a specific network with an SSID and password
//    WiFiStatus connect(const std::string& ssid, const std::string& password);
//
//    // Disconnect from the currently connected network
//    void disconnect();
//
//    // Get current Wi-Fi status
//    WiFiStatus getStatus() const;
//
//    // Get current connected SSID
//    std::string getSSID() const;
//
//    // Get current signal strength (in dBm)
//    int getSignalStrength() const;
//
//private:
//    WiFiStatus status;
//    std::string currentSSID;
//    int signalStrength;
//
//    // Internal helper functions to handle platform-specific implementation
//    bool platformInit();
//    std::vector<WiFiNetwork> platformScanNetworks();
//    bool platformConnect(const std::string& ssid, const std::string& password);
//    void platformDisconnect();
//    int platformGetSignalStrength();
//};
//
//
