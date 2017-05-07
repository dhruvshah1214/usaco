//
/*
 PROG: ratios
 LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int r[5][4];
int best = 400, sol[5];

int mod(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a % b;
}

void check(int a, int b, int c) {
    int totalOfItem[3] = {0, 0, 0};
    int arr[3] = {a,b,c};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            totalOfItem[j] += arr[i] * r[i + 1][j];
        }
    }
    int m = 0;
    for (int j = 0; j < 3; j++) {
        if (r[0][j] != 0) {
            m = (totalOfItem[j] / r[0][j]);
        }
    }
    
    bool works = true;
    for (int i = 0; i < 3; i++) {
        works = works && (mod(totalOfItem[i], r[0][i]) == 0) && (m * r[0][i] == totalOfItem[i]);
    }
    works = works && (a + b + c != 0);
    if (works) {
        if (a + b + c < best) {
            sol[0] = a;
            sol[1] = b;
            sol[2] = c;
            sol[3] = m;
            best = a + b + c;
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream in("ratios.in");
    ofstream out("ratios.out");
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            in >> r[i][j];
        }
    }
    
    for (int i = 0; i <= 101; i++) {
        for (int j = 0; j <= 101; j++) {
            for (int k = 0; k <= 101; k++) {
                if (i + j + k < best) {
                    check(i, j, k);
                }
            }
        }
    }
    
    if (sol[0] + sol[1] + sol[2] + sol[3] == 0) {
        cout << "NONE" << endl;
        out << "NONE" << endl;
        return 0;
    }
    
    for (int i = 0; i < 4; i++) {
        cout << sol[i];
        out << sol[i];
        if (i < 3) {
            cout << " ";
            out << " ";
        }
    }
    cout << endl;
    out << endl;
    
    return 0;
}
