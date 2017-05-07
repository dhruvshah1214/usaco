//
//  main.cpp
//  MoneyHappiness
//
//  Created by Dhruv Shah on 6/20/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>

using namespace std;

int N, D;
int money[100001], happiness[100001];
int dp[100001][100001];

int f() {
    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= N; j++) {
            if (i - money[j] < 0) {
                continue;
            }
            dp[i][j] = max(dp[i - money[j]][j - 1] + happiness[j], dp[i][j - 1]);
        }
    }
    
    return dp[D][N];
}

int main(int argc, const char * argv[]) {
    cin >> N >> D;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        money[i] = a;
        happiness[i] = b;
    }
    dp[0][0] = 0;
    
    cout << f() << endl;
    return 0;
}
