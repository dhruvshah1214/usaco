//
//  main.cpp
//  Cow Hopscotch
//
//  Created by Dhruv Shah on 6/24/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int R, C, K, mat[101][101], dp[101][101];

int main(int argc, const char * argv[]) {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mat[i][j];
        }
    }
    
    dp[0][0] = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = i - 1; k >= 0; k--) {
                for (int l = j - 1; l >= 0; l--) {
                    if (mat[k][l] != mat[i][j]) {
                        dp[i][j] += (dp[k][l] % MOD);
                        dp[i][j] %= MOD;
                    }
                    
                }
            }
        }
    }
    cout << dp[R - 1][C - 1] << endl;
    return 0;
}
