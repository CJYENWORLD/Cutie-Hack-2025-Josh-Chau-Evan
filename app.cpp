#include "app.h"
#include <iostream>
#include <string>

App::App() {
}

void App::run() {
    double points = 0.0;
    int goodStreak = 0;
    double multiplier = 1.0;

    std::string path = "drives/street_drive_good.csv";
    reader.readFile(path);

    int speedLimit = -1;
    loc.setLatitude(reader.getLat(0));
    loc.setLongitude(reader.getLon(0));
    if (loc.fetchSpeedLimit()) {
        speedLimit = loc.getSpeedLimit();
    } else {
        // fallback so the logic still makes sense if API fails
        speedLimit = 25; // or 40, your choice
    }

    for (int i = 0; i < reader.getMaxTime(); i++) {
        double mph = reader.getSpeed(i);
        double accelDelta = reader.getAccel(i);

        // 1) Accel rule: don't penalize accel when under the limit
        bool goodAccel = true;
        if (mph >= speedLimit) {
            // only enforce accel range once you're at/above the limit
            goodAccel = (accelDelta > -3.5 && accelDelta < 3.5);
        }

        // 2) Speed rule: same as before (too fast or way too slow is bad)
        bool goodSpeed = true;
        if (speedLimit > 0) {
            if (mph > (speedLimit + 5) || mph < (speedLimit / 2.0)) {
                goodSpeed = false;
            }
        }

        bool infraction = !(goodAccel && goodSpeed);

        if (infraction) {
            // bad tick: small penalty and full reset
            points -= 1.0;
            multiplier = 1.0;
            goodStreak = 0;
        } else {
            // good tick: add 1 * multiplier
            points += 1.0 * multiplier;
            goodStreak++;

            // every 10 good ticks, boost multiplier by +0.5
            if (goodStreak % 10 == 0) {
                multiplier += 0.5;
            }
        }

        std::cout << "t=" << i
                  << " points=" << points
                  << " mult=" << multiplier
                  << " streak=" << goodStreak
                  << " limit=" << speedLimit
                  << " mph=" << mph
                  << " accel=" << accelDelta
                  << std::endl;
        std::cout << "-----" << std::endl;
    }

    std::cout << "Final points: " << points << std::endl;
}
