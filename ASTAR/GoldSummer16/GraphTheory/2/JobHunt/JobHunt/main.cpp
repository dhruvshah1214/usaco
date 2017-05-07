//
//  main.cpp
//  JobHunt
//
//  Created by Dhruv Shah on 6/16/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define INF 1 << 29

struct edge {
    int c, n1, n2;
    bool operator< (edge e1) {
        return c < e1.c;
    }
    edge(int a, int b, int d) {
        c = a, n1 = b, n2 = d;
    }
    edge() {
        
    }
};

int D, P, C, F, S;
int graph[221][221];
edge vecc[501];

int bellford() {
    int distance[221], pre[221];
    for (int i = 0; i < C; i++) {
        distance[i] = INF;
        pre[i] = 0;
    }
    distance[S] = 0;
    for (int i = 1; i <= C - 1; i++) {
        for (int j = 0; j < P + F; j++) {
            int u = vecc[j].n1;
            int v = vecc[j].n2;
            int w = vecc[j].c;
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pre[v] = u;
            }
        }
    }
    for (int i = 0; i < P + F; i++) {
        int u = vecc[i].n1, v = vecc[i].n2, w = vecc[i].c;
        if (distance[u] + w < distance[v]) {
            return -1;
        }
    }
    /*
    for (int i = 0; i < C; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < C; i++) {
        cout << pre[i] << " ";
    }
    cout << endl;
    */
    return (int)(D - *(min_element(distance, distance + C)));
}



int main(int argc, const char * argv[]) {
    cin >> D >> P >> C >> F >> S;
    S--;
    /*
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            graph[i][j] = INF;
        }
    }
    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = -1 * D;
    }
    for (int i = 0; i < F; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
    }
     */
    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        vecc[i] = (edge(-1 * D, a - 1, b - 1));
    }
    for (int i = 0; i < F; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vecc[P + i] = (edge(c - D, a - 1, b - 1));

    }
    /*
    for (int i = 0; i < P + F; i++) {
        cout << vecc[i].n1 << " " << vecc[i].n2 << " " << vecc[i].c << endl;
        
    }
    cout << endl;
     */
    
    cout << bellford() << endl;
    
    return 0;
}
