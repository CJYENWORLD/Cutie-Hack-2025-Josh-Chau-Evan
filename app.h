#include "location.h"
#include "fileReader.h"
#include "pointsCalc.h"
#include <iostream>
#include <string>

class App{
private:
    fileReader reader;
    Location loc;
    PointsCalc calc;
    
public:
    App();
    void run();
};