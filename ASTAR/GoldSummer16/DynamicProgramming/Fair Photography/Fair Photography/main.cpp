//
//  main.cpp
//  Fair Photography
//
//  Created by Dhruv Shah on 6/24/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long N;
pair<long long, pair<long long, long long> > z[100005]; 
pair<long long, long long> cow[100005];

// a{x, {y, positionOnGraph}}

bool custcomp(pair<long long, pair<long long, long long> > a, pair<long long, pair<long long, long long> > b) {
    if (a.second.first != b.second.first) {
        return a.second.first > b.second.first;
    }
    return a.first > b.first;
}

bool insort(pair<long long, long long > a, pair<long long, long long > b) {
    
    return a.first < b.first;
}

int main() {
    cin >> N;
    long long sum = 0;
    for (long long i = 1; i <= N; i++) {
        int b;
        char c;
        cin >> b >> c;
        cow[i].first = b;
        cow[i].second = ((c == 'W') ? 1 : -1);
    }
    sort(cow + 1, cow + N + 1, insort);
    z[0] = make_pair(0, make_pair(0, 0));
    for (long long i = 1; i <= N; i++) {
        sum += cow[i].second;
        z[i] = make_pair(i, make_pair(sum, cow[i].first));
    }
    sort(z, z + N + 1, custcomp);
    
    /*
    for (long long i = 0; i <= N; i++) {
        cout << a[i].first << " " << a[i].second.first << " " << a[i].second.second << endl;

    }*/
    
    
    long long right = z[0].first;
    long long rightI = 0;
    long long maxn = 0;
    for (long long i = 0; i <= N; i++) {
        if (z[i].first > right) {
            right = z[i].first;
            rightI = i;
        }
        else {
            if (z[i].second.first <= z[rightI].second.first &&
                z[i].first + 1 > 0 && z[i].first + 1 <= N) {
                if ((right - z[i].first) % 2 == 0) {
                    maxn = max(maxn, z[rightI].second.second - cow[z[i].first + 1].first);
                }
                else {
                    if (right - 1 >= 0) {
                        maxn = max(maxn, cow[right - 1].first - cow[z[i].first + 1].first);
                    }
                    if (z[i].first + 2 <= N) {
                        maxn = max(maxn, z[rightI].second.second - cow[z[i].first + 2].first);
                    }
                }
            }
        }
    }
    cout << maxn << endl;
    return 0;
}
/*
 5
 0 S
 4 W
 5 W
 3 S
 9 S
 */
