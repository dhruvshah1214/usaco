//
//  main.cpp
//  CityHorizon
//
//  Created by Dhruv Shah on 6/15/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

long long int N, Hi[40001];
pair<long long int, long long int> ALL[80002];
multiset<long long int> ms;

bool pcomp(pair<long long int, long long int> a, pair<long long int, long long int> b) {
    return a.first < b.first;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (long long int i = 0; i < N; i++) {
        long long int a, b;
        cin >> a >> b >> Hi[i];
        ALL[i].first = a;
        ALL[i].second = i;
        ALL[i + N].first = b;
        ALL[i + N].second = i + N;
        Hi[i + N] = Hi[i];

    }
    sort(ALL, ALL + (2 * N), pcomp);

    long long int lastLoc = 0;
    long long int runningSum = 0;
    for (long long int i = 0; i < 2 * N; i++) {
        long long int objI = ALL[i].second;
        long long int num = ALL[i].first;
        bool isA = (objI < N);
        long long int h = Hi[objI];
        if (i != 0 && !(ms.empty())) {
            runningSum += (*(ms.rbegin()) * (num - lastLoc));
        }
        if (isA) {
            ms.insert(h);            
        }
        else {
            ms.erase(ms.find(h));
        }
        lastLoc = num;
    }
    
    cout << runningSum << endl;
    
    return 0;
}
