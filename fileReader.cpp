#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "fileReader.h"

int fileReader::readFile(string& fileName)
{
    fstream inF;
    inF.open(fileName);

    if (!inF.is_open())
    {
        cout << "unable to open file" << endl;
        return 1;
    }

    stringstream inSS;
    string row;
    vector<double> tempRow;
    string tempData;
    while (getline(cin, row))
    {
        inSS.str(row);
        while (getline(cin, tempData, ','))
        {
            tempRow.push_back(stod(tempData));
        }
    }

    if (!inF.eof())
    {
        cout << "unable to read to end of file" << endl;
        return 1;
    }

    inF.close();
    return 0;
}

void fileReader::print() const
{
    for (vector<double> row : data)
    {
        for (double curNum : row)
        {
            cout << curNum << ', ';
        }
        cout << endl;
    }
}
