//
//  main.cpp
//  Meet&Greet
//
//  Created by Dhruv Shah on 8/8/15.
//  Copyright (c) 2015 DhruvShah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int B, E;
const int INPUT_UPPER = 50000;
int B_POS = 0;
int E_POS = 0;
int B_MOVES[INPUT_UPPER + 1], E_MOVES[INPUT_UPPER + 1];
int numCrosses = 0;

int main(int argc, const char * argv[]) {
    ifstream in("greetings.in");
    ofstream out("greetings.out");
    
    in >> B >> E;
    for (int i = 0; i < B; i++) {
        in >> B_MOVES[i];
        char c;
        in >> c;
        if (c == 'L') {
            B_MOVES[i] *= -1;
        }
    }
    for (int i = 0; i < E; i++) {
        in >> E_MOVES[i];
        char c;
        in >> c;
        if (c == 'L') {
            E_MOVES[i] *= -1;
        }
    }
    int time = 0;
    int currBMove = 0;
    int currEMove = 0;
    
    
    int bDist = 0;
    int eDist = 0;

    bool bDone = false;
    bool eDone = false;

    for (int i = 0; i < B; i++) {
        cout << B_MOVES[i] << endl;
        
    }
    for (int i = 0; i < E; i++) {
        cout << E_MOVES[i] << endl;
        
    }
    cout << endl;
    bool wasConnectedLast = true;
    while (!bDone || !eDone) {
        int bMove = B_MOVES[currBMove];
        int eMove = E_MOVES[currEMove];
        if (!bDone) {
            B_POS += bMove / abs(bMove);

        }
        if (!eDone) {
            E_POS += eMove / abs(eMove);

        }
        
        bDist++;
        eDist++;

        if (bDist == abs(bMove)) {
            if (currBMove != B - 1) {
                currBMove++;
            }
            else {
                bDone = true;
            }
            bDist = 0;
        }
        if (eDist == abs(eMove)) {
            if (currEMove != E - 1) {
                currEMove++;
            }
            else {
                eDone = true;
            }
            eDist = 0;

        }
        
        time++;
        if (wasConnectedLast && B_POS != E_POS) {
            wasConnectedLast = false;
        }
        if (!wasConnectedLast && B_POS == E_POS) {
            numCrosses++;
            wasConnectedLast = true;
        }
        
        cout << time << " " << B_POS << " " << E_POS << " CURRENT MOVE: " << bMove << " " << eMove << endl;
    }
    
    cout << numCrosses << endl;
    out << numCrosses << endl;
    return 0;
}
