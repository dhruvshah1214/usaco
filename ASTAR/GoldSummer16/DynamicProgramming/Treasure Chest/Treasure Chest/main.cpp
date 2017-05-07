//
//  main.cpp
//  Treasure Chest
//
//  Created by Dhruv Shah on 6/24/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N, C[5001];
int sum[5001];
int dp[5002][2];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }
    
    sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + C[i];
    }
    
    int u = 0;
    
    for (int j = 1; j <= N; j++) {
        for (int i = j; i >= 1; i--) {
            if (i == j) {
                dp[i][u] = C[i];
            }
            int sumr = sum[j] - sum[i - 1];
            dp[i][u] = sumr - min(dp[i + 1][u], dp[i][!u]); 
        }
        u = !u;
    }
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 2; j <= N; j++) {
            
        }
    }
    
    cout << dp[1][!u] << endl;
    
    return 0;
}

// d[i][j] = max(d[I + 1][j], d[i][j - 1]);
