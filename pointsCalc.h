#pragma once

class PointsCalc {
private:
    double multiplier;
    int points;
    int speedLimit;
    double accelDelta;
    int streak;
    int initialSpeedLimit;

public:
    PointsCalc();

    int totalPoints(int currSecond, double mph, double accelData);

    int getPoints() const;
    int getStreak() const;
    double getMultiplier() const;
};
