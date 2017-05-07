//
//  main.cpp
//  Best Cow Line
//
//  Created by Dhruv Shah on 7/1/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>

#define INF 1 << 29

using namespace std;

int N;
char cows[2005];

bool dequePop(int front, int back) {
    string cowstr(cows, cows + N);
    string sub1 = cowstr.substr(front, back - front + 1);
    string sub2 = cowstr.substr(front, back - front + 1);
    
    reverse(sub2.begin(), sub2.end());
    
    // cout << "SUBSTR " << sub1 << " " << sub2 << endl;

    return sub1 < sub2;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    
    deque<pair<char, int> > d;
    vector<char> v;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        cows[i] = c;
        d.push_back({c, i});
    }
    
    while (!d.empty()) {
        bool popFront = dequePop(d.front().second, d.back().second);
        // cout << d.front().second << " " << d.back().second << " " << popFront << endl;
        char c;
        if (popFront) {
            c = d.front().first;
            d.pop_front();
        }
        else {
            c = d.back().first;
            d.pop_back(); 
        }
        v.push_back(c);
    }
    
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if ((i + 1) % 80 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}

