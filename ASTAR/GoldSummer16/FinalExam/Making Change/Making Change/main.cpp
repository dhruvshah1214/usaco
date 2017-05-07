//
//  main.cpp
//  Making Change
//
//  Created by Dhruv Shah on 7/1/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 1 << 29

using namespace std;

int N, C, coins[11], dp[2010];

int main(int argc, const char * argv[]) {
    cin >> C >> N;
    for (int i = 0; i <= C; i++) {
        dp[i] = INF;
    }
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    dp[0] = 0;
    sort(coins, coins + N);
    
    for (int i = 0; i <= C; i++) {
        if (dp[i] > 0) {
            for (int j = 0; j < N; j++) {
                if (i + coins[j] < C + 100) {
                    dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
                }
            }
        }
    }
    /*
    for (int i = 0; i <= C; i++) {
        cout << dp[i] << endl;
    }*/
     
    
    cout << dp[C] << endl;
    
    return 0;
}
