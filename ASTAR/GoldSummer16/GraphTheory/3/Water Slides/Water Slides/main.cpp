//
//  main.cpp
//  Water Slides
//
//  Created by Dhruv Shah on 6/17/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

#define INF 1 << 29

using namespace std;

struct plat {
    int thepos, degree;
    plat(int a, int b) {
        thepos = a, degree = b;
    }
    plat() {

    }
};

plat p[10005];

bool platsort(plat a, plat b) {
    return a.thepos < b.thepos;
}

int N, M;

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> p[i].thepos;
        p[i].degree = 0;
    }
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        p[b].degree--;
        p[a].degree++;
    }
    sort(p + 1, p + N + 1, platsort);
    int degcnt = 0;
    long long walk = 0;
    for (int i = 1; i <= N; i++) {
        degcnt += p[i].degree;
        walk += abs(degcnt * (p[i + 1].thepos - p[i].thepos));
    }
    cout << walk << endl;
    return 0;
}
