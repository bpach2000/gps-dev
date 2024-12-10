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


#include "../include/OSM_Parser.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <tinyxml2.h>

using namespace tinyxml2;

OSM_Parser::OSM_Parser(const std::string& filePath) : filePath(filePath) {}

OSM_Parser::~OSM_Parser() {}

bool OSM_Parser::parseFile() {
    XMLDocument doc;

    // Load the file
    if (doc.LoadFile(filePath.c_str()) != XML_SUCCESS) {
        std::cerr << "Failed to load .osm file: " << filePath << std::endl;
        return false;
    }

    // Get the root element
    XMLElement* root = doc.RootElement();
    if (!root || std::string(root->Name()) != "osm") {
        std::cerr << "Invalid .osm file format!" << std::endl;
        return false;
    }

    // Parse nodes
    for (XMLElement* nodeElem = root->FirstChildElement("node"); nodeElem != nullptr; nodeElem = nodeElem->NextSiblingElement("node")) {
        std::string id = nodeElem->Attribute("id");
        double lat = nodeElem->DoubleAttribute("lat");
        double lon = nodeElem->DoubleAttribute("lon");

        nodes[id] = { lat, lon };
    }

    // Parse ways
    for (XMLElement* wayElem = root->FirstChildElement("way"); wayElem != nullptr; wayElem = wayElem->NextSiblingElement("way")) {
        Way way;
        for (XMLElement* ndElem = wayElem->FirstChildElement("nd"); ndElem != nullptr; ndElem = ndElem->NextSiblingElement("nd")) {
            std::string ref = ndElem->Attribute("ref");
            way.nodeRefs.push_back(ref);
        }
        ways.push_back(way);
    }

    return true;
}

const std::unordered_map<std::string, Node>& OSM_Parser::getNodes() const {
    return nodes;
}

const std::vector<Way>& OSM_Parser::getWays() const {
    return ways;
}