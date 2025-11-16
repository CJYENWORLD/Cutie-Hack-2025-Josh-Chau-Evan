#pragma once

#include <vector>
#include <fstream>

class ReadPoints {
public:
    ReadPoints();

    double getTotPoints() const;
    void updateTotPoints(double points);
    void addDrive(double points);       
    std::vector<double> listDrives() const;

private:
    std::ofstream ofS;   
    double totalPoints = 0.0;
    std::vector<double> drives;

    void readFromFile();

};
