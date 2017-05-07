//
//  main.cpp
//  CircularBarnTry2
//
//  Created by Dhruv Shah on 11/23/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


struct cow {
    int id, sloc, loc, d;
    bool operator<(const cow c2) {
        return d < c2.d;
    }
    bool operator>(const cow c2) {
        return d > c2.d;
    }
};

int N, nums[100005];
vector<int> ids[100005];
cow cows[100005];
deque<int> active (0);
int final[1000005];
long long ans = 0;


int main(int argc, const char * argv[]) {
    ifstream in("cbarn.in");
    ofstream out("cbarn.out");
    
    bool debug = false;
    
    if(debug) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
    }
    else {
        in >> N;
        for (int i = 0; i < N; i++) {
            in >> nums[i];
        }
    }
    
    int counter = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < nums[i]; j++) {
            cows[counter] = {counter, i, i, 0};
            ids[i].push_back(counter);
            counter++;
        }
    }
    
    int sid = 0, start = 0;
    for (int i = 0; i < N; i++) {
        /*if (nums[i] > start) {
            sid = i;
            start = nums[i];
        }*/
        start = max(0, start + nums[i] - 1);
    }
    for (int i = 0; ; i++) {
        if (start == 0) {
            sid = i;
            break;
        }
        start = max(0, start + nums[i] - 1);
    }
    
    for (int i = sid; i < sid + N; i++) {
        int ind = (i % N);
         cout << "SSS " << i << " " << ind << endl;
        // change distances
        cout << "ACTIVE ";
        for (unsigned k = 0; k < (unsigned)active.size(); k++) {
            int cid = active[k];
            cows[cid].d++;
            cows[cid].loc = ind;
            if (k > active.size()) {
                break;
            }
            cout << cows[cid].d << " ";
        }
        cout << endl;
        
        //pickup cows(push to back), drop off largest distance traveler (front of deque)
        for (int j = 0; j < ids[ind].size(); j++) {
            active.push_back(ids[ind][j]);
        }
        
        if (active.size() > 0) {
            int dropoffID = active.front();
            active.pop_front();
            final[ind] = dropoffID;
        }
        
        
        
        
        
        
    }
    
    cout << endl << endl;
    for (int i = 0; i < N; i++) {
        cout << cows[i].sloc << " " << cows[i].loc << " " << cows[i].d << endl;
    }
    
    for (int i = 0; i < N; i++) {
        ans += (cows[i].d * cows[i].d);
    }
    
    cout << ans << endl;
    out << ans << endl;
    
    return 0;
}
