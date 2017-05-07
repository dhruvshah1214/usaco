/*
 SOLUTION: Each state is location and direction of each traverser. Any state with locations at (0, N-1) is a solution. Modified BFS will give shortest path.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <string>

using namespace std;


int N;
char mat[25][25]; // graph
int distarr[25][25][4][25][25][4]; // store shortest distance at every possible state
const int dir[4][2] = {{-1, 0},  {0, 1}, {1, 0}, {0, -1}}; //up, right, down, left

// struct to define a certain point
struct point {
    int x, y, dir;
    point(int a, int b, int c) {
        x = a, y = b, dir = c;
    }
    point() {
        
    }
};

// defines full BFS state
struct state {
    point p1, p2;
    int depth;
    state(point t1, point t2, int d) {
        p1 = t1, p2 = t2, depth = d;
    }
    state() {
        
    }
};

// modified modulus (%) operator to allow negatives
int mod(int i, int m) {
    if (i >= 0) {
        return (i % m);
    }
    return (i + m);
}

int shortestBFS(){
    queue<state> bfsQ;
    // start with both traversers at (N - 1, 0), with one facing up, and one facing down
    bfsQ.push(state(point(N - 1, 0, 0), point(N - 1, 0, 1), 0));

    while (!bfsQ.empty()) {
        state v = bfsQ.front();
        if (v.p1.x == 0 && v.p2.x == 0 && v.p1.y == N - 1 && v.p2.y == N - 1) {
            // current location is top right a.k.a. barn
            return v.depth;
        }
        bfsQ.pop();
        if (v.depth >= distarr[v.p1.x][v.p1.y][v.p1.dir][v.p2.x][v.p2.y][v.p2.dir])
            continue; /* current state is some other visitation improved on our distance */
        distarr[v.p1.x][v.p1.y][v.p1.dir][v.p2.x][v.p2.y][v.p2.dir] = v.depth;
        
        // fwd move
        int nx1 = v.p1.x, ny1 = v.p1.y, nd1 = v.p1.dir;
        int nx2 = v.p2.x, ny2 = v.p2.y, nd2 = v.p2.dir;
        
        // check bounds and barrier
        if (0 <= v.p1.x + dir[v.p1.dir][0] && v.p1.x + dir[v.p1.dir][0] < N && 0 <= v.p1.y + dir[v.p1.dir][1] && v.p1.y + dir[v.p1.dir][1] < N && mat[v.p1.x + dir[v.p1.dir][0]][v.p1.y + dir[v.p1.dir][1]] != 'H') {
            nx1 = v.p1.x + dir[v.p1.dir][0];
            ny1 = v.p1.y + dir[v.p1.dir][1];
        }
        if (0 <= v.p2.x + dir[v.p2.dir][0] && v.p2.x + dir[v.p2.dir][0] < N && 0 <= v.p2.y + dir[v.p2.dir][1] && v.p2.y + dir[v.p2.dir][1] < N && mat[v.p2.x + dir[v.p2.dir][0]][v.p2.y + dir[v.p2.dir][1]] != 'H') {
            nx2 = v.p2.x + dir[v.p2.dir][0], ny2 = v.p2.y + dir[v.p2.dir][1];
        }
        
        // if either "traverser" is at final destination, stop moving that traverser
        if (v.p1.x == 0 && v.p1.y == N - 1) {
            nx1 = 0, ny1 = N - 1;
        }
        if (v.p2.x == 0 && v.p2.y == N - 1) {
            nx2 = 0, ny2 = N - 1;
        }
        
        // solution; can only reach on moving to a new square; can only move to a new square thru forward move
        if (nx1 == 0 && nx2 == 0 && ny1 == N - 1 && ny2 == N - 1) {
            return v.depth + 1;
        }
        
        if (v.depth + 1 < distarr[nx1][ny1][nd1][nx2][ny2][nd2]) {
            /* don't enqueue if not optimal so far */
            bfsQ.push(state(point(nx1, ny1, nd1), point(nx2, ny2, nd2), v.depth + 1));
        }
        
        // reset n[x|y][1|2] variables to cur location for pivot turn states
        nx1 = v.p1.x, ny1 = v.p1.y, nd1 = v.p1.dir;
        nx2 = v.p2.x, ny2 = v.p2.y, nd2 = v.p2.dir;
        
        // right (pivot) turn
        nd1 = mod((v.p1.dir + 1), 4);
        nd2 = mod((v.p2.dir + 1), 4);
        if (v.depth + 1 < distarr[nx1][ny1][nd1][nx2][ny2][nd2]) {
            /* don't enqueue if not optimal so far */
            bfsQ.push(state(point(nx1, ny1, nd1), point(nx2, ny2, nd2), v.depth + 1));
        }

        // left (pivot) turn
        nd1 = mod((v.p1.dir - 1), 4);
        nd2 = mod((v.p2.dir - 1), 4);
        if (v.depth + 1 < distarr[nx1][ny1][nd1][nx2][ny2][nd2]) {
            /* don't enqueue if not optimal so far */
            bfsQ.push(state(point(nx1, ny1, nd1), point(nx2, ny2, nd2), v.depth + 1));
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    ifstream in("cownav.in");
    ofstream out("cownav.out");
        
    bool debug  = 0; //set to one to submit
    
    
    if(debug) {
        //std input
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> mat[i][j];
            }
        }
    } else {
        //file input
        in >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                in >> mat[i][j];
            }
        }
    }
    
    //set array to inf
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    for (int m = 0; m < 4; m++) {
                        for (int n = 0; n < 4; n++) {
                            distarr[i][j][m][k][l][n] = (1 << 29); // infinity
                        }
                    }
                }
            }
        }
    }
    

    
    int ans = shortestBFS();
    
    cout << ans << endl;
    out << ans << endl;
    
    return 0;
}
