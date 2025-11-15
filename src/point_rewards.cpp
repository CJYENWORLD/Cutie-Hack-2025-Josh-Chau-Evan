#include <iostream>
#include <vector>
using namespace std;

double multiplier = 1;
int points = 0;
int speedlimit = 40;
double accel_delta = 2;
int streak;


int totalPoints (int curr_second, double mph, double accel_data) {

int infraction_occured = 0;

    if (accel_delta > -2 && accel_delta < 2) {

        points += points ;
        streak += streak ;
    }
        else {
            points --;
            multiplier = 0;
        }

    if (mph > (speedlimit+5) || mph < (speedlimit/2)) {
        points --;
        multiplier=0;
    }
        else {
            points += points*multiplier;
        }

    return points;

}

