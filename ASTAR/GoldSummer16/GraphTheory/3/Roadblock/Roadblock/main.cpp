//
//  main.cpp
//  Roadblock
//
//  Created by Dhruv Shah on 6/17/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iostream>

#define INF 1 << 29
#define MAXINT INF

using namespace std;

int N, M, graph[101][101];

int minKey(int key[], bool vis[])
{
    int min = INF, min_index = 0;
    
    for (int i = 1; i <= N; i++)
        if (vis[i] == false && key[i] < min)
            min = key[i], min_index = i;
    
    return min_index;
}

int solve() {
    int parent[101] = {0};
    int maxIncrease = 0;
    
    int source = 1;
    int numNodes = N;
    
    int dist[101];
    bool visited[101];
    
    for (int i = 1; i <= numNodes; i++) {
        dist[i] = MAXINT;
        visited[i] = false;
        parent[i] = -1;
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
            if (!visited[v] && graph[u][v] < INF && dist[u] < MAXINT && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }
    
    int curshortestRoute = dist[N];
    int curCheck = N;
    while (true) {
        int prev = parent[curCheck];
        if (prev == -1) {
            break;
        }
        graph[curCheck][prev] = graph[prev][curCheck] = graph[prev][curCheck] * 2;
        
        //run dijk, check max increase
        //reset everything, source and numnodes stay same
        for (int i = 1; i <= numNodes; i++) {
            dist[i] = MAXINT;
            visited[i] = false;
        }
        dist[source] = 0;
        for (int count = 1; count <= numNodes - 1; count++)
        {
            int u = minKey(dist, visited);
            visited[u] = true;
            for (int v = 1; v <= numNodes; v++) {
                if (!visited[v] && graph[u][v] < INF && dist[u] < MAXINT && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        int newShortestDist = dist[N];
        maxIncrease = max(maxIncrease, (newShortestDist - curshortestRoute));
        
        graph[curCheck][prev] = graph[prev][curCheck] = graph[prev][curCheck] / 2;
        curCheck = prev;
    }
    return maxIncrease;
}


int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            graph[i][j] = INF;
        }
    }
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
    }
    
    cout << solve() << endl;
    
    return 0;
}
