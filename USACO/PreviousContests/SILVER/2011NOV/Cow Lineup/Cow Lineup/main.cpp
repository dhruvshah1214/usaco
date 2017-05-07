//
//  main.cpp
//  Cow Lineup
//
//  Created by Dhruv Shah on 7/17/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>


#include <ctime>
#include <iomanip>

using namespace std;

int N;
pair<int, int> cows[50005];
int photoCost = (1 << 30);
multiset<int> curIDs; 
set<int> curIDU; 
set<int> allIDs; 

int ms;


bool csort(const pair<int, int> c1, const pair<int, int> c2) {
    return c1.first < c2.first;
}

bool contAll() {
    return (int)curIDU.size() == ms;
}

void solve(bool fileIO, string fileName) {
    
    ifstream in;
    if (fileIO) {
        in.open(fileName.c_str());
    }
    
    ofstream out("lineup.out");
    
    if (fileIO) {
        in >> N;
    }
    else {
        cin >> N;
    }
    for (int i = 0; i < N; i++) {
        if (fileIO) {
            in >> cows[i].first >> cows[i].second;
        }
        else {
            cin >> cows[i].first >> cows[i].second;
        }
        allIDs.insert(cows[i].second);
    }
    ms = (int)allIDs.size();
    sort(cows, cows + N, csort);
    /*
    for (int i = 0; i < N; i++) {
        cout << cows[i].first << " " << cows[i].second << endl;
    }
    */
    int left = 0, right = 0;
    int lp = cows[0].first, rp = cows[0].first;
    curIDs.insert(cows[0].second);
    curIDU.insert(cows[0].second);

    do {

        if (contAll()) {
            lp = cows[left].first, rp = cows[right].first;
            photoCost = min(photoCost, abs(rp - lp));
            
            curIDs.erase(curIDs.find(cows[left].second));
            if (!curIDs.count(cows[left].second)) {
                curIDU.erase(cows[left].second);

            }

            left++;
            // cout << "ASKDHJ" << endl;

        }
        else {
            right++;
            curIDs.insert(cows[right].second);
            curIDU.insert(cows[right].second);
        }
        

        
    } while (left < right && right < N);
    
    /*
    cout << photoCost << endl;
    out << photoCost << endl;
     */
}

int main(int argc, const char * argv[]) {
    solve(false, "");
    cout << photoCost << endl;
    return 0;
}
