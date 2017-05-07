//
//  main.cpp
//  Longest Increasing Subsequence
//
//  Created by Dhruv Shah on 6/20/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N, seq[20005], dp[20005];

int f() {
    int ans = 0;
    for (int i = 1; i < N; i++) {
        int maxdp = 0;
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                maxdp = max(maxdp, dp[j]); 
            }
        }
        dp[i] = 1 + maxdp;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }
    dp[0] = 0;
    cout << f() << endl;
    
    return 0;
}
