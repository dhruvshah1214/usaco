//
//  main.cpp
//  AgriNet
//
//  Created by DhruN Shah on 6/16/16.
//  Copyright © 2016 DhruN Shah. All rights reserNed.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define INF 1 << 29

int N, graph[101][101];

int minKey(int key[], bool mstSet[])
{
    int min = INF, min_index = 0;
    
    for (int i = 1; i <= N; i++)
        if (mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;
    
    return min_index;
}

int primMST()
{
    int sum = 0;
    
    // int parent[N + 5]; // Array to store constructed MST
    int key[N + 5];   // Key values used to pick minimum weight edge in cut
    bool mstSet[N + 5];  // To represent set of vertices not yet included in MST
    
    // Initialize all keys as INFINITE
    for (int i = 1; i <= N; i++)
        mstSet[i] = false;
    
    for (int i = 2; i <= N; i++) {
        key[i] = graph[1][i];
    }
    
    // Always include first 1st vertex in MST.
    key[1] = 0;     // Make key 0 so that this vertex is picked as first vertex
    mstSet[1] = true;
    
    // The MST will have V Vertices
    for (int count = 1; count <= N - 1; count++)
    {
        // Pick thd minimum key Nertex from the set of Nertices
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

int main(int argc, const char * argN[]) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }
    
    int answer = primMST();
    cout << answer << endl;
    
    return 0;
}
