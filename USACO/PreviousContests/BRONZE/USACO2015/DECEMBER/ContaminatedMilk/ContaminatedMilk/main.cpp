//
//  main.cpp
//  ContaminatedMilk
//
//  Created by Dhruv Shah on 12/14/15.
//  Copyright © 2015 USACO. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, D, S;
int maxPotDis = 0;

pair<int, pair<int, int> > info[1001];
pair<int, int > sick[51];

int main(int argc, const char * argv[]) {
    ifstream in("badmilk.in");
    ofstream out("badmilk.out");
    
    in >> N >> M >> D >> S;
    
    for (int i = 0; i < D; i++) {
        in >> info[i].first >> info[i].second.first >> info[i].second.second;
    }
    for (int i = 0; i < S; i++) {
        in >> sick[i].first >> sick[i].second;
    }
    
    for (int i = 1; i <= M; i++) {
        int j;
        for (j = 0; j < S; j++) {
            int sickN = sick[j].first;
            int sickT = sick[j].second;
            bool safedoubleBreak = false;
            for (int z = 0; z < D; z++) {
                if (info[z].first == sickN && info[z].second.first == i) {
                    if (info[z].second.second < sickT) {
                        safedoubleBreak = true;
                    }
                }
            }
            if (safedoubleBreak == false) {
                break;
            }
        }
        
        if (j >= S) {
            int potentialDis = 0;
            bool personCounted[55];
            for (int z = 0; z < 55; z++) {
                personCounted[z] = 0;
            }
            for (int y = 0; y < D; y++) {
                if (info[y].second.first == i) {
                    personCounted[info[y].first] = true;
                }
            }
            for (int z = 1; z <= N; z++) {
                if (personCounted[z]) {
                    potentialDis++;
                }
            }
            maxPotDis = max(maxPotDis, potentialDis);
        }
    }
    
    out << maxPotDis << endl;
    
    return 0;
}
