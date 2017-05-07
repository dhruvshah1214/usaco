//
//  main.cpp
//  Dijkstra's Shortest Path II
//
//  Created by Dhruv Shah on 6/27/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>

#define pii pair<int, int>
#define INF 1 << 29

using namespace std;

int V, E, S;
vector<pair<int, int> > mat[50005];
int dist[50005];
bool vis[50005];

void dijk() {
    priority_queue<pii, vector<pii>, greater<pii> > q;
    for (int i = 0; i <= V; i++) {
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
        for (int i = 0; i < (int)mat[p.second].size(); i++) {
            int b = mat[p.second][i].first;
            int a = mat[p.second][i].second;
            
            if (dist[a] > dist[p.second] + b && !vis[a]) {
                dist[a] = dist[p.second] + b;
                q.push({dist[p.second] + b, a});
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            printf("-1\n");
            continue;
        }
        printf("%d\n", dist[i]);
    }
}

int main(int argc, const char * argv[]) {
    cin >> V >> E >> S;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        mat[a].push_back({c, b});
        mat[b].push_back({c, a});
    }
    dijk();
    return 0;
}
