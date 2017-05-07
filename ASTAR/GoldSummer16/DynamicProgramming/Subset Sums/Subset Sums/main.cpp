#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, K;
long long dp[1000][1000];

int main(int argc, const char * argv[]) {
    cin >> N;
    K = N * (N+1) / 2;
    
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 1;
    }
    dp[0][0] = 0;
    
    if (K % 2 == 1) {
        cout << 0 << endl;
        out << 0 << endl;
        return 0;
    }
    
    
    int singleSum = K / 2;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= singleSum; j++) {
            dp[i][j] = dp[i - 1][j - i] + dp[i - 1][j];
        }
    }
    
    cout << dp[N][singleSum] << endl;
    
    return 0;
}
