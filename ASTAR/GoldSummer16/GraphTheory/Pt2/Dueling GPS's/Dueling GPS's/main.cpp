//
//  main.cpp
//  Dueling GPS's
//
//  Created by Dhruv Shah on 6/27/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 1 << 29

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pair<int, int> > mat[3][10005];
int dist[3][10005];

int dijk(int time) {
    priority_queue<pii, vector<pii>, greater<pii> > q;
    for (int i = 0; i <= N; i++) {
        dist[time][i] = INF;
    }
    int S = (time <= 1) ? N : 1;
    
    dist[time][S] = 0;
    q.push({0, S});
    
    while (!q.empty()) {
        pii p = q.top();
        q.pop();
        if (p.first != dist[time][p.second]) {
            continue;
        }
        for (int i = 0; i < (int)mat[time][p.second].size(); i++) {
            int b = mat[time][p.second][i].first;
            int a = mat[time][p.second][i].second;
            
            if (dist[time][a] > dist[time][p.second] + b) {
                dist[time][a] = dist[time][p.second] + b;
                q.push({dist[time][p.second] + b, a});
            }
        }
    }
    int dest = (time <= 1) ? 1 : N;
    return dist[time][dest];
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mat[0][b].push_back(make_pair(c, a));
        mat[1][b].push_back(make_pair(d, a));
    }
    
    dijk(0);
    dijk(1);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < mat[0][i].size(); j++) {
            int next = mat[0][i][j].second;
            int c = 0;
            int dista = mat[0][i][j].first, distb = mat[1][i][j].first;
            if (dist[0][next] - dist[0][i] != dista) {
                c++;
            }
            if (dist[1][next] - dist[1][i] != distb) {
                c++;
            }
            mat[2][next].push_back({c, i});
        }
    }
        
    int ans = dijk(2);
    cout << ans << endl;
    
    
    return 0;
}
