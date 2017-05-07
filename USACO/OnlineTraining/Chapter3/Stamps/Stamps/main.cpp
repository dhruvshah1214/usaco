/*
 PROG: stamps
 LANG: C++11
 */
#include <iostream>
#include <fstream>

#define INF 1 << 29

using namespace std;

int K, N, stamps[55];
int dp[205 * 10005];

int main(int argc, const char * argv[]) {
    ifstream in("stamps.in");
    ofstream out("stamps.out");
    in >> K >> N;
    for (int i = 0; i < N; i++) {
        in >> stamps[i];
    }
    // sort(stamps, stamps + N);
    dp[0] = true;
    
    for(int i = 0; i < 205 * 10005; i++) dp[i] = (K + 1);
    dp[0] = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 205 * 10005; j++){
            if(j + stamps[i] < 205 * 10005) {
               dp[j + stamps[i]] = min(dp[j + stamps[i]], dp[j] + 1); 
            }
        }
    }
    for(int i = 1; i < 205 * 10005; i++){
        if(dp[i] > K){
            out << (i - 1) << endl;
            cout << (i - 1) << endl;
            break;
        }
    }
    return 0;
}


/*
 200 14 
 1 2 4 15 9 31 63 2100 3500 127 255 511 1000 1999 */

