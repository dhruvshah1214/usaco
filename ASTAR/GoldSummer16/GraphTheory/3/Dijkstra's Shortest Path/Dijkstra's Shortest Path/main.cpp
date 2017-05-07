//
//  main.cpp
//  Dijkstra's Shortest Path
//
//  Created by Dhruv Shah on 6/17/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define MAXINT 1 << 29
#define INF MAXINT

using namespace std;

int V, E, S;
int mat[2505][2505];

int minKey(int key[], bool vis[])
{
    int min = INF, min_index = 0;
    
    for (int i = 1; i <= V; i++)
        if (vis[i] == false && key[i] < min)
            min = key[i], min_index = i;
    
    return min_index;
}

void dijkstra() {
    
    int source = S;
    int numNodes = V;
    
    int dist[2505];
    bool visited[2505];
    
    for (int i = 1; i <= numNodes; i++) {
        dist[i] = MAXINT;
        visited[i] = false;
    }
    
    // Distance of source vertex from itself is always 0
    dist[source] = 0;
    
    // Find shortest path for all vertices
    for (int count = 1; count <= numNodes - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minKey(dist, visited);
        
        // Mark the picked vertex as processed
        visited[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 1; v <= numNodes; v++)
            
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v]
            if (!visited[v] && mat[u][v] && dist[u] < MAXINT && dist[u] + mat[u][v] < dist[v]) {
                dist[v] = dist[u] + mat[u][v];
            }
    }    
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << -1 << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> V >> E >> S;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            mat[i][j] = INF;
        }
    }
    

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = mat[b][a] = min(mat[a][b], c);
    }
    
    dijkstra();
    
    return 0;
}
