#include "Level.h"
#include <cmath>

int Level::getLevelFromPoints(int totalPoints) {
    if (totalPoints < 0) 
        totalPoints = 0;

    double base = 200.0;
    double growth = 1.25;

    int level = 1;
    double required = base;

    // subtract levels until we can’t reach next one
    while (totalPoints >= required) {
        totalPoints -= static_cast<int>(required);
        level++;
        required *= growth;
    }

    return level;
}

int Level::getTotalPointsNeededForNextLevel(int totalPoints) {
    double base = 200.0;
    double growth = 1.25;

    int level = 1;
    int accumulated = 0;
    double required = base;

    // find current level
    while (totalPoints >= required) {
        totalPoints -= static_cast<int>(required);
        accumulated += static_cast<int>(required);
        level++;
        required *= growth;
    }

    // accumulate total for next level
    accumulated += static_cast<int>(required);

    return accumulated;
}

int Level::getPointsRemainingToNextLevel(int totalPoints) {
    double base = 200.0;
    double growth = 1.25;

    int level = 1;
    int accumulated = 0;
    double required = base;

    // find current level and accumulated points
    while (totalPoints >= required) {
        totalPoints -= static_cast<int>(required);
        accumulated += static_cast<int>(required);
        level++;
        required *= growth;
    }

    // total points needed for next level
    int nextLevelTotal = accumulated + static_cast<int>(required);

    // how many more points needed
    return nextLevelTotal - totalPoints - accumulated;
}
