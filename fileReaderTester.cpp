//unused tester file for fileReader class


#include <iostream>
using namespace std;

#include "fileReader.h"

int main()
{
    fileReader reading;
    cout << "input filename" << endl;
    string name;
    // string name = "drives/drive_1.csv"; 
    cin >> name;
    cout << "filename: " << name << endl;
    
    int good;
    good = reading.readFile(name);  

    reading.print();

    double maxTime = reading.getMaxTime();
    cout << "maxTime: " << maxTime << endl;
    
    cout << "speed at maxTime: " << reading.getSpeed(maxTime) << endl;
    cout << "accel at maxTime: " << reading.getAccel(maxTime) << endl;
    cout << "lat and lon at maxTime: " << reading.getLat(maxTime) << ", " << reading.getLon(maxTime) << endl;

    cout << "speed at 3: " << reading.getSpeed(3) << endl;
    cout << "accel at 3: " << reading.getAccel(3) << endl;
    cout << "lat and lon at 3: " << reading.getLat(3) << ", " << reading.getLon(3) << endl;


}