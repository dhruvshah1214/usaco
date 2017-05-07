    //
//  main.cpp
//  Fruit Feast
//
//  Created by Dhruv Shah on 6/22/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int T, A, B;
bool dp[2][5000005];

int main(int argc, const char * argv[]) {
    ifstream in("feast.in");
    ofstream out("feast.out");
    
    bool d = false;
    
    if (d) {
        cin >> T >> A >> B;
    }
    else {
        in >> T >> A >> B;
    }
    
    dp[0][0] = true;
    dp[1][0] = true;
    for (int i = 1; i <= T; i++) {
        if (i >= A) {
            dp[0][i] = dp[0][i] || dp[0][i - A];
        }
        if (i >= B) {
            dp[0][i] = dp[0][i] || dp[0][i - B];
        }
    }
    for (int i = 1; i <= T; i++) {
        if (2 * i <= T) {
            dp[1][i] = dp[1][i] || dp[0][i * 2];
        }
        if (2 * i + 1 <= T) {
            dp[1][i] = dp[1][i] || dp[0][i * 2 + 1];
        }
        if (i - A >=  0) {
            dp[1][i] = dp[1][i] || dp[1][i - A];
        }
        if (i - B >= 0) {
            dp[1][i] = dp[1][i] || dp[1][i - B];
        }
    }
    
    int i = T;
    for (; i >= 0; i--) {
        if (dp[0][i] || dp[1][i]) {
            break;
        }
    }
    out << i << endl;
    cout << i << endl;

    return 0;
}
