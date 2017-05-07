//
//  main.cpp
//  Pogo-Cow
//
//  Created by Dhruv Shah on 6/21/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
    
struct target {
    int x, p;
    bool operator< (const target& rhs) const {
        return x < rhs.x;
    }
};

int N, dp[1005][1005];
target t[1005];

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t[i].x >> t[i].p;
    }
    
    sort(t, t + N);
    
    int result = 0;
    
    for (int z = 0; z < 2; z++) {
        for (int i = N - 1; i >= 0; i--) {
            int maxs = 0;
            int k = N;
            for (int j = 0; j <= i; j++) {
                while(k - 1 > i && abs(t[k - 1].x - t[i].x) >= abs(t[i].x - t[j].x)) {
                    --k;
                    maxs = max(maxs, t[k].p + dp[k][i]);
                }
                dp[i][j] = maxs;
            }
            result = max(result, t[i].p + maxs);
        }
        reverse(t, t + N);
    }
    
    cout << result << endl;
     // */
    
    return 0;
}


