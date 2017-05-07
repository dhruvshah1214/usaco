//
//  main.cpp
//  Mooo
//
//  Created by Dhruv Shah on 6/21/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, h[50001], v[50001], moo[50001], nextright[50001], nextleft[50001];
int main(int argc, const char * argv[]) {
    cin >> N;
    memset(nextleft, -1, sizeof(nextleft));
    memset(nextright, -1, sizeof(nextright));

    for (int i = 0; i < N; i++) {
        cin >> h[i] >> v[i];
    }
    for (int i = 0; i < N; i++) {
        if (i - 1 >= 0 && nextright[i - 1] != -1) {
            if (h[nextright[i - 1]] > h[i]) {
                nextright[i] = nextright[i - 1];
                moo[nextright[i - 1]] += v[i];
            }
            else {
                for (int j = i + 1; j < N; j++) {
                    if (h[j] > h[i]) {
                        nextright[i] = j;
                        moo[j] += v[i];
                        break;
                    }
                }  
            }
        }
        else {
            for (int j = i + 1; j < N; j++) {
                if (h[j] > h[i]) {
                    nextright[i] = j;
                    moo[j] += v[i];
                    break;
                }
            }  
        }
        
        if (i - 1 >= 0 && nextleft[i - 1] != -1) {
            if (h[nextleft[i - 1]] > h[i]) {
                nextleft[i] = nextleft[i - 1];
                moo[nextleft[i - 1]] += v[i];
            }
            else {
                for (int j = i - 1; j >= 0; j--) {
                    if (h[j] > h[i]) {
                        nextleft[i] = j;
                        moo[j] += v[i];
                        break;
                    }
                }  
            }
        }
        else {
            for (int j = i - 1; j >= 0; j--) {
                if (h[j] > h[i]) {
                    nextleft[i] = j;
                    moo[j] += v[i];
                    break;
                }
            } 
            
        }
    }
    int m = 0;
    for (int i = 0; i < N; i++) {
        m = max(m, moo[i]);
    }
    
    cout << m << endl;
    
    return 0;
}
