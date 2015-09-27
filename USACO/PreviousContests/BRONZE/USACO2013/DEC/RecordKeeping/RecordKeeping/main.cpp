//
//  main.cpp
//  RecordKeeping
//
//  Created by Dhruv Shah on 8/5/15.
//  Copyright (c) 2015 DhruvShah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int N, mostOcc = 0;
string cowGroups[1001][3];

bool compGroups(string g1[3], string g2[3]) {
    int numberMatching = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(g1[i] == g2[j]) {
                numberMatching++;
            }
        }
    }
    return (numberMatching == 3);
}

int main(int argc, const char * argv[]) {
    ifstream in("records.in");
    ofstream out("records.out");
    in >> N;
    string line;
    for (int i = 0; getline(in, line); i++) {
        if (i == 0) {
            continue;
        }
        stringstream ss(line);
        for (int j = 0; j < 3; j++)
        {
            ss >> cowGroups[i - 1][j];
        }
    }
    
    
    for (int i = 0; i < N; i++) {
        int numOcc = 0;
        for (int j = 0; j < N; j++) {
            if (compGroups(cowGroups[i], cowGroups[j])) {
                numOcc++;
            }
        }
        if (numOcc > mostOcc) {
            mostOcc = numOcc;
        }
    }
    cout << mostOcc << endl;
    out << mostOcc << endl;
    return 0;
}
