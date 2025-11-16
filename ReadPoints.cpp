#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

#include "ReadPoints.h"

ReadPoints::ReadPoints() 
{
    readFromFile();
}

    // Member functions
double ReadPoints::getTotPoints() const {
    return totalPoints;
}

void ReadPoints::updateTotPoints(double points) {
    totalPoints = points;
}

void ReadPoints::addDrive(double points) {
    drives.push_back(points);
    totalPoints += points;
}

std::vector<double> ReadPoints::listDrives() const {
    return drives;
}

    void ReadPoints::readFromFile() {
        if (!std::filesystem::exists("points.txt")) {
            // File doesn't exist: create it with totalPoints = 0
            std::ofstream outFile("points.txt");
            if (!outFile.is_open()) throw std::runtime_error("Failed to create points.txt");
            outFile << totalPoints << '\n';
            return;
        }

        std::ifstream inFile("points.txt");
        if (!inFile.is_open()) return; // fallback

        std::string line;
        int lineNumber = 0;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            double value;
            if (!(iss >> value)) continue; // skip invalid lines

            if (lineNumber == 0) {
                totalPoints = value;  // first line = total points
            } else {
                drives.push_back(value); // rest = drives
            }
            ++lineNumber;
        }
    }
