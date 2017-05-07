//
//  main.cpp
//  MST 2
//
//  Created by Dhruv Shah on 6/27/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

//Keywords: priority queue, mst, mst 2, 2, II, priority queue MST

#include <iostream>
#include <queue>
#include <vector>

#define INF 1 << 29

using namespace std;

typedef pair<int, int> pii;
vector<pii> mat[50005]; 

int V, E;
int weight[50005];
bool vis[50005];

class pcomp {
public:
    bool operator() (pii p1, pii p2) {
        return p1.second > p2.second;
    }
};

int primMST() {
    int sum = 0;
    priority_queue<pii, vector<pii>,
        pcomp > pq;
    
    for (int i = 0; i <= V; i++) {
        weight[i] = INF;
    }
    
    int src = 1;
    
    weight[src] = 0;
    pq.push(make_pair(src, 0));
    
    while (!pq.empty()) {
        int cur = pq.top().first;
        pq.pop();
        if (!vis[cur]) {
            vis[cur] = 1;
            for (int i = 0; i < (int)mat[cur].size(); i++) {
                int next = mat[cur][i].first;
                int nextW = mat[cur][i].second;
                if (!vis[next] && weight[next] > nextW) {
                    weight[next] = nextW;
                    pq.push(mat[cur][i]);
                }
            }
        }
        
    }
    for (int i = 1; i <= V; i++) {
        sum += weight[i];
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a].push_back(make_pair(b, c));
        mat[b].push_back(make_pair(a, c));
    }
    
    cout << primMST() << endl;
    
    return 0;
}
