//
//  main.cpp
//  SilverLilypadPond
//
//  Created by Dhruv Shah on 6/18/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>       
#include <functional>     

#define INF 1 << 29

using namespace std;

int N, M, mat[31][31], dist[31][31], sx, sy, ex, ey;
long long ways[31][31];

struct point {
    int x, y, depth;
    point(int a, int b, int c) {
        x = a, y = b, depth = c;
    }
    point() {
        
    }
};

struct ptcompare  
{  
    bool operator()(const point& l, const point& r)  
    {  
        return l.depth > r.depth;  
    }  
}; 

int dx[8] = {1, 1,-1,-1, 2, 2, -2, -2};
int dy[8] = {2,-2, 2,-2, 1, -1, 1, -1};

void dijk() {
    priority_queue<point, std::vector<point>, ptcompare > q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
    }
    dist[sx][sy] = 0;
    q.push(point(sx, sy, 0));
    while (!q.empty()) {
        point p = q.top();
        q.pop();
        for (int k = 0; k < 8; k++) {
            int cost = 0;
            bool cont = false;
            if (p.x + dx[k] < 0 || p.x + dx[k] >= M) continue;
            if (p.y + dy[k] < 0 || p.y + dy[k] >= N) continue;
            switch (mat[p.x + dx[k]][p.y + dy[k]]) {
                case 0:
                    cost = 1001;
                    break;
                case 1:
                    cost = 1;
                    break;
                case 2:
                    cont = true;
                    break;
                case 4:
                    cost = 1;
                    break;
                default:
                    break;
            }
            if (cont) {
                continue;
            }
            if (dist[p.x + dx[k]][p.y + dy[k]] > dist[p.x][p.y] + cost) {
                dist[p.x + dx[k]][p.y + dy[k]] = dist[p.x][p.y] + cost;
                q.push(point(p.x + dx[k], p.y + dy[k], dist[p.x + dx[k]][p.y + dy[k]]));
                ways[p.x + dx[k]][p.y + dy[k]] = ways[p.x][p.y];
            }
            else if (dist[p.x + dx[k]][p.y + dy[k]] == dist[p.x][p.y] + cost) {
                ways[p.x + dx[k]][p.y + dy[k]] += ways[p.x][p.y];
            }
        }
    }
    if (dist[ex][ey] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << (int)(dist[ex][ey] / 1000) << endl << (dist[ex][ey] % 1000) << endl << ways[ex][ey] << endl;
    }
}

int main(int argc, const char * argv[]) {
    cin >> M >> N;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 3) {
                sx = i, sy = j;
                ways[sx][sy] = 1;
            }
            if (mat[i][j] == 4) {
                ex = i, ey = j;
            }
        }
    }
    
    dijk();
    
    
    return 0;
}
