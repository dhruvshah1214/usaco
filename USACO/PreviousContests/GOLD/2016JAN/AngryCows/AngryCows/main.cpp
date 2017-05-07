//
//  main.cpp
//  AngryCows
//
//  Created by Dhruv Shah on 7/3/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

long N, bales[50005];
long dpr[50005];
long dpl[50005];

void explode(set<long>& s, long c, long r) {
    std::set<long>::iterator itlow,itup;
    itlow = s.lower_bound(c - r);
    itup = s.upper_bound(c + r + 1);
    if (itlow != s.end() && itup != s.end()) {
        s.erase(itlow, itup);
        explode(s, c - r, r - 1);
        explode(s, c + r, r - 1);

    }
    else if(itlow != s.end()) {
        s.erase(itlow, s.upper_bound(c));
        explode(s, c - r, r - 1);
    }
    else if(itup != s.end()) {
        s.erase(s.lower_bound(c), itup);
        explode(s, c + r, r - 1);
    }

}

bool possibleFirst(set<long> s, long l, long r) {
    cout << "ELE " << s.size() << endl;
    explode(s, l, r);
    cout << "EEEE" << s.size() << endl;
    return s.empty();
}

int main() {
    ifstream in("angry.in");
    ofstream out("angry.out");
    set<long> bset;

    cin >> N;
    for (long i = 0; i < N; i++) {
        cin >> bales[i];
        bales[i] *= 2;
        bset.insert((long)bales[i]);
    }
        
    
    long min = 0;
    long max = 1000000000;
    while(min != max) {
        long mid = (min+max)/2;
        long l = *bset.begin();
        long r = *bset.rbegin();
        while(l < r) {
            long m = (l+r+1)/2;
            if(possibleFirst(bset, m, mid)) {
                l = m;
            }
            else {
                r = m-1;
            }
        }
        if(possibleFirst(bset, l, mid)) {
            max = mid;
        }
        else {
            min = mid+1;
        }
    }
    
    cout << min << endl;
    
    return 0;
}
