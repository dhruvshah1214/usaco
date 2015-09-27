/*
 ID: dhruv.s2
 PROG: namenum
 LANG: C++11
 */

#include <iostream>
#include <fstream>

using namespace std;

int numDigits;
string numberCattle;
char keypad[8][3] = {
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
    {'J', 'K', 'L'},
    {'M', 'N', 'O'},
    {'P', 'R', 'S'},
    {'T', 'U', 'V'},
    {'W', 'X', 'Y'}
};
string realNames[5000];
int realNamesCount = 0;
bool noName = true;
ofstream out("namenum.out");

int binarySearch(string names[], int size, string value)
{
    int first = 0,             // First array element
    last = size - 1,       // Last array element
    middle,                // Mid point of search
    position = -1;         // Position of search value
    bool found = false;        // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (names[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }
    return position;
}


void recursive(string name, int number, int index) {
    if (index == numDigits) {
        if (binarySearch(realNames, realNamesCount, name) > -1) {
            noName = false;
            cout << name << endl;
            out << name << endl;
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        recursive(name + keypad[number - 2][i], numberCattle[index + 1] - '0', index + 1);
    }
}


int main(int argc, const char * argv[])
{
    
    
    ifstream in("namenum.in");
    ifstream realNamesIN("dict.txt");

    getline(in, numberCattle);
    
    cout << numberCattle << endl;
    numDigits = (int)numberCattle.size();
    cout << numDigits << endl;
    
    string line;
    for (int i = 0; getline(realNamesIN, line); i++) {
        realNames[i] = line;
        realNamesCount++;
    }

    recursive("", numberCattle[0] - '0', 0);
    

    
    if (noName == true) {
        cout << "NONE" << endl;
        out << "NONE" << endl;
    }

    /*
    cout << endl;
    ostringstream stream;
    if (namesMatch.size() > 0) {
        for (size_t i = 0; i < namesMatch.size(); i++) {
            stream << namesMatch[i] << endl;
        }
    }
    else {
        stream << "NONE" << endl;
    }
    string output = stream.str();
    out << output;
    cout << endl << endl << endl << output << endl << endl;
    */
     
    return 0;
    
}





