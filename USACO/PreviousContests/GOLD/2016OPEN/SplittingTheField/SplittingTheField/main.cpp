//
//  main.cpp
//  SplittingTheField
//
//  Created by Dhruv Shah on 12/19/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int N;
pair<int, int> xc[50005];
pair<int, int> yc[50005];
multiset<int> yS;
multiset<int> xS;
multiset<int> xS1;

bool fsort(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first < p2.first;
}

bool ssort(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}

void input(istream& inp) {
    inp >> N;
    for (int i = 0; i < N; i++) {
        inp >> xc[i].first >> xc[i].second;
        yc[i] = xc[i];
        xS.insert(xc[i].first);
        yS.insert(xc[i].second);
    }
}

int main(int argc, const char * argv[]) {
    ifstream in("split.in");
    ofstream out("split.out");
    
    bool debug = true;
    
    if (debug) {
        input(cin);
    }
    else {
        input(in);
    }
    
    sort(xc, xc + N, fsort);
    sort(yc, yc + N, ssort);
    
    for (int i = 0; i < N; i++) {
        xS.erase(xS.find(xc[i].first));
    }

    return 0;
}
