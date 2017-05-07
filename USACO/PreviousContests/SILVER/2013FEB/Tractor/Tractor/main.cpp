#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <climits>

#define MAXINT 1 << 29


using namespace std;

typedef pair<int, int> point;


int N;
int farm[501][501];
bool visited[501][501];
int minHeight = MAXINT, maxHeight = 0;
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int x, int y, int d) {
    if (visited[x][y] == 1) {
        return 0;
    }
    visited[x][y] = 1;
    int count = 1;
    for (int i = 0; i < 4; i++) {
        int newX = x + dir[i][0], newY = y + dir[i][1];
        if (0 <= newX && newX < N && 0 <= newY && newY < N && abs(farm[x][y] - farm[newX][newY]) <= d) {
            count += dfs(newX, newY, d);
        }
    }
    return count;
}


bool possible(int D) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                if (dfs(i, j, D) * 2 >= N * N) {
                    return true;
                }
            }
        }
    }
    return false;
}


int main(int argc, const char * argv[]) {
    ifstream in("tractor.in");
    ofstream out("tractor.out");
    
    in >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            in >> farm[i][j];
            minHeight = min(minHeight, farm[i][j]);
            maxHeight = max(maxHeight, farm[i][j]);
        }
    }
    
    int lo = minHeight, hi = maxHeight, mid = (lo + hi) / 2;

    while (hi > lo + 1) {
        mid = (lo + hi) / 2;
        if (possible(mid)) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    
    cout << hi << endl;
    out << hi << endl;
    
    return 0;
}


