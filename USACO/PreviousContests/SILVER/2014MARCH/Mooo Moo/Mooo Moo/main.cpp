//
//  main.cpp
//  Mooo Moo
//
//  Created by Dhruv Shah on 10/30/15.
//  Copyright © 2015 USACO. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, B, V[21], F[101], C[101];

int solve() {
    for (int i = 0; i < N; i++) {
        int maxVol = F[i];
        int cVol = C[i];
        int volI = 0;
        while (cVol < maxVol) {
            cVol += V[volI];
            if (cVol > maxVol) {
                cVol -= V[volI];
                volI++;
            }
            if (volI == B && cVol != maxVol) {
                return -1;
            }
        }
        
    }
    return 0;
}


bool breedSort(int a, int b) {
    return a > b;
}

int main(int argc, const char * argv[]) {
    ifstream in("mooomoo.in");
    ofstream out("mooomoo.out");
    
    in >> N >> B;
    for (int i = 0; i < B; i++) {
        in >> V[i];
    }
    for (int i = 0; i < N; i++) {
        in >> F[i];
        C[i] = 0;
    }
    sort(V, V + B, breedSort);
    
    return 0;
}
