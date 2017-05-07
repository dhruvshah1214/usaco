//
//  main.cpp
//  Moocast
//
//  Created by Dhruv Shah on 12/22/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int N;
pair<int , int> p[1005];
bool vis[1005];

#define INF 1 << 29

int sq(int a) {
    return a * a;
}

int eucl(pair<int , int> p1, pair<int, int> p2) {
    return sq(p1.first - p2.first) + sq(p1.second - p2.second);
}

int minKey(int key[], bool mstSet[])
{
    int min = INF, min_index = 0;
    
    for (int i = 0; i < N; i++)
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
    for (int i = 0; i < N; i++)
        mstSet[i] = false;
    
    for (int i = 1; i < N; i++) {
        key[i] = eucl(p[0], p[i]);
    }
    
    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    mstSet[0] = true;
    
    // The MST will have V Vertices
    for (int count = 0; count < N - 1; count++)
    {
        // Pick thd minimum key Nertex from the set of Nertices
        // not yet included in MST
        int u = minKey(key, mstSet);
        
        // Add the picked Nertex to the MST Set
        mstSet[u] = true;
        
        // Update key value of the adj vertices of the picked vertex. Consider only those vertices which are not yet included in MST
        
        sum = max(sum, key[u]);
        
        for (int v = 0; v < N; v++) {
            
            // mstSet[N] is false for Nertices not yet included in MST
            // Update the key
            if (mstSet[v] == false) {
                key[v] = min(key[v], eucl(p[u], p[v]));
            }
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream in("moocast.in");
    ofstream out("moocast.out");
    
    in >> N;
    for (int i = 0; i < N; i++) {
        in >> p[i].first >> p[i].second;
        vis[i] = false;
    }
    
    int ans = primMST();
    cout << ans << endl;
    out << ans << endl;
    
    

    return 0;
}
