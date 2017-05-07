//
//  main.cpp
//  CowHurdles
//
//  Created by Dhruv Shah on 6/16/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>


#define INF 1 << 29


using namespace std;

long long N, M, T, mat[305][305];

int main(int argc, const char * argv[]) {
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            mat[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = c;
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (mat[i][k] < INF && mat[k][j] < INF) {
                    mat[i][j] = min(mat[i][j], max(mat[i][k], mat[k][j]));
                }
            }
        }
    }
    
    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        if (mat[a][b] == INF) {
            cout << "-1" << endl;
        }
        else {
            cout << mat[a][b] << endl;
        }
    }
    
    return 0;
}
