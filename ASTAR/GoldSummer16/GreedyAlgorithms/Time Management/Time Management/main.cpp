//
//  main.cpp
//  Time Management
//
//  Created by Dhruv Shah on 6/29/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct task {
    int t, s;
    bool operator<(const task& t) const {
        return s > t.s;
    }
};


int N;
task t[1005];

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t[i].t >> t[i].s;
    }
    sort(t, t + N);
    
    int latesttime = 1000000;
    for (int i = 0; i < N; i++) {
        latesttime = min(t[i].s, latesttime) - t[i].t;
    }
    if (latesttime < 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << latesttime << endl;

    
    return 0;
}