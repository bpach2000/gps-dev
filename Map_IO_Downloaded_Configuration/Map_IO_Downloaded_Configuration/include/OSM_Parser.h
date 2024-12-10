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