//
//  main.cpp
//  Wormholes
//
//  Created by Dhruv Shah on 8/5/15.
//  Copyright (c) 2015 DhruvShah. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

struct point {
    int x, y;
    point(int a, int b) {
        x = a;
        y = b;
    }
    point() {
        
    }
};


int N;
point wormholes[13];
int distinctPairings = 0;


int main(int argc, const char * argv[]) {
    ifstream in("wormhole.in");
    in >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        in >> a >> b;
        wormholes[i] = point(a, b);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            
        }
    }
    ofstream out("wormhole.out");
    
    return 0;
}
