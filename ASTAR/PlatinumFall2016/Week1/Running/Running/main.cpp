//
//  main.cpp
//  Running
//
//  Created by Dhruv Shah on 9/11/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>

using namespace std;

long long N, M, d[10005];
long long dp[10005];

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    d[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    
    dp[0] = 0;
    
    for (int i = 0; i < N; i++) {
        //  best (m, 0) = MAX (best (m - 1, 0), best (m - 1, 1))
        dp[i + 1] = max(dp[i + 1], dp[i]);

        for (int j = 1; j <= M; j++) {
            dp[i + 2*j] = max(dp[i + 2*j], dp[i] + (d[i + j] - d[i]));
        }
    }
    
    
    
    /*
    for (int i = 0; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i <= N; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    */
    cout << dp[N] << endl;
    
    
    
    return 0;
}
