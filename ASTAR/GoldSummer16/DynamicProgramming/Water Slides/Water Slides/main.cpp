//
//  main.cpp
//  Water Slides
//
//  Created by Dhruv Shah on 6/23/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

#define INF 1ll << 60

using namespace std;

long long V, E, K, P[150005], Q[150005], F[150005];
long long dp[50005][11];
vector<int> start[50005];
// vector<int> endP[50005];

/*
 DP STATE:
 
 dp[i][j] = min happiness you can achieve starting at pool i with j slides left to lose control on.
 
 i from 0 to V
 j from K to 0
*/

long long dpfunc(long long pool, long long j) {
    if (pool == V) {
        return 0;
    }
    if (dp[pool][j] == -1) {
        long long mindp = INF;
        long long maxdp = 0;
        for (int i = 0; i < (int)start[pool].size(); i++) {
            int ind = start[pool][i];
            if (j > 0) {
                mindp = min(mindp, F[ind] + dpfunc(Q[ind], j - 1));
            }
            maxdp = max(maxdp, F[ind] + dpfunc(Q[ind], j));
        } 
        dp[pool][j] = min(mindp, maxdp);
    }
    
    return dp[pool][j];
}

int main(int argc, const char * argv[]) {
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        cin >> P[i] >> Q[i] >> F[i];
        start[P[i]].push_back(i);
        // endP[Q[i]].push_back(i);

    }
    memset(dp, -1, sizeof(dp));
    
    cout << dpfunc(1, K) << endl;
    
    return 0;
}
