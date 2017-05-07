//
//  main.cpp
//  VacationPlanning
//
//  Created by Dhruv Shah on 6/16/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1 << 29

long long N, M, K, Q, graph[205][205][2];

int main(int argc, const char * argv[]) {
    cin >> N >> M >> K >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j) {
                graph[i][j][0] = INF;
            }
            graph[i][j][1] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b][0] = c;
        if (a <= K || b <= K) {
            graph[a][b][1] = 1;
        }
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][k][0] < INF && graph[k][j][0] < INF) {
                    graph[i][j][0] = min(graph[i][j][0], graph[i][k][0] + graph[k][j][0]);
                    if (graph[i][k][1] == 1 || graph[k][j][1] == 1 || i <= K || j <= K || k <= K) {
                        graph[i][j][1] = 1;
                    }
                }
            }
        }
    }
    
    long long numPoss = 0;
    long long sumPoss = 0;
    long long sumPoss2 = 0;

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (graph[a][b][1] == 1 && graph[a][b][0] < INF) {
            numPoss++;
            sumPoss += graph[a][b][0];
        }
        long long cost = INF;
        for (int j=1; j <= K; j++) {
            cost = min(cost, (graph[a][j][0] + graph[j][b][0]));
        }
        if (cost != INF) {
            sumPoss2 += cost;
        }
    }
    cout << numPoss << endl << sumPoss2 << endl;
    
    return 0;
}
