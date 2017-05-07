//
//  main.cpp
//  Farm Painting
//
//  Created by Dhruv Shah on 8/22/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>


using namespace std;


bool inBetween(int min, int mid, int max) {
    return min < mid && mid < max;
}

struct point {
    int x, y;
    point(int a, int b) {
        x = a, y = b;
    }
    point() {
        
    }
    
    bool xib(point a, point b) {
        return a.x < x && x < b.x;
    }
    bool yib(point a, point b) {
        return a.y < y && y < b.y;
    }
    
};

struct rect {
    point ur, ll;
    rect(point upperr, point lowerl) {
        ur = upperr;
        ll = lowerl;
    }
    rect() {
        
    }
    bool containsPoint(point p) {
        return p.xib(ll, ur) && p.yib(ll, ur);
    }
};



int N;
pair<int, pair<int, int>> events[100005];
rect r[50005];

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> r[i].ll.x >> r[i].ll.y >> r[i].ur.x >> r[i].ur.y;
        events[2 * i] = {r[i].ll.x, {i, 0}};
        events[2 * i + 1] = {r[i].ur.x, {i, 1}};
    }
    sort(events, events + 2 * N);
    
    
    
    return 0;
}
