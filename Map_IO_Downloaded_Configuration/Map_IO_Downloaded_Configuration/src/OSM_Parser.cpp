/* Copyright (C) Luna - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the current license, which should be made available soon
 *
 * You should have received a copy of the Luna license with
 * this file. If not, please write to: jasonparkinson331@gmail.com
 */


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