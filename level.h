#pragma once

class Level {
public:
    static int getLevelFromPoints(int totalPoints);
    static int getTotalPointsNeededForNextLevel(int totalPoints);
    static int getPointsRemainingToNextLevel(int totalPoints);
};
