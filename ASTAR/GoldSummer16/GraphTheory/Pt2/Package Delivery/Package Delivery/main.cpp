//
//  main.cpp
//  Package Delivery
//
//  Created by Dhruv Shah on 6/27/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>


#define INF 1 << 29

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pii> mat[50005];

int dist[50005];
bool vis[50005];

int S = 1;

int dijk() {
    priority_queue<pii, vector<pii>, greater<pii> > q;
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dist[i] = INF;
            vis[i] = false;
        }
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
        for (int i = 0; i < mat[p.second].size(); i++) {
            int a = mat[p.second][i].second;
            int b = mat[p.second][i].first;
            
            if (dist[a] > dist[p.second] + b) {
                dist[a] = dist[p.second] + b;
                q.push({dist[p.second] + b, a});
            }
        }
    }
    return dist[N];
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a].push_back({c, b});
        mat[b].push_back({c, a});
    }
    cout << dijk() << endl;
     
    
    return 0;
}
