//
//  main.cpp
//  Hay For Sale
//
//  Created by Dhruv Shah on 6/22/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N, C, size[1005];
bool dp[50005];

int main(int argc, const char * argv[]) {
    cin >> C >> N;
    for (int i = 1; i <= N; i++) {
        cin >> size[i];
    }
    
    dp[0] = true;
    
    for (int i = 0; i <= C; i++) {
        if (dp[i]) {
            for (int j = 1; j <= N; j++) {
                if (i + size[j] < C) {
                    dp[i + size[j]] = true;
                }
                else if (i + size[j] == C) {
                    cout << C << endl;
                    return 0;
                }
            }
        }
    }
    
    int ind = C;
    for (; ind >= 0; ind--) {
        if (dp[ind]) {
            break;
        }
    }
    
    cout << ind << endl;
    
    return 0;
}
