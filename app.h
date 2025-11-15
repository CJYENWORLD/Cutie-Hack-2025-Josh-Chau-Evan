#pragma once
#include "location.h"
#include "fileReader.h"
#include <iostream>
#include <string>

class App{
private:
    fileReader reader;
    Location loc;
    
public:
    App();
    void run();
};