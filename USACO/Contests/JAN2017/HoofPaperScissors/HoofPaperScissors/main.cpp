//
//  main.cpp
//  HoofPaperScissors
//
//  Created by Dhruv Shah on 1/15/17.
//  Copyright © 2017 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, K;
char play[100005];
int dp[100005][25][3];

int beats(char a, char b) {
    if (a == 'P' && b == 'H') {
        return 1;
    }
    if(a == 'S' && b =='P') return 1;
    if (a == 'H' && b == 'S') {
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    ifstream in("hps.in");
    ofstream out("hps.out");
    
    bool debug = 0;
    
    if(debug) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> play[i];
        }
    }
    else {
        in >> N >> K;
        for (int i = 1; i <= N; i++) {
            in >> play[i];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + beats('H', play[i]));
            if(j > 0) dp[i][j][0] = max(dp[i][j][0], max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + beats('H', play[i]));
            
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + beats('P', play[i]));
            if(j > 0) dp[i][j][1] = max(dp[i][j][1], max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]) + beats('P', play[i]));

            
            dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][2] + beats('S', play[i]));
            if(j > 0) dp[i][j][2] = max(dp[i][j][2], max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + beats('S', play[i]));

        }
    }
    
    cout << max(dp[N][K][0], max(dp[N][K][1], dp[N][K][2])) << endl;
    out << max(dp[N][K][0], max(dp[N][K][1], dp[N][K][2])) << endl;

    return 0;
}
