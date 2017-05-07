//
//  main.cpp
//  Distant Pastures
//
//  Created by Dhruv Shah on 6/27/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#include <fstream>
#include <string>
#include <iomanip>


#define INF 1ll << 60

using namespace std;

typedef pair<long long, long long> pii;

long long N, A, B;
vector<pii> mat[50005];

long long dist[905];
bool vis[905];
pii node[905];
char farm[35][35];

const long long dx[4] = {0, 0, 1, -1};
const long long dy[4] = {1, -1, 0, 0};

bool bound(long long x, long long y) {
    return (1 <= x) && (x <= N) && (1 <= y) && (y <= N);
}

long long nodeNum(long long i, long long j) {
    return N * (i - 1) + j;
}

pii indexFarm(long long noden) {
    long long j = (noden % N);
    if (j == 0) {
        j = N;
    }
    return {((noden + (N - 1)) / N), j};
}

long long dijk(long long S) {
    priority_queue<pii, vector<pii>, greater<pii> > q;
    
    long long NN = N * N;
    for (long long i = 0; i <= NN; i++) {
        dist[i] = INF;
        vis[i] = false;
    }
    
    dist[S] = 0;
    q.push({0, S});
    
    while (!q.empty()) {
        pii p = q.top();
        q.pop();
        if (vis[p.second]) {
            continue;
        }
        vis[p.second] = 1;
        for (long long i = 0; i < mat[p.second].size(); i++) {
            long long a = mat[p.second][i].second;
            long long b = mat[p.second][i].first;
            
            if (dist[a] > dist[p.second] + b) {
                dist[a] = dist[p.second] + b;
                q.push({dist[p.second] + b, a});
            }
        }
    }
    long long ma = 0;
    for (long long i = 1; i <= NN; i++) {
        if (dist[i] != INF) {
            ma = max(ma, dist[i]);
        }
    }
    return ma;
}

long long solve() {
    long long sol = 0;
    for (long long i = 1; i <= N * N; i++) {
        sol = max(sol, dijk(i));
    }
    return sol;
}

int main() {
    cin >> N >> A >> B;
    char z;
    cin.get(z);
    
    for (long long i = 1; i <= N; i++) {
        for (long long j = 1; j <= N; j++) {
            char c;
            cin.get(c);
            farm[i][j] = c;
            node[(N * (i - 1)) + j] = {i, j};
        }
        char d;
        cin.get(d);
    }
    
    for (long long i = 1; i <= N; i++) {
        for (long long j = 1; j <= N; j++) {
            for (long long k = 0; k < 4; k++) {
                long long nx = i + dx[k];
                long long ny = j + dy[k];
                if (bound(nx, ny)) {
                    if (farm[i][j] != farm[nx][ny]) {
                        mat[nodeNum(i, j)].push_back({B, nodeNum(nx, ny)});
                        mat[nodeNum(nx, ny)].push_back({B, nodeNum(i, j)});
                    }
                    else {
                        mat[nodeNum(i, j)].push_back({A, nodeNum(nx, ny)});
                        mat[nodeNum(nx, ny)].push_back({A, nodeNum(i, j)});
                    }
                }
            }
        }
    }
    
    
    long long sl = solve();
    cout << sl << endl;
    return 0;
}
