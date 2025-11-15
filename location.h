#pragma once
#include <string>

class Location {
private:
    double latitude;
    double longitude;
    int speedLimitMPH = -1;

public:
    Location(double lat, double lon);
    Location();
    bool fetchSpeedLimit();
    double getLatitude() const;
    double getLongitude() const;
    int getSpeedLimit() const;
    void setLatitude(double lat);
    void setLongitude(double lon);
};
