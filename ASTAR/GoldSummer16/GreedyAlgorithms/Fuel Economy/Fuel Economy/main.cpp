//
//  main.cpp
//  Fuel Economy
//
//  Created by Dhruv Shah on 6/29/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>

using namespace std;

struct station {
    int pos, cost;
    bool operator<(station const& s) const {
        return pos < s.pos;
    }
} stations[50005];

int s[50005];
int nextSmall[50005];
int N, G, B, D;

int main() {

    scanf("%d %d %d %d", &N, &G, &B, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d", &stations[i].pos);
        scanf("%d", &stations[i].cost);
    }
    sort(stations, stations + N);
    
    int stacklen = 0;
    for (int i = N - 1; i >= 0; i--) {
        while (stacklen > 0 && stations[s[stacklen - 1]].cost >= stations[i].cost) {
            stacklen--;
        }
        nextSmall[i] = (stacklen == 0 ? -1 : s[stacklen-1]);
        s[stacklen] = i;
        stacklen++;
    }
    
    B -= stations[0].pos;
    long long cost = 0;
    for (int i = 0; i < N; i++) {
        if (B < 0) {
            printf("-1\n");
            return 0;
        }
        int gasNeeded = min(G, ((nextSmall[i] == -1) ? D : (stations[nextSmall[i]].pos)) - stations[i].pos);
        if (gasNeeded > B) {
            cost += (long long) (gasNeeded - B) * (long long) stations[i].cost;
            B = gasNeeded;
        }
        B -= ((i == N - 1) ? D : stations[i+1].pos) - stations[i].pos;
    }
    
    if (B < 0) {
        printf("-1\n");
    } else {
        printf("%lld\n", cost);
    }
}
