//
//  main.cpp
//  Crowded Cows
//
//  Created by Dhruv Shah on 6/30/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int N, D;
pair<int , int> cows[50005];

int main(int argc, const char * argv[]) {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    
    sort(cows, cows + N);
    
    int result = 0;
    multiset<int> prev, next;
    
    int j = 0, k = 0;
    for(int i = 0; i < N; i++) {
        while(k < N && cows[k].first <= cows[i].first + D) {
            next.insert(cows[k].second);
            k++;
        }
        while(cows[j].first + D < cows[i].first) {
            prev.erase(prev.find(cows[j].second));
            j++;
        }
        prev.insert(cows[i].second);
        
        if (*(prev.rbegin()) >= 2 * cows[i].second && *(next.rbegin()) >= 2 * cows[i].second) {
            result++;
        }
        next.erase(next.find(cows[i].second));
    }
    cout << result << endl;
    return 0;
}


