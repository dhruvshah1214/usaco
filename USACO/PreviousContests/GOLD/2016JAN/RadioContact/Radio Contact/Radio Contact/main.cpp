//
//  main.cpp
//  Radio Contact
//
//  Created by Dhruv Shah on 7/13/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<char, pair<long long, long long> > dir = {{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};

long long N, M, fx, fy, bx, by;
vector<pair<long long, long long> > fj;
vector<pair<long long, long long> > bs;
string s1, s2;

long long dp[1005][1005]; // farmer pos i, bess pos j

long long sq(long long a) {
    return a * a;
}

long long euclidsq(long long f, long long b) {
    return sq(bs[b].first - fj[f].first) + sq(bs[b].second - fj[f].second);
}


int main() {
    ifstream in("radio.in");
    ofstream out("radio.out");
    
    in >> N >> M >> fx >> fy >> bx >> by;
    in >> s1 >> s2;
    
    fj.push_back(make_pair(fx, fy));
    bs.push_back(make_pair(bx, by));

    
    for (long long i = 0; i < s1.length(); i++) {
        char c = s1[i];
        
        fx += dir[c].first;
        fy += dir[c].second;
        fj.push_back(make_pair(fx, fy));
    }
    
    for (long long i = 0; i < s2.length(); i++) {
        char c = s2[i];
        
        bx += dir[c].first;
        by += dir[c].second;
        bs.push_back(make_pair(bx, by));
    }
    
    for (long long i = N; i >= 0; i--) {
        for (long long j = M; j >= 0; j--) {
            dp[i][j] = (1ll << 60);
        }
    }
    
    dp[0][0] = 0;
    for (long long i = 0; i <= N; i++) {
        for (long long j = 0; j <= M; j++) {
            if (i == j && i == 0) {
                continue;
            }
            long long cmin = dp[i][j];
            if (i - 1 >= 0) {
                cmin = min(dp[i - 1][j], cmin);
                if (j - 1 >= 0) {
                    cmin = min(dp[i - 1][j - 1], cmin);
                }
            }
            if (j - 1 >= 0) {
                cmin = min(dp[i][j - 1], cmin);
            }
            dp[i][j] = min(dp[i][j], euclidsq(i, j) + cmin);
        }
    }
    
    cout << dp[N][M] << endl;
    out << dp[N][M] << endl;

    return 0;
}
