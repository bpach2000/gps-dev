// Map_IO_Downloaded_Configuration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

#include "../include/OSM_Parser.h"

int main()
{
    // Path to the .osm file
    OSM_Parser parser("C:/gps-dev/Map_IO_Downloaded_Configuration/Map_IO_Downloaded_Configuration/ResourceFile/map.osm");

    // Parse the file
    if (!parser.parseFile()) {
        std::cerr << "Error parsing .osm file!" << std::endl;
        return 1;
    }

    // Access parsed data
    const auto& nodes = parser.getNodes();
    const auto& ways = parser.getWays();

    // Print node data
    std::cout << "Nodes:" << std::endl;
    for (const auto& [id, node] : nodes) {
        std::cout << "ID: " << id << ", Lat: " << node.lat << ", Lon: " << node.lon << std::endl;
    }

    // Print way data
    std::cout << "\nWays:" << std::endl;
    for (const auto& way : ways) {
        std::cout << "Way with nodes: ";
        for (const auto& ref : way.nodeRefs) {
            std::cout << ref << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
