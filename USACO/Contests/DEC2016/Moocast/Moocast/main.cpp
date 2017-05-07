//
//  main.cpp
//  Moocast
//
//  Created by Dhruv Shah on 12/17/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int N;
pair<int, pair<int, int> > cows[205]; 
int ans = 0;

int sq(int a) {
    return a * a;
}

int eucliddist(pair<int, int> a, pair<int, int> b) {
    return sq(a.first - b.first) + sq(a.second - b.second);
    
}

void rec(int cur, int pos, bool vis[205]) {
    for (int i = 0; i < N; i++) {
        if (vis[i] == false && (eucliddist(cows[pos].second, cows[i].second) <= sq(cows[pos].first))) {
            vis[i] = true;
            rec(cur + 1, i, vis);
        }
    }
    cout << cur << " " << pos << endl;
    int aa = 0;
    for (int i = 0; i < N; i++) {
        if (vis[i] == true) {
            aa++;
        }
    }
    ans = max(ans, aa);
}

int main(int argc, const char * argv[]) {
    ifstream in("moocast.in");
    ofstream out("moocast.out");
    
    in >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        
        in >> a >> b >> c;
        
        cows[i] = make_pair(c, make_pair(a, b));
    }
    
    for (int n = 0; n < N; n++) {
        bool ar[205];
        for (int j = 0; j <= N; j++) {
            ar[j] = false;
        }
        ar[n] = true;
        rec(1, n, ar);
        cout << endl;
    }
    
    cout << ans << endl;
    out << ans << endl;

    return 0;
}
