#include "Level.h"
#include <cmath>

int Level::getLevelFromPoints(int totalPoints) {
    if (totalPoints < 0) 
        totalPoints = 0;

    double base = 200.0;
    double growth = 1.25;

    int level = 1;
    double required = base;

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

    while (totalPoints >= required) {
        totalPoints -= static_cast<int>(required);
        accumulated += static_cast<int>(required);
        level++;
        required *= growth;
    }

    accumulated += static_cast<int>(required);

    return accumulated;
}

int Level::getPointsRemainingToNextLevel(int totalPoints) {
    double base = 200.0;
    double growth = 1.25;

    int level = 1;
    int accumulated = 0;
    double required = base;

    while (totalPoints >= required) {
        totalPoints -= static_cast<int>(required);
        accumulated += static_cast<int>(required);
        level++;
        required *= growth;
    }

    int nextLevelTotal = accumulated + static_cast<int>(required);

    return nextLevelTotal - totalPoints - accumulated;
}
