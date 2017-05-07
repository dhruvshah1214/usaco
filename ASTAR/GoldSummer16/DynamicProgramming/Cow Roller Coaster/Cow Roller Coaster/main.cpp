//
//  main.cpp
//  Cow Roller Coaster
//
//  Created by Dhruv Shah on 6/22/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1 << 29

using namespace std;

int L, B, N, Xi[10005], Wi[10005], Fi[10005], Ci[10005], dp[1005][1005];
vector<int> arr[1005];

int main(int argc, const char * argv[]) {
    cin >> L >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> Xi[i] >> Wi[i] >> Fi[i] >> Ci[i];
        arr[Xi[i]].push_back(i);
    }
    
    for (int i = L; i >= 0; i--) {
        
        for (int j = 0; j <= B; j++) {
            int maxFun = 0;
            if (i == L) {
                maxFun = 0;
            }
            else {
                maxFun = -1 * INF;
            }
            for (int k = 0; k < arr[i].size(); k++) {
                int curSegment = arr[i][k];
                int endOfCurSegment = Xi[curSegment] + Wi[curSegment];
                if (j - Ci[curSegment] >= 0 && 0 <= endOfCurSegment && endOfCurSegment <= L) {
                    maxFun = max(maxFun, Fi[curSegment] + dp[endOfCurSegment][j - Ci[curSegment]]);
                }
            }
            dp[i][j] = maxFun;
        }
    }
    
    
    /*
    for (int i = 0; i <= L; i++) {
        for (int j = 0; j <= B; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    if (dp[0][B] < 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[0][B] << endl;
    return 0;
}
