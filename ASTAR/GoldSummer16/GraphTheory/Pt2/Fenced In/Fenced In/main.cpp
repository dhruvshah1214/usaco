//
//  main.cpp
//  Fenced In
//
//  Created by Dhruv Shah on 6/27/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<long long, long long > pll;
    
long long A, B, n, m;
long long np[2005], mp[2005];
pair<long long , long long> nodes[4020025];
vector<pll> mat[4020025];

int main() {
    cin >> A >> B >> n >> m;
    
    np[0] = 0;
    mp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> np[i];
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> mp[i];
    }
    sort(np, np + n);
    sort(mp, mp + m);
    
    np[n + 1] = A;
    mp[m + 1] = B;
    n++, m++;
    
    int nodeC = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            nodes[nodeC] = make_pair(np[i], mp[j]);
            nodeC++;
        }
    }
    
    for (int i = 0; i < nodeC; i++) {
        if (i + 1 <= ) {
            <#statements#>
        }
        mat[i].push_back(make_pair(i + 1, <#_T2 &&__t2#>))
    }
    
    
    
    
    return 0;
}
