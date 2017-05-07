#include <iostream>
#include <algorithm>

#define MOD 1000000

using namespace std;

int T, A, S, B, maxJ[1005], dp[100005][2];

int realMod(int c) {
    while (c < 0) {
        c += MOD;
    }
    return (c % MOD);
}

int main(int argc, const char * argv[]) {
    cin >> T >> A >> S >> B;
    for (int i = 0; i < A; i++) {
        int a;
        cin >> a;
        maxJ[a]++;
    }
    
    int u = 0;
    for (int j = 0; j <= T; j++) {
        for (int i = 0; i <= A; i++) {
            if (j == 0) {
                dp[j][u] = 1;
                continue;
            }
                dp[i][u] = ((dp[i - 1][u] + dp[i][!u]) % MOD);

                if (i - maxJ[j] - 1 >= 0) {
                    dp[i][u] -= dp[i - maxJ[j] - 1][!u];
                }
            dp[i][u] = (dp[i][u] % MOD);
        }        
        u = !u;
    }
    
    int sum = 0;
    for (int i = S; i <= B; i++) {
        sum = realMod((sum + dp[i][!u]));
    }
    cout << sum << endl;
    
    return 0;
}
