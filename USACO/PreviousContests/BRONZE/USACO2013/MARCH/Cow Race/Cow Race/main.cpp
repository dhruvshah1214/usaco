/*
 ID: dhruv.s2
 PROG: cowrace
 LANG: C++11
 */

#include <algorithm>
#include <bitset>
#include <limits>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <stdio.h>





#define READY_FOR_SUBMIT 1

using namespace std;

void output(string outputString);
ifstream in;
ofstream out;

string GetlineX(ifstream& file, unsigned int x){
    file.seekg(ios::beg);
    int i = 0;
    string line;
    while (i < x) {
        getline(file, line);
        i++;
    }
    return line;
}

vector<string> getWords(string line, int noOfWords){
    stringstream ss(line);
    string word;
    
    vector<string> words;

    for (int i = 0; i < noOfWords; i++)
    {
        ss >> word;
        words.push_back(word);
    }
    return words;
}

int stringToInt(string string){
    return atoi(string.c_str());
}



int main(int argc, const char * argv[])
{

    
    if (READY_FOR_SUBMIT) {
        in.open ("cowrace.in");
        out.open ("cowrace.out");
        
    }
    else {
        in.open("/Users/hitesh/Documents/ProblemSolving/USACO/PreviousContests/BRONZE/USACO2013/MARCH/Cow Race/Cow Race/cowrace.in");
        
    }
    vector<int> bessie;
    vector<int> elsie;
    int numberOfSwitches = 0;
    
    string firstLine = GetlineX(in, 1);
    
    
    int N = stringToInt(getWords(firstLine, 2)[0]);
    int M = stringToInt(getWords(firstLine, 2)[1]);
    
    
    for (int i = 0; i < N; i++) {
        string currLine = GetlineX(in, i + 2);
        int speed = stringToInt(getWords(currLine, 2)[0]);
        int time = stringToInt(getWords(currLine, 2)[1]);
        
        for (int a = 0; a < time; a++) {
            if (bessie.empty()) {
                bessie.push_back(speed);
            }
            else {
                bessie.push_back(speed + bessie[bessie.size() - 1]);
            }
        }
    }
    if (!READY_FOR_SUBMIT) {
        for (vector<int>::size_type i = 0; i < bessie.size(); i++) {
            cout << bessie[i] << endl;
        }
    }
    
    cout << endl << endl << endl;
    for (int i = 0; i < M; i++) {
        string currLine = GetlineX(in, N + i + 2);
        int speed = stringToInt(getWords(currLine, 2)[0]);
        int time = stringToInt(getWords(currLine, 2)[1]);
        
        for (int a = 0; a < time; a++) {
            if (elsie.empty()) {
                elsie.push_back(speed);
            }
            else {
                elsie.push_back(speed + elsie[elsie.size() - 1]);
            }
        }
    }
    if (!READY_FOR_SUBMIT) {
        for (vector<int>::size_type i = 0; i < elsie.size(); i++) {
            cout << elsie[i] << endl;
        }
    }
    
    bool bessieInLead = ((bessie[0] > elsie[0]) ? true : false);
    
    cout << endl << "BES: " << bessie.size() << " ELSIE: " << elsie.size() << endl;
    for (int i = 0; i < ((bessie.size() + elsie.size()) / 2); i ++ ) {
        bool isSwitch = false;
        if (i == 0) {
            continue;
        }
        else {
            if ((bessie[i] > elsie[i]) && !bessieInLead) {
                isSwitch = true;
                bessieInLead = true;
            }
            else if((elsie[i] > bessie[i]) && bessieInLead){
                bessieInLead = false;
                isSwitch = true;
            }
        }
        if (isSwitch) {
            numberOfSwitches++;
        }
    }
    cout << numberOfSwitches << endl;

    output(to_string(numberOfSwitches));
    return 0;
    
}

void output(string outputString){
    ostringstream stream;
    stream << outputString;
    string output = stream.str();
    out << output;
}




