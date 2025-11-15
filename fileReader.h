#pragma once
#include <string>
#include <vector>
using namespace std;

class fileReader{
    public:
        
        int readFile(string&);
        double getSpeed(double) const;
        double getAccel(double) const;
        double getLat(double) const; 
        double getLon(double) const;
        double getMaxTime() const;
        void print();
    private:
        vector<vector<double>> _data;
};