//
//  main.cpp
//  Power Failure
//
//  Created by Dhruv Shah on 6/17/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define INF 1 << 29
#define MAXINT INF

struct point {
    int x, y;
    point(int a, int b) {
        x = a, y = b;
    }
    point() {
        
    }
} p[1005];

int N, W;
long double M, graph[1005][1005] = {{}};

long long sq(long long a) {
    return (long long)(a * a);
}

long double euclid(point p1, point p2) {
    return sqrt(sq(p1.y - p2.y) + sq(p1.x - p2.x));
}

int minKey(long double key[], bool vis[])
{
    long double min = INF;
    int min_index = -1;
    
    for (int i = 1; i <= N; i++)
        if (vis[i] == false && key[i] < min)
            min = key[i], min_index = i;
    
    return min_index;
}

int dijkstra() {
    
    int source = 1;
    int numNodes = N;
    
    long double dist[2505];
    bool visited[2505];
    
    for (int i = 1; i <= numNodes; i++) {
        dist[i] = MAXINT;
        visited[i] = false;
    }
    
    // Distance of source vertex from itself is always 0
    dist[source] = 0;
    
    for (int i = 2; i <= N; i++) {
        dist[i] = graph[1][i];
    }
    
    // Find shortest path for all vertices
    for (int count = 1; count <= numNodes - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minKey(dist, visited);
        // cout << "U " << u << endl;
        if (u == -1) {
            break;
        }
        
        // Mark the picked vertex as processed
        visited[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 1; v <= numNodes; v++)
            
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v]
            if (!visited[v] && dist[u] < MAXINT && dist[u] + graph[u][v] < dist[v] && graph[u][v] < INF) {
                dist[v] = dist[u] + graph[u][v];
                // cout << dist[v] << endl;
            }
    }
    
    if (dist[N] == INF) {
        return -1;
    }
    else {
        return (int)(1000 * dist[N]);
    }
}

int main(int argc, const char * argv[]) {
    cin >> N >> W >> M;
    
    for (int i = 1; i <= N; i++) {
        cin >> p[i].x >> p[i].y;
        for (int j = 1; j <= N; j++) {
            graph[i][j] = INF;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            double d = euclid(p[i], p[j]);
            if (d <= M && i != j) {
                graph[i][j] = graph[j][i] = d;
            }
        }
    }
    for (int i = 1; i <= W; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 0.0;
        graph[b][a] = 0.0;
    }
    
    /*
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (graph[i][j] < INF) {
                cout << i << " " << j << " " << graph[i][j] << endl;
            }
        }
    }
    */
    
    cout << dijkstra() << endl;
    
    return 0;
}
