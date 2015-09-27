//
//  main.cpp
//  ReorderingCows
//
//  Created by Dhruv Shah on 7/21/15.
//  Copyright (c) 2015 DhruvShah. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int N, origArr[101], endArr[101];

/*
 51423
 25314
 */

int firstCycleStartIndex = -1;
int numCycles = 0;
int longestCycle = -1;
int curCycle = 0;

void performCycleShift(int number) {
    int correctPos = -1;
    int numAtDestination = -1;
    for (int i = 0; i < N; i++) {
        if (endArr[i] == number) {
            correctPos = i;
            numAtDestination = origArr[i];
        }
    }
    origArr[correctPos] = number;
    curCycle++;
    
    if (correctPos != firstCycleStartIndex) {
        performCycleShift(numAtDestination);
    }
    else {
        numCycles++;
        if (curCycle > longestCycle) {
            longestCycle = curCycle;
        }
        curCycle = 0;
        
    }
    
}

int main(int argc, const char * argv[]) {
    ifstream in("reorder.in");
    ofstream out("reorder.out");
    
    in >> N;
    
    for (int a = 0; a < 2; a++) {
        for (int i = 0; i < N; i++) {
            switch (a) {
                case 0:
                    in >> origArr[i];
                    break;
                case 1:
                    in >> endArr[i];
                    break;
                default:
                    break;
            }
        }
    }
    bool allCorrect = false;
    while (!allCorrect) {
        for (int i = 0; i < N; i++) {
            if (origArr[i] != endArr[i]) {
                firstCycleStartIndex = i;
                break;
            }
            if (i == N - 1) {
                // arrays identical
                allCorrect = true;
            }
        }
        if (!allCorrect) {
            performCycleShift(origArr[firstCycleStartIndex]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << origArr[i];
    }
    cout << endl;
    
    cout << endl << endl;
    cout << numCycles << " " << longestCycle << endl;
    out << numCycles << " " << longestCycle << endl;

    return 0;
}

