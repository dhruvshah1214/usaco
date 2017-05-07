//
//  main.cpp
//  SnailTrails
//
//  Created by Dhruv Shah on 6/15/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, B, mat[125][125];
int maxSteps = 0;
int endPosX, endPosY;

// dir 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0,-1};

bool bounds(int x, int y) {
    return ((0 <= x) && (x < N) && (0 <= y) && (y < N));
}

bool onBound(int x, int y, int dir) {
    return ((0 == x && dir == 0) || (x == N - 1 && dir == 2) || (0 == y && dir == 3) || (y == N - 1 && dir == 1));
}
bool vis[125][125];

void dfs(int x, int y, int curdir, int steps) {
    if (!bounds(x, y) || vis[x][y] || mat[x][y] == 1) {
        if (vis[x][y] || mat[x][y]) {
            maxSteps = max(maxSteps, steps - 1);
        }
        return;
    }
    vis[x][y] = true;
    /*
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
    cout << x << " " << y << " " << steps << endl;
    // */
    
    if (bounds(x + dx[curdir], y + dy[curdir])) {
        if (vis[x + dx[curdir]][y + dy[curdir]]) {
            maxSteps = max(maxSteps, steps);
            vis[x][y] = false;
            return;
        }
        if (!vis[x + dx[curdir]][y + dy[curdir]] && mat[x + dx[curdir]][y + dy[curdir]] == 0) {
            dfs(x + dx[curdir], y + dy[curdir], curdir, steps + 1);
        }
        if (mat[x + dx[curdir]][y + dy[curdir]] == 1) {
            int newDir1 = (curdir - 1);
            int newDir2 = (curdir + 1);
            if (curdir == 0) {
                newDir1 = 3;
            }
            if (curdir == 3) {
                newDir2 = 0;
            }
            dfs(x + dx[newDir1], y + dy[newDir1], newDir1, steps + 1);
            dfs(x + dx[newDir2], y + dy[newDir2], newDir2, steps + 1);
        }
    }
    if (onBound(x, y, curdir)) {
        int newDir1 = (curdir - 1);
        int newDir2 = (curdir + 1);
        if (curdir == 0) {
            newDir1 = 3;
        }
        if (curdir == 3) {
            newDir2 = 0;
        }
        
        dfs(x + dx[newDir1], y + dy[newDir1], newDir1, steps + 1);
        dfs(x + dx[newDir2], y + dy[newDir2], newDir2, steps + 1);
    }
    vis[x][y] = false;
}

int main(int argc, const char * argv[]) {
    cin >> N >> B;
    for (int i = 0; i < B; i++) {
        char c;
        cin >> c;
        int a;
        cin >> a;
        
        mat[a - 1][c - 'A'] = 1;
    }
    
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // */
    
    memset(vis, 0, sizeof(vis));
    dfs(0, 0, 1, 1);
    memset(vis, 0, sizeof(vis));
    dfs(0, 0, 2, 1);
    
    cout << maxSteps << endl;
    
    return 0;
}
