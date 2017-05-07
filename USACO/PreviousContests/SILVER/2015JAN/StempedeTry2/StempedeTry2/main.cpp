//
//  main.cpp
//  StempedeTry2
//
//  Created by Dhruv Shah on 11/12/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

int N;

struct cow {
    int x, y, r;
} cows[50005];

typedef pair<int, pair<int, int> > dpii;

dpii visible[50005];
bool seen[50005];

bool custsort(const dpii &p1, const dpii &p2) {
    return p1.first < p2.first;
}

bool ysort(const dpii &p1, const dpii &p2) {
    return p1.second.first < p2.second.first;
}

set<dpii, bool(*)(const dpii& lhs, const dpii& rhs)> cowSet(&ysort);


void calcVisible() {
    for (int i = 0; i < N; i++) {
        visible[i] = make_pair(cows[i].r * cows[i].x, make_pair(cows[i].r * (cows[i].x + 1), i));
    }
}

int main(int argc, const char * argv[]) {
    ifstream in("stampede.in");
    ofstream out("stampede.out");
    
    bool debug = 1;
    
    if (debug) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            int l;
            cin >> l >> cows[i].y >> cows[i].r;
            cows[i].x = l + 1;
        }
    }
    else {
        in >> N;
        for(int i = 0; i < N; i++) {
            int l;
            in >> l >> cows[i].y >> cows[i].r;
            cows[i].x = l + 1;
        }
    }
    
    calcVisible();
    
    int t = visible[0].first;
    cowSet.insert(visible[0]);
    seen[0] = true;
    
    for (int i = 1; i < N; i++) {
        
    }
}
