//
//  main.cpp
//  Munching
//
//  Created by Dhruv Shah on 6/13/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

int Rc, Cc, C, R;
char mat[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int vis[101][101] = {{0}};

struct point {
    int x, y, depth;
    point(int a, int b, int c){
        x = a;
        y = b;
        depth = c;
    }
    point() {
        
    }
};


long fielddepth[101][101];

int shortestBFS(int startX, int startY){
    int numRows = R;
    int numCol = C;
    char endingChar = 'B';
    char avoidChar = '*';

    queue<point> bfsQ; 
    bfsQ.push(point(startX, startY, 0));
    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < numCol; j++)
            fielddepth[i][j] = 101 * 101 + 9999;
    while (!bfsQ.empty()) {
        point v = bfsQ.front();
        bfsQ.pop();
        if (v.depth >= fielddepth[v.x][v.y])
            continue; 
        fielddepth[v.x][v.y] = v.depth;
        for (int i = 0; i < 4; i++) {
            int nr = v.x + dx[i]; 
            int nc = v.y + dy[i];
            if (nr < 0 || nr >= numRows) continue; 
            if (nc < 0 || nc >= numCol) continue; 
            if (mat[nr][nc] == avoidChar) continue;
            if (mat[nr][nc] == endingChar) {
                return v.depth + 1;
            }
            if (v.depth + 1 >= fielddepth[nr][nc])
                continue;
            bfsQ.push(point(nr, nc, v.depth + 1));
        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'C') {
                Rc = i, Cc = j;
            }
        }
    }
    
    cout << shortestBFS(Rc, Cc) << endl;
    
    return 0;
}
