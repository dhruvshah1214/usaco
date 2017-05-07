//
//  main.cpp
//  Div7Try2
//
//  Created by Dhruv Shah on 11/16/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int N, pref[50005];
int longest[7], shortest[7];

int main(int argc, const char * argv[]) {
    ifstream in("div7.in");
    ofstream out("div7.out");
    
    bool debug = false;
    
    if (debug) {
        cin >> N;
    }
    else {
        in >> N;
    }
    
    for (int i = 0; i < 7; i++) {
        shortest[i] = -1;
        longest[i] = -1;
    }
    
    int cur = 0;
    for (int i = 0; i < N; i++) {
        int a;
        if (debug) {
            cin >> a;
        }
        else {
            in >> a;
        }
        cur += a;
        cur %= 7;
        pref[cur] = i;
        if (shortest[cur] == -1) {
            shortest[cur] = i;
        }
        longest[cur] = i;
    }
    
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        ans = max(ans, longest[i] - shortest[i]);
    }
    
    cout << ans << endl;
    out << ans << endl;
    
    return 0;
}
