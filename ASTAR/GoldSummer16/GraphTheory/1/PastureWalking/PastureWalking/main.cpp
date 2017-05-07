//
//  main.cpp
//  PastureWalking
//
//  Created by Dhruv Shah on 6/15/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <stack>

#define INF 1 << 29

using namespace std;

int N, Q, G[1001][1001];

int main(int argc, const char * argv[]) {
    cin >> N >> Q;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            G[i][j] = INF;
        }
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = c;
        G[b][a] = c;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (G[j][i] < INF) {
                for (int k = 1; k <= N; k++) {
                    if (G[i][k] < INF) {
                        if (G[j][k] > G[j][i] + G[i][k]) {
                            G[j][k] = G[j][i] + G[i][k];
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        cout << G[a][b] << endl;
    }
    
    return 0;
}

/*
 
 int dfs(int node, int end, int len) {
 stack<int> s;
 s.push(node);
 while (!s.empty()) {
 int t = s.top();
 if (t == end) {
 return /
 }
 s.pop();
 for (int i = 1; i <= N; i++) {
 if (G[t][i] < INF) {
 s.push(i);
 }
 }
 }
 }
 */
