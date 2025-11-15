#pragma once
#include <string>
#include <vector>
using namespace std;

class fileReader{
    public:
        fileReader();
        int readFile(string&);
        double getMPH(int) const;
        double getAccel(int) const;
        double getLat(int) const; 
        double getLon(int) const;
        void print() const;
    private:
        vector<vector<double>> data;
};