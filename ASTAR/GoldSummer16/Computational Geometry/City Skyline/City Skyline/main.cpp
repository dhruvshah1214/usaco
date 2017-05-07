//
//  main.cpp
//  City Skyline
//
//  Created by Dhruv Shah on 6/30/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, W, ans = 0;

int main(int argc, const char * argv[]) {
    cin >> N >> W;
    stack<int> s;
    s.push(0);
    int inp = 0;
    while (inp <= N) {
        int x, y;
        if (inp < N) {
            scanf("%d %d", &x, &y);
        }
        else {
          y = 0;  
        }
        while (y < s.top())
        {
            ans++;
            s.pop();
        }
        if (y > s.top()) {
            s.push(y);
        }
        inp++;
    }
    
    cout << ans << endl;
    return 0;
}
/*
 10 26
 1 1
 2 2
 5 1
 6 3
 8 1
 11 0
 15 2
 17 3
 20 2
 22 1
 */
