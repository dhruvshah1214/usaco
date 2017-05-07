//
//  main.cpp
//  Bovine Bridge Battle
//
//  Created by Dhruv Shah on 6/30/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

struct point {
    int x, y;
} p[1005];

int N;
map<pair<int, int> , int> m;

int choose2(int a) {
    return ((a * (a - 1)) / 2);
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
                int dx = p[i].x + p[j].x;
                int dy = p[i].y + p[j].y;
                m[make_pair(dx, dy)]++;
                // cout << dx << " " << dy << endl;
        }
    }
    
    int ans = 0;
    for (map<pair<int, int>, int>::iterator it = m.begin(); it != m.end(); it++) {
        ans += (((it -> second) / 2) * (((it -> second) / 2) - 1)) / 2;
    }
    
    cout << ans << endl;
    
    return 0;
}
