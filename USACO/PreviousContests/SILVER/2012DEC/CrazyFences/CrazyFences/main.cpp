//
//  main.cpp
//  CrazyFences
//
//  Created by Dhruv Shah on 9/11/15.
//  Copyright (c) 2015 USACO. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct fence {
    int x1, x2, y1, y2;
    fence() {
        
    }
    fence(int a, int b, int c, int d) {
        x1 = a, x2 = b, y1 = c, y2 = d;
    }
};

struct cow {
    int x, y;
    cow() {
        
    }
    cow(int a, int b) {
        x = a, y = b;
    }
};

cow cows[1001];
fence fences[1001];
int N, C;

int main(int argc, const char * argv[]) {
    ifstream in("crazy.in");
    ofstream out("crazy.out");
    
    in >> N >> C;
    
    
    return 0;
}
