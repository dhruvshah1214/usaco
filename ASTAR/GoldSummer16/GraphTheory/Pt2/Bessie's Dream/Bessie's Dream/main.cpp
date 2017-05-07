//
//  main.cpp
//  Bessie's Dream
//
//  Created by Dhruv Shah on 6/28/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>

#define INF 1 << 29

using namespace std;

int N, M;

int graph[1002][1002];
bool vis[1002][1002][5][2];

struct dream {
    int x, y, slided;
    bool smell;
    int depth;
    dream(int a, int b, int c, bool d, int e) {
        x = a, y = b, slided = c, smell = d, depth = e;
    }
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

//sliding dir: left, right, down, up



int shortestBFS(){
    int numRows = N;
    int numCol = M;
    queue<dream> bfsQ;
    bfsQ.push(dream(1, 1, 4, 0, 0));
    vis[1][1][4][0] = true;
    
    while (!bfsQ.empty()) {
        dream v = bfsQ.front();
        bfsQ.pop();
        // cout << v.x << " " << v.y << " " << v.slided << " " << v.smell <<  " " << v.depth << endl;
        if (v.slided < 4) {
            int nr = v.x + dx[v.slided]; 
            int nc = v.y + dy[v.slided];
            bool cont = false;
            int slideDir = 4;
            bool orange = false;
            if (nr < 1 || nr > numRows || nc < 1 || nc > numCol) cont = true;
            else {
                
                switch (graph[nr][nc]) {
                    case 0:
                        cont = true;
                        break;
                    case 2:
                        orange = true;
                        break;
                    case 3:
                        // blue
                        cont = true;
                        break;
                    case 4:
                        slideDir = v.slided;
                        break;
                    default:
                        break;
                }
 
            }
            if (cont) {
                for (int i = 0; i < 4; i++) {
                    int nrn = v.x + dx[i]; 
                    int ncn = v.y + dy[i];
                    if (nrn < 1 || nrn > numRows) continue; /* legal row */
                    if (ncn < 1 || ncn > numCol) continue; /* legal column */
                    if (nrn == N && ncn == M) {
                        // ending, first result is shortest, return the answer
                        return v.depth + 1;
                    }
                    
                    int slideDirn = 4;
                    bool orangen = false;
                    bool contn = false;
                    switch (graph[nrn][ncn]) {
                        case 0:
                            contn = true;
                            break;
                        case 1:
                            break;
                        case 2:
                            orangen = true;
                            break;
                        case 3:
                            // blue
                            contn = true;
                            
                            break;
                        case 4:
                            slideDirn = i;
                            break;
                        default:
                            break;
                    }
                    if (contn) {
                        continue;
                    }
                    if (!vis[nrn][ncn][slideDirn][orangen]) {
                        bfsQ.push(dream(nrn, ncn, slideDirn, orangen, v.depth + 1));
                        vis[nrn][ncn][slideDirn][orangen] = 1;
                    }  
                }
                continue;
            }
            if (nr == N && nc == M) {
                // ending, first result is shortest, return the answer
                return v.depth + 1;
            }
            if (!vis[nr][nc][slideDir][orange]) {
                bfsQ.push(dream(nr, nc, slideDir, orange, v.depth + 1));
                vis[nr][nc][slideDir][orange] = 1;
            }        
        }
        else {
            for (int i = 0; i < 4; i++) {
                int nr = v.x + dx[i]; 
                int nc = v.y + dy[i];
                if (nr < 1 || nr > numRows) continue; /* legal row */
                if (nc < 1 || nc > numCol) continue; /* legal column */
                if (nr == N && nc == M) {
                    // ending, first result is shortest, return the answer
                    return v.depth + 1;
                }
                
                int slideDir = 4;
                bool orange = v.smell;
                bool cont = false;
                switch (graph[nr][nc]) {
                    case 0:
                        cont = true;
                        break;
                    case 1:
                        break;
                    case 2:
                        orange = true;
                        break;
                    case 3:
                        // blue
                        if (!v.smell) {
                            cont = true;
                        }
                        break;
                    case 4:
                        slideDir = i;
                        break;
                    default:
                        break;
                }
                if (cont) {
                    continue;
                }
                if (!vis[nr][nc][slideDir][orange]) {
                    bfsQ.push(dream(nr, nc, slideDir, orange, v.depth + 1));
                    vis[nr][nc][slideDir][orange] = 1;
                }  
                
                
            }
            
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }
    int ans = shortestBFS();
    cout << ans << endl;
    return 0;
}

/*
3 3
 1 4 0
 3 1 4
 3 4 1
 
 8
*/