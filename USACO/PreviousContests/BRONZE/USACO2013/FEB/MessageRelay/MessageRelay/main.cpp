//
//  main.cpp
//  MessageRelay
//
//  Created by Dhruv Shah on 12/19/15.
//  Copyright © 2015 USACO. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, cows[1001], zeroes[1001], zeroescount = 0, solution = 0;
bool counted[1001];

void solveN(int A) {
    for (int i = 1; i <= N; i++) {
        if (cows[i] == A) {
            if (!counted[i]) {
                counted[i] = true;
                solution++;
            }
            solveN(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream in("relay.in");
    ofstream out("relay.out");

    in >> N;
    
    for (int i = 1; i <= N; i++) {
        in >> cows[i];
        if (cows[i] == 0) {
            zeroes[zeroescount] = i;
            zeroescount++;
        }
        counted[i] = false;
    }
    solution += zeroescount;
    for (int i = 0; i < zeroescount; i++) {
        counted[zeroes[i]] = true;
        solveN(zeroes[i]);
    }
    
    out << solution << endl;
    
    return 0;
}
