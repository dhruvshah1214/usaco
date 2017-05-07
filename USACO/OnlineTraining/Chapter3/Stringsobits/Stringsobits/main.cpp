/*
 TASK: kimbits
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>

using namespace std;

int N, I, L;
long long dp[33][33];



int main(int argc, const char * argv[]) {
    ifstream in("kimbits.in");
    ofstream out("kimbits.out");
    
    in >> N >> L >> I;
    for (int j = 0; j <= N + 1; j++) {
        dp[0][j] = 1;
        dp[j][0] = 1;
        dp[j][j] = 1;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    string s = "";
    int curL = L;
    for (int i = 0; i < N; i++) {
        cout << N - i - 1 << " " << curL << endl;
        cout << dp[N - i - 1][curL] << " " << I << endl;

        if (dp[N - i - 1][curL] >= I && curL != I) {
            s += '0';
        }
        else {
            s += '1';
            I -= dp[N - i - 1][curL];
            curL--;
        }

    }
    
    cout << s << endl;
    out << s << endl;
    
    return 0;
}

/*
 Suppose that a1a2..aN is a binary string.
 
 if num_of_possibilities(0 a2a3...aN) < I. Then the first bit could not be 0. Otherwise the first bit would be exactly zero.
 
 By deciding whether it is 0 or 1, you can solve the rest of the string by solving a new problem where N'=N-1, L'=L (or L'=L-1 if the first bit is 1) and I'=I (or I'= I - num_of_possibilities(0a2a3...aN) if the first bit is 1).
*/