//
//  main.cpp
//  TallestCow
//
//  Created by Dhruv Shah on 6/14/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int N, I, H, R;
int see[10001][2];
int arr[10001];

int main(int argc, const char * argv[]) {
    cin >> N >> I >> H >> R;
    for (int i = 1; i <= R; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        see[i][0] = a, see[i][1] = b;
    }
    for (int i = 1; i <= N; i++) {
        arr[i] = H;
    }
    for (int l = 0; l < N; l++) {
        for (int i = 1; i <= R; i++) {
            if (abs(see[i][0] - see[i][1]) == 1) {
                continue;
            }
            if (see[i][0] < see[i][1]) {
                for (int j = see[i][0] + 1; j < see[i][1]; j++) {
                    if (arr[j] >= arr[see[i][0]] && j != I) {
                        arr[j] -= 1;
                    }
                }
            }
            else {
                for (int j = see[i][0] - 1; j > see[i][1]; j--) {
                    if (arr[j] >= arr[see[i][0]] && j != I) {
                        arr[j] -= 1;
                    }
                } 
            }
            
        }
    }
    
    for (int z = 1; z <= N; z++) {
        printf("%d\n", arr[z]);
    }
    
    return 0;
}
