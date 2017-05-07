//
//  main.cpp
//  FieldReductionTry2
//
//  Created by Dhruv Shah on 11/22/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

long long N;
pair<long long, pair<long long, long long> > cows[50005];
pair<long long, pair<long long, long long> > cowsX[50005];
pair<long long, pair<long long, long long> > cowsY[50005];
long long minArea = (1ll << 60);

bool ysort(const pair<long long, pair<long long, long long> > p1, const pair<long long, pair<long long, long long> > p2) {
    return p1.second.first < p2.second.first;
}

long long cowsOutside(long long bound[4]) {
    set<long long> cowOut;
    for (long long i = 0; i < 4; i++) {
        if (cowsX[i].first < bound[1] || cowsX[i].first > bound[0]) {
            cowOut.insert(cowsX[i].second.second);
        }
        if (cowsX[i].second.first < bound[3] || cowsX[i].second.first > bound[2]) {
            cowOut.insert(cowsX[i].second.second);
        }
        
        if (cowsX[N - 1 - i].first < bound[1] || cowsX[N - 1 - i].first > bound[0]) {
            cowOut.insert(cowsX[N - 1 - i].second.second);
        }
        if (cowsX[N - 1 - i].second.first < bound[3] || cowsX[N - 1 - i].second.first > bound[2]) {
            cowOut.insert(cowsX[N - 1 - i].second.second);
        }
        
        if (cowsY[i].first < bound[1] || cowsY[i].first > bound[0]) {
            cowOut.insert(cowsY[i].second.second);
        }
        if (cowsY[i].second.first < bound[3] || cowsY[i].second.first > bound[2]) {
            cowOut.insert(cowsY[i].second.second);
        }
        
        if (cowsY[N - 1 - i].first < bound[1] || cowsY[N - 1 - i].first > bound[0]) {
            cowOut.insert(cowsY[N - 1 - i].second.second);
        }
        if (cowsY[N - 1 - i].second.first < bound[3] || cowsY[N - 1 - i].second.first > bound[2]) {
            cowOut.insert(cowsY[N - 1 - i].second.second);
        }
    }
    return (long long)cowOut.size();
}

int main(int argc, const char * argv[]) {
    ifstream in("reduce.in");
    ofstream out("reduce.out");
    
    bool debug = false;
    
    if (debug) {
        cin >> N;
        for (long long i = 0; i < N; i++) {
            cin >> cows[i].first >> cows[i].second.first;
            cows[i].second.second = i;
            cowsX[i] = cowsY[i] = cows[i];
        }
    }
    else {
        in >> N;
        for (long long i = 0; i < N; i++) {
            in >> cows[i].first >> cows[i].second.first;
            cows[i].second.second = i;
            cowsX[i] = cowsY[i] = cows[i];
        }
    }
    
    sort(cowsX, cowsX + N);
    sort(cowsY, cowsY + N, ysort);

    long long cowSet[4][4];
    
    /*
     *
     * [0] -> minX
     * [1] -> maxX
     * [2] -> minY
     * [3] -> maxY
     *
     */
    
    for (long long i = 0; i < 4; i++) {
        long long a = cowSet[0][i] = (cowsX[i].second.second);
        long long b = cowSet[1][i] = (cowsX[N - i - 1].second.second);
        long long c = cowSet[2][i] = (cowsY[i].second.second);
        long long d = cowSet[3][i] = (cowsY[N - i - 1].second.second);
        cout << a << "  " << b << "  " << c << "  " << d << endl;
    }
    
    for (long long i = 0; i < N; i++) {
        cout << cowsX[i].first << " " << cowsY[i].second.first << endl;
    }
    
    cout << endl << endl;
    
    for (long long a = 0; a < 4; a++) {
        for (long long b = 0; b < 4; b++) {
            for (long long c = 0; c < 4; c++) {
                for (long long d = 0; d < 4; d++) {
                    long long bounds[4] = {cows[cowSet[1][b]].first, cows[cowSet[0][a]].first, cows[cowSet[3][d]].second.first, cows[cowSet[2][c]].second.first};
                    long long cO = cowsOutside(bounds);
                    cout << cO << endl;
                    if (cO <= 3) {
                        long long area = (bounds[0] - bounds[1]) * (bounds[2] - bounds[3]);
                        cout << bounds[0] << " " << bounds[1] << " " << bounds[2] << " " << bounds[3] << endl;
                        minArea = min(minArea, area);
                    }
                }
            }
        }
    }
    
    cout << max(0ll, minArea) << endl;
    out << max(0ll, minArea) << endl;

    return 0;
}
