//
//  main.cpp
//  EatingTogether
//
//  Created by Dhruv Shah on 6/21/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define INF 1 << 29

using namespace std;

int N, dining[30005], dp[30005][5]; // [30005];

int f(bool ascend) {
    memset(dp, 0, sizeof(dp));
    for (int i = N - 1; i >= 0; i--) {
        if (ascend) {
            for (int minn = 1; minn <= 3; minn++) {
                int ans = INF;
                for (int k = minn; k <= 3; k++) {
                    int cost = (k != dining[i]);
                    ans = min(ans, dp[i + 1][k] + cost);
                }
                dp[i][minn] = ans;
            }
        }
        else {
            for (int maxi = 3; maxi >= 1; maxi--) {
                int ans = INF;
                for (int k = maxi; k >= 1; k--) {
                    int cost = (k != dining[i]);
                    ans = min(ans, dp[i + 1][k] + cost);
                }
                dp[i][maxi] = ans;
            }
        }
        
    }
    /*
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    return min(dp[0][1], min(dp[0][2], dp[0][3]));
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dining[i];
    }
    
    //cout << "HELLO" << endl;
    
    cout << min(f(true), f(false)) << endl;
    return 0;
}
/*
RECURSIVE DP FORMULA:
 
 dp[i] = dp[i - 1]

*/