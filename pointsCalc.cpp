#include "PointsCalc.h"

PointsCalc::PointsCalc() : initialSpeedLimit(0), multiplier(1.0), points(0), speedLimit(initialSpeedLimit), accelDelta(0.0), streak(0) {}

int PointsCalc::totalPoints(int currSecond, double mph, double accelData) {
    accelDelta = accelData;

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

    return points;
}

int PointsCalc::getPoints() const { 
    return points; 
}

int PointsCalc::getStreak() const { 
    return streak; 
}

double PointsCalc::getMultiplier() const { 
    return multiplier; 
}