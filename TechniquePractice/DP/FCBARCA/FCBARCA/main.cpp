/*
 LANG: C++11
 TASK:
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

#define MAXINT 1 << 29
#define LL long long

using namespace std;

int T;
int N[101];
int K[101];
long long dp[101][1001];
#define MOD 1000000007L



void solve(int t) {
    int n = N[t];
    int k = K[t];
    
    dp[t][0] = 1;
    dp[t][1] = 0;
    
    for (int i = 2; i <= n; i++) {
        // disclude messi as passingoption 
        dp[t][i] = ((dp[t][i - 2] * (k)) % MOD + (dp[t][i - 1] * (k - 1)) % MOD) % MOD;
    }
}


int main(int argc, const char * argv[]) {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N[i] >> K[i];
    }
    
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    
    for (int i = 1; i <= T; i++) {
        cout << dp[i][N[i]] << endl;
    }
    
    return 0;
}


