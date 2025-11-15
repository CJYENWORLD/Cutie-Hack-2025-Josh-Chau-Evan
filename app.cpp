#include "app.h"

App::App() {
}

void App::run() {
    int points = 0;
    std::string path = "drives/drive_1.csv";
    int streak = 0;
    double multiplier = 0;
    reader.readFile(path);
    for(int i = 0; i < reader.getMaxTime(); i++) {
        int mph = reader.getSpeed(i);
        loc.setLatitude(reader.getLat(i));
        loc.setLongitude(reader.getLon(i));
        int speedLimit = -1;
        if (loc.fetchSpeedLimit()){
            speedLimit = loc.getSpeedLimit();
        }
        double accelDelta = reader.getAccel(i);
        if (accelDelta > -2 && accelDelta < 2) {
        streak++;
        points += static_cast<int>(points * multiplier);
        multiplier += 0.1;
        } 
        else {
            points--;
            multiplier = 1.0;
            streak = 0;
        }

        if (mph > (speedLimit + 5) || mph < (speedLimit / 2.0)) {
            points--;
            multiplier = 1.0;
            streak = 0;
        } 
        else {
            points += static_cast<int>(points * multiplier);
        }
    }
}
