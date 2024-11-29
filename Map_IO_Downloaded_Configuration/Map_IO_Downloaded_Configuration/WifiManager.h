/* Copyright (C) Luna - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the current license, which should be made available soon
 *
 * You should have received a copy of the Luna license with
 * this file. If not, please write to: jasonparkinson331@gmail.com
 */

#pragma once

#include <string>
#include <vector>

// Enum for Wi-Fi connection status
enum class WiFiStatus {
    DISCONNECTED,
    CONNECTED,
    CONNECTING,
    FAILED,
};

// Struct to hold network details
struct WiFiNetwork {
    std::string ssid;
    int signalStrength;  // Signal strength in dBm
    std::string encryptionType; // WPA, WEP, Open, etc.
};

// WiFi class declaration
class WiFiManager {
public:
    WiFiManager();
    ~WiFiManager();

    // Initialize the Wi-Fi interface
    bool init();

    // Scan for available Wi-Fi networks
    std::vector<WiFiNetwork> scanNetworks();

    // Connect to a specific network with an SSID and password
    WiFiStatus connect(const std::string& ssid, const std::string& password);

    // Disconnect from the currently connected network
    void disconnect();

    // Get current Wi-Fi status
    WiFiStatus getStatus() const;

    // Get current connected SSID
    std::string getSSID() const;

    // Get current signal strength (in dBm)
    int getSignalStrength() const;

private:
    WiFiStatus status;
    std::string currentSSID;
    int signalStrength;

    // Internal helper functions to handle platform-specific implementation
    bool platformInit();
    std::vector<WiFiNetwork> platformScanNetworks();
    bool platformConnect(const std::string& ssid, const std::string& password);
    void platformDisconnect();
    int platformGetSignalStrength();
};


