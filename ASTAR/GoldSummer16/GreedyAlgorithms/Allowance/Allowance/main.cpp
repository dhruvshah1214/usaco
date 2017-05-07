//
//  main.cpp
//  Allowance
//
//  Created by Dhruv Shah on 6/29/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define INF 1 << 29

using namespace std;

struct coin {
    int v, a;
    bool operator<(const coin& c) const {
        return v < c.v;
    }
} c[25];

int N, C;
int ans = 0;


int main(int argc, const char * argv[]) {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> c[i].v >> c[i].a;
        if (c[i].v >= C) {
            ans += c[i].a;
            c[i].a = 0;
        }
    }
    sort(c, c + N);
    
    
    bool m = true;
    
    while (m) {
        int suma = C;
        m = false;
        for (int i = N - 1; i >= 0; i--) {
            while (c[i].a>0 && suma-c[i].v >= 0) {
                c[i].a--;
                suma -= c[i].v;
            }
        }
        for (int i = 0; i < N; i++)
            if (c[i].a > 0 && suma > 0) {
                c[i].a--;
                suma -= c[i].v;
                break;
            }
        if (suma <= 0) m = true;
        if (m) ans++;
    }

    cout << ans << endl;    
    return 0;
}
