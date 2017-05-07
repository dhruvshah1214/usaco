//
//  main.cpp
//  Breed Proximity
//
//  Created by Dhruv Shah on 6/24/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, K, breed[50005], dp[50005];
map<int, int> last;

int main(int argc, const char * argv[]) {
    cin >> N >>  K;
    for (int i = 1; i <= N; i++) {
        cin >> breed[i];
    }
    dp[0] =  -1;
    for (int i = 1; i <= N; i++) {
        if (last[breed[i]] > 0) {
            if (i - last[breed[i]] <= K) {
                dp[i] = max(dp[i - 1], breed[i]);
            }
        }
        if (dp[i] == 0) {
            dp[i] = dp[i - 1];
        }
        last[breed[i]] = i;
    }
    
    cout << dp[N] << endl;
    
    
    return 0;
}
