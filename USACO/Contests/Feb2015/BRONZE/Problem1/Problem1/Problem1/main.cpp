
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



int main(int argc, const char * argv[])
{
    cout << "HELLO";
    
    ifstream in;
    ofstream outs;
    
    if (READY_FOR_SUBMIT) {
        in.open ("censor.in");
        outs.open ("censor.out");
    }
    else {
        in.open("/Users/hitesh/Documents/ProblemSolving/USACO/Contests/Feb2015/BRONZE/Problem1/Problem1/Problem1/p1.in");
        outs.open("/Users/hitesh/Documents/ProblemSolving/USACO/Contests/Feb2015/BRONZE/Problem1/Problem1/Problem1/p1.out");
        
    }
    
    string line;
    string S;
    string T;
    int multiplier;
    if (strlen(T.c_str()) < 10) {
        multiplier = 5;
    }
    else {
        multiplier = 2;
    }
    for (int i = 0; getline(in, line); i++) {
        if (i == 0) {
            S = line;
        }
        else {
            T = line;
        }
    }
    // char* chars = (char*)T.c_str();
    
    size_t lastChangedIndex = S.find(T);
    size_t searchFrom = 0;
    
    while (true) {
        std::string::size_type i = S.find(T, searchFrom);
        if (i == S.npos) {
            break;
        }
        else {
            if (i - lastChangedIndex > 2 * strlen(T.c_str())) {
                searchFrom = i - (2 * strlen(T.c_str()));
            }
            S.erase(i, T.length());

        }
        lastChangedIndex = i;
        
    }
    
    if (S.find(T) == S.npos) {
       
    }
    else {
        while (true) {
            std::string::size_type i = S.find(T);
            if (i == S.npos) {
                break;
            }
            else {
                S.erase(i, T.length());
            }
            
        }
    }
    
    if (READY_FOR_SUBMIT) {
        ostringstream stream;
        string output = stream.str();
        stream << S << endl;
        outs << stream.str();
        cout << endl << endl << endl << output << endl << endl;
        outs.close();
    }
     
    else {
        cout << endl;
        cout << S << endl;
        
    }
    
    
    return 0;
    
}





