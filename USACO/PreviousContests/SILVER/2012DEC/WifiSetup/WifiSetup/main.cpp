//
//  main.cpp
//  WifiSetup
//
//  Created by Dhruv Shah on 7/18/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <limits>

using namespace std;



long long N, A, B, pos[2005];
long double dp[2005];

int main(int argc, const char * argv[]) {
    freopen("wifi.in", "r", stdin);
    freopen("wifi.out", "w", stdout);

    scanf("%lld %lld %lld", &N, &A, &B);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &pos[i]);
    }
    sort(pos, pos + N);
    
    long double INF = (numeric_limits<long double>::max() / 8.0);

    
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], A + B * ((pos[i - 1] - pos[j])/2.0) + dp[j]);
        }
    }
    long int dpnInt = (long int)dp[N];
    if (((long double)dpnInt) == ((long double)dp[N])) {
        printf("%.0Lf\n", dp[N]);
    }
    else {
        printf("%.1Lf\n", dp[N]);
    }
    
    return 0;
}
