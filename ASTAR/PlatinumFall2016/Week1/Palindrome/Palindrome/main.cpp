//
//  main.cpp
//  Palindrome
//
//  Created by Dhruv Shah on 9/12/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>

using namespace std;

int dp[2][5005];
char a[5005], b[5005];

int main(int argc, const char * argv[]) {
    int N;
    string c;
    cin >> N >> c;
    
    for (int i = 1; i <= c.length(); i++) {
        a[i] = c[i - 1];
        b[i] = c[c.length() - i];
    }
    
    
    int u = 0;    // cout << s1.length() << endl;
    
    for (int i = 0; i <= (int)c.length(); i++) {
        for (int j = 0; j <= (int)c.length(); j++) {
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
    
    cout << N - dp[!u][c.length()] << endl;
    return 0;
}

