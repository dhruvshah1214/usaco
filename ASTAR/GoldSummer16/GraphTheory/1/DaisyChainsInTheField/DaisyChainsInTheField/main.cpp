//
//  main.cpp
//  DaisyChainsInTheField
//
//  Created by Dhruv Shah on 6/15/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>

using namespace std;

int N, M, mat[251][251];

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (mat[j][i] == 1) {
                for (int z = 1; z <= N; z++) {
                    if (mat[i][z] == 1) {
                        mat[j][z] = 1; 
                    }
                }
            }
        }
    }
    
    int c = 0;
    for (int i = 2; i <= N; i++) {
        if (mat[1][i] == 0) {
            cout << i << endl;
            c++;
        }
    }
    if (c == 0) {
        cout << "0" << endl;
    }
    return 0;
}
