//
//  main.cpp
//  PrimsACtuaLCode
//
//  Created by Dhruv Shah on 10/25/15.
//  Copyright © 2015 USACO. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int V, E, graph[2503][2503], d[2503], cost = 0;
bool vis[2503];

int main(int argc, const char * argv[]) {
    cin >> V >> E;
    for (int i = 0; i < V; i++) {
        vis[i] = false;
        d[i] = INT_MAX;
    }
    d[0] = 0;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    for (int i = 0; i < V; i++) {
        int node = 0, dis = INT_MAX;
        for (int i = 0; i < V; i++) {
            if (d[i] < dis && !vis[i]) {
                node = i;
                dis = d[i];
            }
            if (dis < INT_MAX) {
                cost += dis;
            }
            vis[node] = true;
            for (int i = 0; i < V; i++) {
                d[i] = min(d[i], graph[node][i]);
            }
        }
    }
    for (int i = 0; i < V; i++) {
        cout << d[i] << " ";
    }
    return 0;
}

/*
 
 vis[i] = false for all i   <---- true if i is in current tree
 graph[i][j] = min weight from i to j if connected, else MAXINT
 dis[i] = MAX_INT for all i
 d[0] = 0
 cost = 0
 for 1...n {
 
 }
 
 
*/
 
