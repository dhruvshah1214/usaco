/*
 LANG: C++11
 TASK:
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

#define MAXINT 1 << 29


using namespace std;

typedef pair<int, int> pii;

int N;
pii cows[50001];

bool xsort(pii p1, pii p2) {
    return p1.first < p2.first;
}


int main(int argc, const char * argv[]) {
    ifstream in("reduce.in");
    ofstream out("reduce.out");
    
    in >> N;
    for (int i = 0; i < N; i++) {
        in >> cows[i].first >> cows[i].second;
    }
    
    int minx = cows[0].first, maxx = cows[0].first, miny = cows[0].first, maxy = cows[0].first;
    int minxi = 0, minyi = 0, maxxi = 0, maxyi = 0;
    for (int i = 0; i < N; i++) {
        if (cows[i].first < minx) {
            minx = cows[i].first;
            minxi = i;
        }
        if (cows[i].first > maxx) {
            maxx = cows[i].first;
            maxxi = i;
        }
        if (cows[i].second < miny) {
            miny = cows[i].second;
            minyi = i;
        }
        if (cows[i].second > maxy) {
            maxy = cows[i].second;
            maxyi = i;
        }
    }
    
    int area = (maxx - minx) * (maxy - miny);
    cout << area << endl;
    
    int ignoreI[4] = {minxi, maxxi, minyi, maxyi};
    
    minx = MAXINT, maxx = 0, miny = MAXINT, maxy = 0;
    minxi = 0, minyi = 0, maxxi = 0, maxyi = 0;
    
    for (int i = 0; i < N; i++) {
        int j = 0;
        for (j = 0; j  < 4; j++) {
            if (i == ignoreI[j]) {
                break;
            }
        }
        if (j < 4) {
            continue;
        }
        if (cows[i].first < minx) {
            minx = cows[i].first;
            minxi = i;
        }
        if (cows[i].first > maxx) {
            maxx = cows[i].first;
            maxxi = i;
        }
        if (cows[i].second < miny) {
            miny = cows[i].second;
            minyi = i;
        }
        if (cows[i].second > maxy) {
            maxy = cows[i].second;
            maxyi = i;
        }
    }
    
    area = (maxx - minx) * (maxy - miny);
    cout << area << endl;
    out << area << endl;
    
    
    return 0;
}