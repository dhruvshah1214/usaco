/*
 ID: dhruv.s2
 PROG: mirrors
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, a, b;

struct mirror {
    int x, y, i;
    bool bouncesUp;
    mirror(int a, int b, bool c, int d) {
        x = a;
        y = b;
        bouncesUp = c;
        i = d;
    }
    mirror() {
        
    }
};

enum direction { UP, DOWN, RIGHT, LEFT };

mirror mirrorsX[201];
// mirror mirrorsY[201];

bool mirrorSortY(mirror m1, mirror m2) {
    if (m1.y == m2.y) {
        return (m1.x < m2.x);
    }
    return (m1.y < m2.y);
}

bool mirrorSortX(mirror m1, mirror m2) {
    if (m1.x == m2.x) {
        return (m1.y < m2.y);
    }
    return (m1.x < m2.x);
}

direction setDirection(direction curDir, bool bouncesUp) {
    if (curDir == RIGHT) {
        if (bouncesUp) {
            return UP;
        }
        else {
            return DOWN;
        }
    }
    else if (curDir == LEFT) {
        if (bouncesUp) {
            return DOWN;
        }
        else {
            return UP;
        }
    }
    else if (curDir == UP) {
        if (bouncesUp) {
            return RIGHT;
        }
        else {
            return LEFT;
        }
    }
    else if (curDir == DOWN) {
        if (bouncesUp) {
            return LEFT;
        }
        else {
            return RIGHT;
        }
    }
    else {
        cout << "ERROR" << endl;
        return RIGHT;
    }
}

bool barnInSightDirect(int curX, int curY, direction dir) {
    if (curX == a && curY < b && dir == UP) {
        return true;
    }
    else if (curX == a && curY > b && dir == DOWN) {
        return true;
    }
    else if (curY == b && curX < a && dir == RIGHT) {
        return true;
    }
    else if (curY == b && curX > a && dir == LEFT) {
        return true;
    }
    return false;
}

bool canSeeBarn() {
    int curX = 0, curY = 0;
    direction dir = RIGHT;
    bool visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    while (curX != a || curY != b) {
         cout << curX << " " << curY << " " << dir << endl;
        
        if (barnInSightDirect(curX, curY, dir)) {
            curX = a;
            curY = b;
            break;
        }
        if(dir == UP) {
            int smallestGreater = 1000000;
            for (int i = 0; i < N; i++) {
                // cout << "DEBUG" << curY << " " << curX << " " << mirrorsX[i].x << endl;
                if (mirrorsX[i].x == curX && mirrorsX[i].y > curY && mirrorsX[i].y < smallestGreater) {
                    smallestGreater = mirrorsX[i].y;
                    curY = mirrorsX[i].y;
                    dir = setDirection(dir, mirrorsX[i].bouncesUp);
                    if (visited[i]) {
                        return false;
                    }
                    visited[i] = true;
                }
            }
            if (smallestGreater == 1000000) {
                return false;
            }
        }
        else if(dir == DOWN) {
            int largestSmaller = -1000000;
            for (int i = 0; i < N; i++) {
                if (mirrorsX[i].x == curX && mirrorsX[i].y < curY && mirrorsX[i].y > largestSmaller) {
                    cout << "DEBUG" << curX << " " << curY << " " << mirrorsX[i].y << endl;

                    largestSmaller = mirrorsX[i].y;
                    curY = mirrorsX[i].y;
                    dir = setDirection(dir, mirrorsX[i].bouncesUp);
                    if (visited[i]) {
                        return false;
                    }
                    visited[i] = true;
                }
            }
            if (largestSmaller == -1000000) {
                return false;
            }
        }
        else if(dir == LEFT) {
            int largestSmaller = -1000000;
            for (int i = 0; i < N; i++) {
                if (mirrorsX[i].y == curY && mirrorsX[i].x < curX && mirrorsX[i].x > largestSmaller) {
                    // cout << "DEBUG" << curY << " " << curX << " " << mirrorsX[i].x << endl;
                    largestSmaller = mirrorsX[i].x;
                    curX = mirrorsX[i].x;
                    dir = setDirection(dir, mirrorsX[i].bouncesUp);
                    if (visited[i]) {
                        return false;
                    }
                    visited[i] = true;
                }
            }
            if (largestSmaller == -1000000) {
                return false;
            }
        }
        else if(dir == RIGHT) {
            int smallestGreater = 1000000;
            for (int i = 0; i < N; i++) {
                if (mirrorsX[i].y == curY && mirrorsX[i].x > curX && mirrorsX[i].x < smallestGreater) {
                     // cout << "DEBUG" << curY << " " << curX << " " << mirrorsX[i].x << endl;
                    smallestGreater = mirrorsX[i].x;
                    curX = mirrorsX[i].x;
                    dir = setDirection(dir, mirrorsX[i].bouncesUp);
                    if (visited[i]) {
                        return false;
                    }
                    visited[i] = true;
                }
            }
            if (smallestGreater == 1000000) {
                return false;
            }
        }
        else {
            cout << "ERROR WHILE" << endl;
            return false;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    ifstream in("mirrors.in");
    ofstream out("mirrors.out");
        
    in >> N >> a >> b;
    cout << "N: " << N << " " << a << " " << b << endl << endl;
    for (int i = 0; i < N; i++) {
        int a, b;
        in >> a >> b;
        char c;
        in >> c;
        bool dir;
        if (c == '/') {
            dir = true;
        }
        else {
            dir = false;
        }
        mirrorsX[i] = mirror(a, b, dir, i + 1);
        // mirrorsY[i] = mirror(a, b, dir, i + 1);

    }
    
    // sort(mirrorsX, mirrorsX + N, mirrorSortX);
    
    if (canSeeBarn()) {
        cout << 0 << endl;
        out << 0 << endl;
    }
    else {
         cout << "CANT SEE FIRST " << endl;
        bool found = false;
        for (int i = 0; i < N; i++) {
            mirrorsX[i].bouncesUp = !(mirrorsX[i].bouncesUp);
            if (canSeeBarn()) {
                cout << i + 1 <<  endl;
                out << i + 1 << endl;
                found = true;
                break;
            }
            mirrorsX[i].bouncesUp = !(mirrorsX[i].bouncesUp);
            cout << endl;
        }
        if (!found) {
            cout << -1 << endl;
            out << -1 << endl;
        }
    }

    
    return 0;
}
