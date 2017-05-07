//
//  main.cpp
//  Bobsledding
//
//  Created by Dhruv Shah on 6/30/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define INF 1 << 29

using namespace std;

struct turn {
    int t, s;
    bool operator<(const turn& tu) const {
        return t < tu.t;
    }
}t[100005];

int L, N;
int decc[100005], acc[100005];

int main(int argc, const char * argv[]) {
    cin >> L >> N;
    t[0] = {0, 1};
    for (int i = 1; i <= N; i++) {
        cin >> t[i].t >> t[i].s;
    }
    t[N + 1] = {L, INF};
    N += 2;
    sort(t, t + N);
    
    decc[N - 1] = t[N - 1].s;
    for (int i = N - 2; i >= 0; i--) {
        decc[i] = min(decc[i + 1] + (t[i + 1].t - t[i].t), t[i].s);
    }
    
    int maxS = 1;
    acc[0] = t[0].s;
    for (int i = 1; i <= N; i++) {
        acc[i] = min(acc[i-1] + (t[i].t - t[i - 1].t), decc[i]);
        maxS = max(maxS, max(acc[i - 1], acc[i]) + (int)(((t[i].t - t[i - 1].t) - abs(acc[i - 1] - acc[i])) / 2));
    }
    
    cout << maxS << endl;
    
    return 0;
}
