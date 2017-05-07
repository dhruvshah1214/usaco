#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAXINT 1 << 29

using namespace std;

int T;
int N[12];
int M[12];
int S[12];
int mat[12][3002][3002];
int dist[12][3002];
bool visited[12][3002];

void solve(int z) {
    int source = S[z];
    int numNodes = N[z];
    int numEdges = M[z];
    
    int DST = MAXINT;
    
    for (int i = 1; i <= numNodes; i++) {
        dist[z][i] = MAXINT;
        visited[z][i] = false;
    }
    
    dist[z][source] = 0;
    visited[z][source] = true;
    
    for (int i = 1; i <= numNodes; i++) {
        visited[z][i] = true;
        DST = dist[z][i];
        for (int j = 1; j <= numNodes; j++) {
            if (!visited[z][j] && mat[z][i][j] < MAXINT) {
                dist[z][j] = min(dist[z][j], DST + mat[z][i][j]);
            }
        }
    }
    
}




int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= N[i]; j++) {
            for (int k = 1; k <= N[i]; k++) {
                mat[i][j][k] = MAXINT;
            }
        }
    }
    for(int i = 1; i <= T; i++) {
        cin >> N[i] >> M[i];
        for(int j = 1; j <= M[i]; j++) {
            int x, y, r;
            cin >> x >> y >> r;
            mat[i][x][y] = r;
            mat[i][y][x] = r;
        }
        cin >> S[i];
    }
    
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= N[i]; j++) {
            if (j != S[i]) {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
