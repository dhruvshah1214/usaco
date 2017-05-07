//
//  main.cpp
//  String Edit Distance
//
//  Created by Dhruv Shah on 6/23/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <string>

#define INF 1 << 29

using namespace std;

char a[1005], b[1005];
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
    
    
    for (int i = 0; i <= (int)c.length(); i++) {
        for (int j = 0; j <= (int)d.length(); j++) {
            dp[0][j] = j;
            
            dp[i][0] = i;
            
            
            int minn = INF;
            int num;
            if (a[i] == b[j]) {
                num = dp[i - 1][j - 1];
            }
            else {
                num = dp[i - 1][j - 1] + 1;
            }
            minn = min(minn, min(min(num, dp[i][j - 1] + 1), dp[i - 1][j] + 1));
            dp[i][j] = minn;
        }
    }
    
    cout << dp[c.length()][d.length()] << endl;
    
    return 0;
}
