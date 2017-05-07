/*
 LANG: C++11
 TASK:
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <climits>

#define MAXINT 1 << 29


using namespace std;

typedef pair<int, int> pii;


int N;
char arr[101][101];

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};


int regions() {
    bool vis[101][101] = {0};

    int vCount = 0;
    int rCount = 0;
    while (vCount < N * N) {
        int i = 0, j = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (!vis[i][j]) {
                    rCount++;
                    break;
                }
            }
            if (j < N) {
                break;
            }
        }
        if ((i == j) && i == 5) {
            break;
        }
        cout << i << " " << j << endl;
        stack<pii> s;
        s.push(make_pair(i, j));
        vis[i][j] = true;
        while (!s.empty()) {
            pii p = s.top();
            s.pop();
            vCount++;
            for (int i = 0; i < 4; i++) {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if (0 <= nx && nx < N && 0 <= ny && ny < N && !vis[nx][ny] && arr[nx][ny] == arr[p.first][p.second]) {
                    s.push(make_pair(nx, ny));
                    vis[nx][ny] = 1;
                }
            }
        }
        cout << vCount << endl;

    }
    return rCount;
}

int main(int argc, const char * argv[]) {
    ifstream in("cowart.in");
    ofstream out("cowart.out");
    
    in >> N;
    for (int i = 0; i < N; i++) {
        in >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    int humanr = regions();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'G') {
                arr[i][j] = 'R';
            }
        }
    }
    int  cowr = regions();
    
    cout << humanr << " " << cowr << endl;
    out << humanr << " " << cowr << endl;
    
    return 0;
}


