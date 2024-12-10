/* Copyright (C) Luna - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the current license, which should be made available soon
 *
 * You should have received a copy of the Luna license with
 * this file. If not, please write to: jasonparkinson331@gmail.com
 */

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Struct for a node (latitude/longitude point)
struct Node {
    double lat;  // Latitude
    double lon;  // Longitude
};

// Struct for a way (sequence of node references)
struct Way {
    std::vector<std::string> nodeRefs; // List of node IDs
};


class OSM_Parser {
private:
    std::string filePath; // Path to the .osm file
    std::unordered_map<std::string, Node> nodes; // Map of nodes (id -> Node)
    std::vector<Way> ways; // List of ways

public:
    OSM_Parser(const std::string& filePath); // Constructor with file path
    ~OSM_Parser(); // Destructor

    bool parseFile(); // Parse the .osm file

    const std::unordered_map<std::string, Node>& getNodes() const; // Get parsed nodes
    const std::vector<Way>& getWays() const; // Get parsed ways
};