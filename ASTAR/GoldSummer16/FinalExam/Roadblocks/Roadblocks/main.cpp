//
//  main.cpp
//  Roadblocks
//
//  Created by Dhruv Shah on 7/1/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

#define INF 1 << 29

using namespace std;
typedef pair<long long, long long> pii;

int N, R;
vector<pii> mat[100005];
long long dist[5005];
long long parent[5005];
long long parentC[5005];
bool vis[5005];
pair<pii, long long> edges[100005];

long long dijk(long long S, pair<pii, long long> removedEdge) {
    // cout << "DIJK " << endl;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    
    for (long long i = 0; i <= N; i++) {
        dist[i] = INF;
        vis[i] = false;
    }
    
    dist[S] = 0;
    q.push({0, S});
    
    long long blockedS = removedEdge.first.first;
    long long blockedD = removedEdge.first.second;
    long long blockedC = removedEdge.second;
    
    while (!q.empty()) {
        pii p = q.top();
        q.pop();
        if (vis[p.second]) {
            continue;
        }
        vis[p.second] = 1;
        for (long long i = 0; i < mat[p.second].size(); i++) {
            
            // cout << i << " " << p.second << " " << mat[p.second][i].second << endl;
            if ((p.second == blockedS) && (mat[p.second][i].second == blockedD) && (mat[p.second][i].first == blockedC)) {
                // cout << "YEAHH" << endl;
                continue;
            }
            if ((p.second == blockedD) && (mat[p.second][i].second == blockedS) && (mat[p.second][i].first == blockedC)) {
                // cout << "REVERSE" << endl;
                continue;
            }
                long long a = mat[p.second][i].second;
                long long b = mat[p.second][i].first;
                // cout << "GOT HERE" << endl;

                if (dist[a] > dist[p.second] + b) {
                    dist[a] = dist[p.second] + b;
                    q.push({dist[p.second] + b, a});
                    // cout << "PUSH " << a << endl;
                    parent[a] = p.second;
                    parentC[a] = b;
                }
            
        }
    }
    // cout << "END DIJK" << endl;
    return dist[N];
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &N, &R);
    for (int i = 0; i < R; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        mat[a].push_back({c, b});
        mat[b].push_back({c, a});
        // edges[i] = {{a, b}, c};
    }
    memset(parent, -1, sizeof(parent));
    memset(parentC, -1, sizeof(parentC));

    // cout << "INPUT DONE" << endl;
    
    dijk(1, {{N + 5, N + 5}, R + 1000});
    
    // cout << "DIJK INITIAL DONE" << endl;
    
    
    
    long long ans = INF;
    long long edgeEnd = N;
    while (true) {
        long long edgeStart = parent[edgeEnd];
        long long edgeCost = parentC[edgeEnd];

        if (edgeStart == -1 || edgeEnd == -1 || edgeCost == -1) {
            break;
        }
        //cout << edgeStart << " " << edgeEnd << " " << edgeCost << endl;
        long long cur = dijk(1, {{edgeStart, edgeEnd}, edgeCost});
        // cout << cur << endl << endl;
        ans = min(ans, cur);
        edgeEnd = edgeStart;
    }
    cout << ans << endl;
    return 0;
}
