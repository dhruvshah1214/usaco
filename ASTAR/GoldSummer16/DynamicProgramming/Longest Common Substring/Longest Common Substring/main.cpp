//
//  main.cpp
//  Longest Common Substring
//
//  Created by Dhruv Shah on 6/23/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

char a[1002], b[1002];
int dp[1005][1005];

int main(int argc, const char * argv[]) {
    string c, d;
    cin >> c >> d;
    
    for (int i = 1; i <= c.length(); i++) {
        a[i] = c[i - 1];
    }
    for (int i = 1; i <= d.length(); i++) {
        b[i] = d[i - 1];
    }
    
    int maxn = 0;
    
    for (int i = 0; i <= c.length(); i++) {
        for (int j = 0; j <= d.length(); j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = 0;
                }
            }
            maxn = max(maxn, dp[i][j]);
        }
    }
    cout << maxn << endl;
    return 0;
}
