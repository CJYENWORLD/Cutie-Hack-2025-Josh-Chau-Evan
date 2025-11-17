#include "Location.h"
#include <iostream>
#include <cctype>
#include <sstream>
#include <iomanip>
#include "httplib.h"
#include "json.hpp"
using json = nlohmann::json;

Location::Location(double lat, double lon): latitude(lat), longitude(lon) {}

Location::Location(): latitude(0.0), longitude(0.0) {}

bool Location::fetchSpeedLimit() {
    httplib::SSLClient cli("overpass-api.de");
    std::string path = "/api/interpreter?data=%5Bout%3Ajson%5D%3Bway%28around%3A30%2C" + std::to_string(latitude) + "%2C" + std::to_string(longitude) + "%29%5Bmaxspeed%5D%3Bout%201%3B";
    auto res = cli.Get(path.c_str());
    if (!res){
        return false;
    }
    if (res->status != 200){
        return false;
    }

    json j = json::parse(res->body);
    if (!j.contains("elements") || j["elements"].empty()) {
        return false;
    }

    auto &elem = j["elements"][0];
    if (!elem.contains("tags") || !elem["tags"].contains("maxspeed")) {
        return false;
    }

    std::string maxspeed = elem["tags"]["maxspeed"];
    int value = 0;
    std::string num;
        for (char c : maxspeed) {
            if (isdigit(c)) {
                num.push_back(c);
            }
            else if (!num.empty()) {
                break;
            }
        }
        if (num.empty()) {
            return false;
        } 
    value = std::stoi(num);

    std::string lower = maxspeed;
    for (auto &c : lower) c = tolower(c);

    if (lower.find("mph") != std::string::npos)
        speedLimitMPH = value;
    else
        speedLimitMPH = static_cast<int>(value * 0.621371 + 0.5);

    return true;
}

double Location::getLatitude() const { 
    return latitude; 
}

double Location::getLongitude() const { 
    return longitude; 
}

int Location::getSpeedLimit() const { 
    return speedLimitMPH; 
}

void Location::setLatitude(double lat) {
    latitude = lat;
}

void Location::setLongitude(double lon) {
    longitude = lon;
}
