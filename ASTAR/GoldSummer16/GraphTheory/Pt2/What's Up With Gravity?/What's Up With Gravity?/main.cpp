//
//  main.cpp
//  What's Up With Gravity?
//
//  Created by Dhruv Shah on 6/27/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include <functional>

#define INF 1 << 29

using namespace std;

typedef pair<int, pair<int, int> > pii;

int N, M;
char farm[505][505];
int dist[505][505];
bool vis[505][505];

bool bound(int x, int y) {
    return (1 <= x) && (x <= N) && (1 <= y) && (y <= M);
}

pair<int, int> realPoint(int x, int y, bool gravityDown, int steps) {
    if (farm[x][y] != '.') {
        return make_pair(x, y);
    }
    if (gravityDown) {
        int i = x;
        for (; i < N; i++) {
            
            if (farm[i + 1][y] != '.') {
                break;
            }
            if (i != x) {
                dist[i][y] = min(dist[i][y], steps);
            }
        }
        if (i == N) {
            return make_pair(N + 5, y);
        }
        return make_pair(i, y);
    }
    else {
        int i = x;
        for (; i > 1; i--) {
            
            if (farm[i - 1][y] != '.') {
                break;
            }
            if (i != x) {
                dist[i][y] = min(dist[i][y], steps);
            }
        }
        if (i == 1) {
            return make_pair(-5, y);
        }
        return make_pair(i, y);
    }
}

class ccomp
{
public:
    bool operator() (pii p1, pii p2)
    {
        return p1.first > p2.first;
    }
};

int dijk(int sx, int sy, int ex, int ey) {
    priority_queue<pii, vector<pii>, ccomp > q;
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dist[i][j] = INF;
            vis[i][j] = false;
        }
    }
    
    pair<int, int> sp = realPoint(sx, sy, true, 0);
    sx = sp.first;
    sy = sp.second;

    
    dist[sx][sy] = 0;
    q.push({0, {sx, sy}});
    
    while (!q.empty()) {
        pii p = q.top();
        q.pop();
        
        bool isGravDown = (p.first % 2 == 0);

        
        if (vis[p.second.first][p.second.second]) {
            continue;
        }
        vis[p.second.first][p.second.second] = 1;
        
        // cout << "L " << p.first << " " << p.second.first << " " << p.second.second << endl;
        if (isGravDown) {
            // right
            pair<int, int> np = realPoint(p.second.first, p.second.second + 1, true, p.first);
            int nx = np.first, ny = np.second;
            if (bound(nx, ny) && bound(nx + 1, ny)) {
                if (farm[nx][ny] == '.' && (nx + 1 < N || farm[nx + 1][ny] == '#')) {
                    if (dist[nx][ny] > p.first + 0) {
                        dist[nx][ny] = p.first;
                        // cout << "PUSHING " << nx << " " << ny << endl;
                        q.push({p.first, {nx, ny}});
                    }
                }
            }
            
            // left
            np = realPoint(p.second.first, p.second.second - 1, true, p.first);
            nx = np.first, ny = np.second;
            if (bound(nx, ny) && bound(nx + 1, ny)) {
                if (farm[nx][ny] == '.' && (nx + 1 < N || farm[nx + 1][ny] == '#')) {
                    if (dist[nx][ny] > p.first + 0) {
                        dist[nx][ny] = p.first;
                        //cout << "PUSHING " << nx << " " << ny << endl;
                        q.push({p.first, {nx, ny}});
                    }
                }
            }
            
            // switch gravity

            np = realPoint(p.second.first, p.second.second, false, p.first + 1);
            nx = np.first, ny = np.second;
            if (bound(nx, ny)) {
                if (farm[nx][ny] == '.') {
                    if (dist[nx][ny] > p.first + 1) {
                        dist[nx][ny] = p.first + 1;
                        //cout << "PUSHING " << nx << " " << ny << endl;
                        q.push({p.first + 1, {nx, ny}});
                    }
                }
            }
        }
        else {
            // right
            pair<int, int> np = realPoint(p.second.first, p.second.second + 1, false, p.first + 1);
            int nx = np.first, ny = np.second;
            if (bound(nx, ny) && bound(nx - 1, ny)) {
                if (farm[nx][ny] == '.' && (nx - 1 > 1 || farm[nx - 1][ny] == '#')) {
                    if (dist[nx][ny] > p.first + 0) {
                        dist[nx][ny] = p.first;
                        //cout << "PUSHING " << nx << " " << ny << endl;
                        q.push({p.first, {nx, ny}});
                    }
                }
            }
            
            // left
            np = realPoint(p.second.first, p.second.second - 1, false, p.first);
            nx = np.first, ny = np.second;
            if (bound(nx, ny) && bound(nx - 1, ny)) {
                if (farm[nx][ny] == '.' && (nx - 1 > 1 || farm[nx - 1][ny] == '#')) {
                    if (dist[nx][ny] > p.first + 0) {
                        dist[nx][ny] = p.first;
                        //cout << "PUSHING " << nx << " " << ny << endl;
                        q.push({p.first, {nx, ny}});
                    }
                }
            }
            
            // switch gravity
            int i = p.second.first;
            np = realPoint(i, p.second.second, true, p.first);
            nx = np.first, ny = np.second;
            if (bound(nx, ny)) {
                if (farm[nx][ny] == '.') {
                    if (dist[nx][ny] > p.first + 1) {
                        dist[nx][ny] = p.first + 1;
                        // << "PUSHING " << nx << " " << ny << endl;
                        q.push({p.first + 1, {nx, ny}});
                    }
                }
            }
        }
    }
    return dist[ex][ey];
}

int main(int argc, const char * argv[]) {
    /*
    bool single = true;
    int i = 8;
    int endi = 10;
    if (single) {
        endi = i;
    }
    for (; i <= endi; i++) {
        string con = (to_string(i) + ".in");
        string conO = (to_string(i) + ".out");
        
        ifstream in(con);
        ifstream op(conO);
        
        std::clock_t start;
        double duration;
        
        start = std::clock();
        
        in >> N >> M;
        char c;
        in.get(c);
        int sx, sy, ex, ey;
        for (int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                in.get(c);
                farm[i][j] = c;
                if (c == 'C') {
                    sx = i, sy = j;
                    farm[i][j] = '.';
                }
                if (c == 'D') {
                    ex = i, ey = j;
                    farm[i][j] = '.';
                }
            }
            in.get(c);
        }
        
        
        for (int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                cout << farm[i][j];
            }
            cout << endl;
        }
        
        
        
        int outp;
        op >> outp;
        
        int ans = dijk(sx, sy, ex, ey);
        if (ans == INF) {
            ans = -1;
        }
        cout << outp << " " << ans << " ";
        if (outp == ans) {
            cout << "CORRECT    -      TIME: ";
        }
        else {
            cout << "WRONG      -      TIME: ";
        }
        cout << setprecision(10) << fixed;
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        cout << duration << endl;
    }
    */
    
    cin >> N >> M;
    char c;
    cin.get(c);
    int sx, sy, ex, ey;
    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin.get(c);
            farm[i][j] = c;
            if (c == 'C') {
                sx = i, sy = j;
                farm[i][j] = '.';
            }
            if (c == 'D') {
                ex = i, ey = j;
                farm[i][j] = '.';
            }
        }
        cin.get(c);
    }

    int ans = dijk(sx, sy, ex, ey);
    if (ans == INF) {
        ans = -1;
    }
    
    return 0;
}
