#include "app.h"
#include "Level.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include "json.hpp"
using json = nlohmann::json;

App::App() {}

void App::run() {
    double curPoints = 0.0;
    int goodStreak = 0;
    double multiplier = 1.0;

    std::string path = "drives/street_drive_good3.csv";
    reader.readFile(path);

    int speedLimit = -1;
    loc.setLatitude(reader.getLat(0));
    loc.setLongitude(reader.getLon(0));
    if (loc.fetchSpeedLimit()) {
        speedLimit = loc.getSpeedLimit();
    } else {
        speedLimit = 25;
    }

    std::vector<std::string> currentDriveSummary;

    for (int i = 0; i < reader.getMaxTime(); i++) {
        double mph = reader.getSpeed(i);
        double accelDelta = reader.getAccel(i);

        bool goodAccel = true;
        if (mph >= speedLimit) {
            goodAccel = (accelDelta > -3.5 && accelDelta < 3.5);
        }

        bool goodSpeed = true;
        if (speedLimit > 0) {
            if (mph > (speedLimit + 5) || mph < (speedLimit / 2.0)) {
                goodSpeed = false;
            }
        }

        bool infraction = !(goodAccel && goodSpeed);

        if (infraction) {
            curPoints -= 1.0;
            multiplier = 1.0;
            goodStreak = 0;
        } else {
            curPoints += 1.0 * multiplier;
            goodStreak++;
            if (goodStreak % 10 == 0) {
                multiplier += 0.5;
            }
        }

        std::string status;
        if (!infraction) {
            status = "Eco Driving";
        } else {
            std::vector<std::string> reasons;

            if (!goodSpeed) {
                if (mph > speedLimit + 5) {
                    reasons.push_back("Speeding (over limit + 5 mph)");
                } else if (mph < speedLimit / 2.0) {
                    reasons.push_back("Driving too slow (below half limit)");
                }
            }
            if (!goodAccel) {
                reasons.push_back("Harsh acceleration/braking");
            }

            if (reasons.size() == 0) {
                status = "Driving rule violation";
            } else if (reasons.size() == 1) {
                status = reasons[0];
            } else {
                status = reasons[0] + " and " + reasons[1];
            }
        }

        std::ostringstream oss;
        oss << "t=" << i << "s"
            << ", points=" << curPoints
            << ", multiplier=" << multiplier
            << ", " << status;

        currentDriveSummary.push_back(oss.str());
        std::cout << currentDriveSummary.back() << "\n-----\n";
    }

    std::cout << "Final points: " << curPoints << std::endl;

    json cd;
    cd["drive_1"] = currentDriveSummary;

    std::ofstream driveFile("current_drive.json");
    if (driveFile.is_open()) {
        driveFile << cd.dump(4);
        driveFile.close();
    }

    double totalPoints = 0.0;
    std::vector<std::string> drives;

    std::ifstream inFile("points.json");
    if (inFile.is_open() && inFile.peek() != std::ifstream::traits_type::eof()) {
        try {
            json j;
            inFile >> j;
            totalPoints = j.value("totalPoints", 0.0);
            drives = j.value("drives", std::vector<std::string>());
        } catch (...) {
            totalPoints = 0.0;
            drives.clear();
        }
    }
    inFile.close();

    int driveIndex = static_cast<int>(drives.size()) + 1;

    double safePoints = curPoints;
    if (safePoints < 0) {
        safePoints = 0;
    } else {
        safePoints = std::ceil(safePoints);
    }

    std::ostringstream entry;
    entry << "Drive " << driveIndex << ": " << safePoints;
    drives.push_back(entry.str());

    double newTotalPoints = totalPoints + safePoints;

    json j;
    j["totalPoints"] = newTotalPoints;
    j["drives"] = drives;

    std::ofstream outFile("points.json");
    if (outFile.is_open()) {
        outFile << j.dump(4);
        outFile.close();
    }

    Level levelObj;
    int level = levelObj.getLevelFromPoints(static_cast<int>(newTotalPoints));
    int nextLevelTotal = levelObj.getTotalPointsNeededForNextLevel(static_cast<int>(newTotalPoints));

    json levelJson;
    levelJson["level"] = level;
    levelJson["totalPoints"] = newTotalPoints;
    levelJson["nextLevelTotalPoints"] = nextLevelTotal;

    std::ofstream levelFile("level.json");
    if (levelFile.is_open()) {
        levelFile << levelJson.dump(4);
        levelFile.close();
    }
}
