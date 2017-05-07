//
//  main.cpp
//  Milking Time
//
//  Created by Dhruv Shah on 6/23/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct interval {
    int start, end, effeciency;
    interval(int a, int b, int c) {
        start = a, end = b, effeciency = c;
    }
    interval() {
        
    }
    bool operator< (const interval& b) const {
        return end < b.end;
    }
};

interval il[1005];
int N, M, R;
int dp[2000005];

int main(int argc, const char * argv[]) {
    cin >> N >> M >> R;
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        il[i] = interval(a, b + R, c);
    }
    sort(il, il + M);
    
    dp[0] = 0;
    
    long lastFound = 0;
    for (int i = 1; i <= N + R; i++) {
        int maxE = dp[i - 1];
        long curS = lower_bound(il + lastFound, il + M, interval(0, i, 0)) - il;
        while (il[curS].end == i) {
            int startS = il[curS].start;
            maxE = max(maxE, il[curS].effeciency + dp[startS]);
            curS++;
        }
        lastFound = curS;
        dp[i] = maxE;
    }
    
    cout << dp[N + R] << endl;
    
    
    return 0;
}
