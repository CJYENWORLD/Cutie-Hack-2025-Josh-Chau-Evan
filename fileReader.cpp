#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "fileReader.h"

int fileReader::readFile(string& fileName)
{
    ifstream inF;
    inF.open(fileName);

    if (!inF.is_open())
    {
        cout << "unable to open file" << endl;
        return 1;
    }
    // else{ cout << "open success" << endl; }

    stringstream inSS;
    string row;
    vector<double> tempRow;
    string tempData;

    while (getline(inF, row))
    {
        inSS.clear();
        inSS.str(row);

        // cout << "reading row: " << row << endl;
        while (getline(inSS, tempData, ',')) 
        { 
            tempRow.push_back(stod(tempData)); 
            // cout << "reading data: " << tempData << endl;
        }

        _data.push_back(tempRow);
        tempRow.clear();
    }

    if (!inF.eof())
    {
        cout << "unable to read to end of file" << endl;
        return 1;
    }

    inF.close();
    return 0;
}

double fileReader::getSpeed(double time) const
{
    return _data.at(time).at(1);
}

double fileReader::getAccel(double time) const
{
    return _data.at(time).at(2);
}

double fileReader::getLat(double time) const
{
    return _data.at(time).at(3);
}

double fileReader::getLon(double time) const
{
    return _data.at(time).at(4);
}

double fileReader::getMaxTime() const
{
    return static_cast<double>(_data.size() - 1);
}

void fileReader::print()
{
    int precision = 1;
    for (unsigned i = 0; i < this->_data.size(); i++)
    {
        for (unsigned j = 0; j < this->_data[i].size(); j++)
        {
            if (j == 1) { precision = 15; }
            else if (j == 3) { precision = 15; }
            
            cout << setprecision(precision); 
            cout << _data[i][j];
            if (j != this->_data[i].size() - 1)
            {
                cout << ',';
            }
        }
        cout << endl;
    }
}
