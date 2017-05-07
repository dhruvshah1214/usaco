//
//  main.cpp
//  Knapsack
//
//  Created by Dhruv Shah on 6/22/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N, C, size[1005], value[1005], dp[1005][5005];

int main(int argc, const char * argv[]) {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> size[i] >> value[i];
    }
    
    for (int i = 0; i <= N; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= C; j++) {
            if (size[i - 1]  > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - size[i - 1]] + value[i - 1], dp[i - 1][j]);
            }
        }
    }
    
    cout << dp[N][C] << endl;
    
    return 0;
}
