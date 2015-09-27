/*
PROG: wormhole
LANG: C++11
*/


#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

struct point {
    int x, y;
    point(int a, int b) {
        x = a;
        y = b;
    }
    point() {
        
    }
};


int N;
point wormholes[13];
int partners[13];
int next_on_right[13];

int distinctPairings = 0;

bool loopForver() {
    for (int start=0; start<N; start++) {
        // does there exist a cylce starting from start
        int pos = start;
        for (int count=0; count<N; count++)
            pos = next_on_right[partners[pos]];
        if (pos != 0) return true;
    }
    return false;
}

int solution() {
    int i, total=0;
    for (i=0; i<N; i++)
        if (partners[i] == 0) break;
    
    if (i >= N - 1) {
        if (loopForver()) return 1;
        else return 0;
    }
    
    for (int j=i+1; j<N; j++) {
        if (partners[j] == 0) {
            partners[i] = j;
            partners[j] = i;
            total += solution();
            partners[i] = partners[j] = 0;
        }
    }
    return total;
}

int main(int argc, const char * argv[]) {
    ifstream in("wormhole.in");
    in >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        in >> a >> b;
        wormholes[i] = point(a, b);
    }
    
    for (int i=0; i < N; i++) // set next_on_right[i]...
        for (int j=0; j < N; j++)
            if (wormholes[j].x > wormholes[i].x && wormholes[i].y == wormholes[j].y)
                if (next_on_right[i] == 0 ||
                    wormholes[j].x - wormholes[i].x < wormholes[next_on_right[i]].x-wormholes[i].x)
                    next_on_right[i] = j;
    
    int sol = solution();
    cout << N << endl << sol << endl;
    
    ofstream out("wormhole.out");
    out << sol << endl;

    return 0;
}
