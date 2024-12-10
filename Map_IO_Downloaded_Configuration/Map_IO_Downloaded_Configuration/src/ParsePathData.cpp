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

#include <iostream>
#include <tinyxml2.h>

#include "../include/ParsePathData.h"

ParsePathData::ParsePathData() {

}

void ParsePathData::ParseGpxFile(const char* filename) {
    // Create XML Document
    XMLDocument doc;

    // Load the GPX file
    XMLError eResult = doc.LoadFile(filename);
    if (eResult != XML_SUCCESS) {
        std::cerr << "Error loading file: " << filename << std::endl;
        return;
    }

    // Get the root element
    XMLElement* root = doc.RootElement();
    if (!root) {
        std::cerr << "Error: no root element in GPX file" << std::endl;
        return;
    }

    // Check that the root element is a 'gpx' element
    const char* rootName = root->Value();
    if (rootName == nullptr || std::string(rootName) != "gpx") {
        std::cerr << "Error: root element is not 'gpx'" << std::endl;
        return;
    }

    // Output GPX version and creator
    const char* version = root->Attribute("version");
    const char* creator = root->Attribute("creator");
    std::cout << "GPX Version: " << (version ? version : "Unknown") << std::endl;
    std::cout << "Creator: " << (creator ? creator : "Unknown") << std::endl;

    // Iterate over the 'wpt' (waypoints) elements
    XMLElement* waypoint = root->FirstChildElement("wpt");
    while (waypoint) {
        const char* lat = waypoint->Attribute("lat");
        const char* lon = waypoint->Attribute("lon");
        const char* name = waypoint->FirstChildElement("name") ? waypoint->FirstChildElement("name")->GetText() : "Unnamed";

        std::cout << "Waypoint: " << name << " at (" << lat << ", " << lon << ")" << std::endl;

        waypoint = waypoint->NextSiblingElement("wpt");
    }

    // Iterate over the 'trk' (track) elements
    XMLElement* track = root->FirstChildElement("trk");
    while (track) {
        std::cout << "Track: " << std::endl;

        // Iterate over the track segments ('trkseg')
        XMLElement* segment = track->FirstChildElement("trkseg");
        while (segment) {
            // Iterate over the track points ('trkpt')
            XMLElement* trackPoint = segment->FirstChildElement("trkpt");
            while (trackPoint) {
                const char* lat = trackPoint->Attribute("lat");
                const char* lon = trackPoint->Attribute("lon");
                const char* elevation = trackPoint->FirstChildElement("ele") ? trackPoint->FirstChildElement("ele")->GetText() : "Unknown";
                const char* time = trackPoint->FirstChildElement("time") ? trackPoint->FirstChildElement("time")->GetText() : "Unknown";

                std::cout << "Track Point: (" << lat << ", " << lon << "), Elevation: " << elevation << ", Time: " << time << std::endl;

                trackPoint = trackPoint->NextSiblingElement("trkpt");
            }
            segment = segment->NextSiblingElement("trkseg");
        }

        track = track->NextSiblingElement("trk");
    }
}
