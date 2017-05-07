//
//  main.cpp
//  Longest Common Subsequence
//
//  Created by Dhruv Shah on 6/20/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int dp[2][10001];
char a[10001], b[10001];

int main(int argc, const char * argv[]) {
    string c, d;
    cin >> c >> d;
    
    for (int i = 1; i <= c.length(); i++) {
        a[i] = c[i - 1];
    }
    for (int i = 1; i <= d.length(); i++) {
        b[i] = d[i - 1];
    }


    int u = 0;    // cout << s1.length() << endl;
    
    for (int i = 0; i <= (int)c.length(); i++) {
        for (int j = 0; j <= (int)d.length(); j++) {
            if (i == 0 || j == 0) {
                dp[u][j] = 0;
            }
            else {
                if (a[i] == b[j]) {
                    dp[u][j] = max(dp[!u][j - 1] + 1, max(dp[!u][j], dp[u][j - 1]));
                }
                else {
                    dp[u][j] = max(dp[!u][j], dp[u][j - 1]);
                }
            }
        }
        u = !u;
    }
    
    cout << dp[!u][d.length()] << endl;
    return 0;
}
/*
TADFHR
ABCDAGHLM
*/