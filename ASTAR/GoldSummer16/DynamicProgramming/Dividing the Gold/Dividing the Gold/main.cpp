//
//  main.cpp
//  Dividing the Gold
//
//  Created by Dhruv Shah on 6/22/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>

#define MOD 1000000

using namespace std;

long long N, tSum = 0, coins[255], dp[3][500005];

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> coins[i];
        tSum += coins[i];
    }
    
    long long singleSum = (tSum + 1) / 2;

    sort(coins, coins + N);
    
    dp[0][0] = 1;
    dp[1][0] = 1;
    
    int u = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= tSum; j++) {
            if (j >= coins[i]) {
                dp[u][j] = ((dp[!u][j - coins[i]]) + (dp[!u][j]) % MOD);
            }
            else if(j == 0) { 
                dp[u][j] = 1;
            }
            else {
                dp[u][j] = (dp[!u][j] % MOD);
            }
        }
        u = !u;
    }
    long long first = singleSum;
    for (; first <= tSum; first++) {
        if (dp[!u][first] > 0) {
            break;
        }
    }
    
    long long second = (tSum / 2);
    for (; second >= 0; second--) {
        if (dp[!u][second] > 0) {
            break;
        }
    }
    
    
    cout << abs(first - second) << endl << (min(dp[!u][second], dp[!u][first]) % MOD) << endl;
}
