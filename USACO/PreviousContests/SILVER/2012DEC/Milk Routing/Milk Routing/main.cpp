//
//  main.cpp
//  Milk Routing
//
//  Created by Dhruv Shah on 7/22/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>

#define pii pair<pair<int, int>, int>
#define INF 1 << 29

using namespace std;

int N, M, X;
vector<pair<pair<int, int>, int> > mat[505];
pair<int, int> dist[50005];
bool vis[50005];

int dijk() {
    priority_queue<pii, vector<pii>, greater<pii> > q;
    for (int i = 0; i <= N; i++) {
        dist[i] = {INF, INF};
        vis[i] = false;
    }
    
    dist[1] = {0, INF};
    q.push({{0, INF}, 1});
    
    while (!q.empty()) {
        pii p = q.top();
        q.pop();
        if (vis[p.second]) {
            continue;
        }
        vis[p.second] = 1;
        for (int i = 0; i < (int)mat[p.second].size(); i++) {
            int destLatency = dist[p.second].first + mat[p.second][i].first.first;
            int destCap = min(dist[p.second].second, mat[p.second][i].first.second);
            int destination = mat[p.second][i].second;
            
            double destCost = destLatency + ((1.0 * X) / destCap);
            double origCost = dist[destination].first + ((1.0 * X) / (dist[destination].second));

            if (destCost < origCost && !vis[destination]) {
                dist[destination] = {destLatency, destCap};
                q.push({dist[destination], destination});
            }
        }

    }
    /*
    for (int i = 1; i <= N; i++) {
        if (dist[i] == make_pair(INF, INF)) {
            printf("-1\n");
            continue;
        }
        printf("%d %d %d\n", i, dist[i].first, dist[i].second);
    }
     */
    
    return (int)(dist[N].first + ((1.0 * X) / dist[N].second));
}

int main(int argc, const char * argv[]) {
    
    freopen("mroute.in", "r", stdin);
    freopen("mroute.out", "w", stdout);
    
    scanf("%d %d %d", &N, &M, &X);
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        mat[a].push_back({{c, d}, b});
        mat[b].push_back({{c, d}, a});
    }
    printf("%d\n", dijk());
    
    return 0;
}