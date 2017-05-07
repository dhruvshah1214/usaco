//
//  main.cpp
//  BuildingRoads
//
//  Created by Dhruv Shah on 6/16/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <cmath>

using namespace std;

#define INF 1 << 29


int N, M, roads[1005][2];
long double graph[1005][1005];


struct point {
    long double x, y;
} nr[1001];



long double sq(long double a) {
    return a * a;
}
long double euclid(point p1, point p2) {
    return sqrt(sq(p2.y - p1.y) + sq(p2.x - p1.x));
}



int minKey(long double key[], bool mstSet[])
{
    long double min = INF;
    int min_index = 0;
    
    for (int i = 1; i <= N; i++)
        if (mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;
    
    return min_index;
}

long double primMST()
{
    long double sum = 0;
    
    // int parent[N + 5]; // Array to store constructed MST
    long double key[N + 5];   // Key values used to pick minimum weight edge in cut
    bool mstSet[N + 5];  // To represent set of vertices not yet included in MST
    
    // Initialize all keys as INFINITE
    for (int i = 1; i <= N; i++) {
        mstSet[i] = false;
    }
    
    for (int i = 2; i <= N; i++) {
        key[i] = graph[1][i];
    }
    
    // Always include first 1st vertex in MST.
    key[1] = 0;     // Make key 0 so that this vertex is picked as first vertex
    mstSet[1] = true;
    
    // The MST will have V Vertices
    for (int count = 1; count <= N - 1; count++)
    {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
        
        // Add the picked Nertex to the MST Set
        mstSet[u] = true;
        
        // Update key value of the adj vertices of the picked vertex. Consider only those vertices which are not yet included in MST
        
        sum += key[u];
        
        for (int v = 1; v <= N; v++) {
            
            // mstSet[N] is false for Nertices not yet included in MST
            // Update the key
            if (mstSet[v] == false) {
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> nr[i].x >> nr[i].y;
    }
    for (int i = 0; i < M; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            graph[i][j] = graph[j][i] = euclid(nr[i], nr[j]);
        }
    }
    for (int i = 0; i < M; i++) {
        graph[roads[i][0]][roads[i][1]] = graph[roads[i][1]][roads[i][0]] = 0.0;
    }
    
    long double ans = primMST();
    cout << setprecision(2) << fixed;
    cout << ans << endl;
    
    return 0;
}
