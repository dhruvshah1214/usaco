//
//  main.cpp
//  HighCardLowCard
//
//  Created by Dhruv Shah on 12/19/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

int N, points = 0;
bool isECard[100001];
vector<int> ECards;
vector<int> BCCards;

set<int> BCards;
set<int> BCards2;

int main(int argc, const char * argv[]) {
    ifstream in("cardgame.in");
    ofstream out("cardgame.out");
    
    in >> N;
    for (int i = 0; i < 2 * N; i++) {
        isECard[i + 1] = false;
        
    }
    for (int i = 1; i <= N; i++) {
        int a;
        in >> a;
        isECard[a] = true;
        ECards.push_back(a);

    }
    
    for (int i = 1; i <= 2 * N; i++) {
        if (!isECard[i]) {
            BCCards.push_back(i);
        }
    }
    
    sort(BCCards.begin(), BCCards.end());
    
    for (int i = 0; i < N; i++) {
        if (i < N / 2) {
            BCards2.insert(-BCCards[i]);
            cout << "B2 " << -BCCards[i] << endl;
        }
        else {
            BCards.insert(BCCards[i]);
            cout << "B " << BCCards[i] << endl;
        }
    }
    
    for (int i = 0; i < (N / 2); i++) {
        set<int>::iterator bcIND = BCards.lower_bound(ECards[i]);
        if (bcIND == BCards.end()) {
            BCards.erase(BCards.begin());
        }
        else {
            BCards.erase(bcIND);
            points++;
        }
        cout << ECards[i] << " " << *bcIND << endl;

    }
    
    
    for (int i = N / 2; i < N; i++) {
        set<int>::iterator bcIND = BCards2.lower_bound(-ECards[i]);
        if (bcIND == BCards2.end()) {
            BCards2.erase(BCards2.begin());
        }
        else {
            BCards2.erase(bcIND);
            points++;
        }
        cout << "ASD" << endl;
    }
    
    cout << BCards.size() << endl;
    
    cout << points << endl;
    out << points << endl;
    
    return 0;
}
