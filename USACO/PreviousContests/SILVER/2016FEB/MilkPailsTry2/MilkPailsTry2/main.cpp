//
//  main.cpp
//  MilkPailsTry2
//
//  Created by Dhruv Shah on 11/14/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int X, Y, K, M;
int minError = (1 << 29);
int mem[105][105][105];

int recurse(int x, int y, int curK) {
    if (mem[x][y][curK] != -1) {
        return mem[x][y][curK];
    }
    if (curK == K) {
        return abs((x + y) - M);
    }
     
    int theMin = (1 << 29);
    
    // fill x, fill y to top
    if (x < X) {
        theMin = min(theMin, recurse(X, y, curK + 1));
    }
    if (y < Y) {
        theMin = min(theMin, recurse(x, Y, curK + 1));
    }
    
    // empty x, y
    if (x > 0) {
        theMin = min(theMin, recurse(0, y, curK + 1));
    }
    if (y > 0) {
        theMin = min(theMin, recurse(x, 0, curK + 1));
    }
    
    // pour x into y
    if (x > 0 && y < Y) {
        int amountToPour = min(x, Y - y);
        if (amountToPour > 0) {
            theMin = min(theMin, recurse(x - amountToPour, y + amountToPour, curK + 1));
        }
    }
    
    // pour y into x
    if (y > 0 && x < X) {
        int amountToPour = min(X - x, y);
        if (amountToPour > 0) {
            theMin = min(theMin, recurse(x + amountToPour, y - amountToPour, curK + 1));
        }
    }
    
    mem[x][y][curK] = theMin;
    return mem[x][y][curK];
}

int main(int argc, const char * argv[]) {
    ifstream in("pails.in");
    ofstream out("pails.out");
    
    bool debug = false;
    
    if(debug) {
        cin >> X >> Y >> K >> M;
    }
    else {
        in >> X >> Y >> K >> M;
    }
    
    for (int i = 0; i <= X; i++) {
        for (int j = 0; j <= Y; j++) {
            for (int k = 0; k <= K; k++) {
                mem[i][j][k] = -1;
            }
        }
    }
    
    int ans = recurse(0, 0, 0);
    
    cout << ans << endl;
    out << ans << endl;
    
    return 0;
}
