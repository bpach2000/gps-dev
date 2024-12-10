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
//#include "WifiManager.h"
//#include <iostream>
//#include <stdexcept>
//#include <sstream>
//#include <fstream>
//#include <cstring>
//#include <cstdio>
//
//// Constructor initializes the status to disconnected
//WiFiManager::WiFiManager() : status(WiFiStatus::DISCONNECTED), signalStrength(0) {}
//
//// Destructor (if needed, clean-up resources)
//WiFiManager::~WiFiManager() {}
//
//// Initializes Wi-Fi interface (platform-specific)
//bool WiFiManager::init() {
//    return platformInit();
//}
//
//// Scans for available networks (platform-specific)
//std::vector<WiFiNetwork> WiFiManager::scanNetworks() {
//    return platformScanNetworks();
//}
//
//// Connects to a Wi-Fi network (platform-specific)
//WiFiStatus WiFiManager::connect(const std::string& ssid, const std::string& password) {
//    // Set status to connecting
//    status = WiFiStatus::CONNECTING;
//
//    // Attempt connection
//    if (platformConnect(ssid, password)) {
//        status = WiFiStatus::CONNECTED;
//        currentSSID = ssid;
//        signalStrength = platformGetSignalStrength(); // Set the signal strength after connection
//    }
//    else {
//        status = WiFiStatus::FAILED;
//    }
//
//    return status;
//}
//
//// Disconnects from the current Wi-Fi network
//void WiFiManager::disconnect() {
//    platformDisconnect();
//    status = WiFiStatus::DISCONNECTED;
//    currentSSID.clear();
//    signalStrength = 0;
//}
//
//// Gets the current connection status
//WiFiStatus WiFiManager::getStatus() const {
//    return status;
//}
//
//// Gets the current connected SSID
//std::string WiFiManager::getSSID() const {
//    return currentSSID;
//}
//
//// Gets the current signal strength (in dBm)
//int WiFiManager::getSignalStrength() const {
//    return signalStrength;
//}
//
//// Platform-specific helper functions (to be implemented depending on platform)
//
//// Initializes platform-specific Wi-Fi interface using nmcli
//bool WiFiManager::platformInit() {
//    // Check if `nmcli` is available
//    if (system("which nmcli > /dev/null 2>&1") != 0) {
//        std::cerr << "Error: nmcli not found. Ensure NetworkManager is installed." << std::endl;
//        return false;
//    }
//    return true;
//}
//
//// Scans for available networks using nmcli
//std::vector<WiFiNetwork> WiFiManager::platformScanNetworks() {
//    std::vector<WiFiNetwork> networks;
//    std::string cmd = "nmcli -t -f SSID,SIGNAL,SECURITY dev wifi";
//
//    // Open a pipe to nmcli
//    FILE* pipe = popen(cmd.c_str(), "r");
//    if (!pipe) {
//        std::cerr << "Error: Failed to run nmcli." << std::endl;
//        return networks;
//    }
//
//    // Read line by line from the nmcli output
//    char buffer[256];
//    while (fgets(buffer, sizeof(buffer), pipe)) {
//        WiFiNetwork network;
//        std::string line(buffer);
//        std::istringstream ss(line);
//        std::getline(ss, network.ssid, ':');
//        ss >> network.signalStrength;
//
//        // Extract encryption type (e.g., WPA2, Open, etc.)
//        std::string security;
//        std::getline(ss, security);
//        network.encryptionType = security.empty() ? "Open" : security;
//
//        networks.push_back(network);
//    }
//
//    fclose(pipe);
//    return networks;
//}
//
//// Connect to a specific Wi-Fi network using nmcli
//bool WiFiManager::platformConnect(const std::string& ssid, const std::string& password) {
//    std::string cmd = "nmcli dev wifi connect '" + ssid + "' password '" + password + "'";
//
//    // Run the nmcli command to connect
//    int result = system(cmd.c_str());
//    if (result != 0) {
//        std::cerr << "Failed to connect to network: " << ssid << std::endl;
//        return false;
//    }
//
//    return true;
//}
//
//// Disconnect from the current Wi-Fi network using nmcli
//void WiFiManager::platformDisconnect() {
//    std::string cmd = "nmcli dev disconnect iface wlan0"; // Adjust interface name if needed
//    system(cmd.c_str());
//}
//
//// Get the signal strength of the connected Wi-Fi network using nmcli
//int WiFiManager::platformGetSignalStrength() {
//    // To get the signal strength, use `nmcli` to get the device's current status
//    std::string cmd = "nmcli -t -f IN-USE,SIGNAL dev wifi";
//
//    FILE* pipe = popen(cmd.c_str(), "r");
//    if (!pipe) {
//        std::cerr << "Error: Failed to run nmcli." << std::endl;
//        return -1;
//    }
//
//    char buffer[256];
//    while (fgets(buffer, sizeof(buffer), pipe)) {
//        std::string line(buffer);
//        if (line.find('*') != std::string::npos) {
//            // Find the signal strength (in dBm)
//            size_t pos = line.find_last_of(":");
//            if (pos != std::string::npos) {
//                return std::stoi(line.substr(pos + 1));
//            }
//        }
//    }
//
//    fclose(pipe);
//    return -1;  // Return an error value if signal strength cannot be retrieved
//}