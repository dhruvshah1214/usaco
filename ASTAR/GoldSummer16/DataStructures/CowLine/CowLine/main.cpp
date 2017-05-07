//
//  main.cpp
//  CowLine
//
//  Created by Dhruv Shah on 6/14/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int S, arr[200001], Li = 99999, Ri = 100000;

int main(int argc, const char * argv[]) {
    cin >> S;
    int insertNum = 1;
    for (int i = 0; i < S; i++) {
        char t, s;
        int k;
        cin >> t >> s;
        if (t == 'D') {
            cin >> k;
            // remove k from side s
            switch (s) {
                case 'R':
                    for (int j = Ri - 1; j > (Ri - 1) - k; j--) {
                        arr[j] = 0;
                    }
                    Ri = Ri - k;
                    break;
                case 'L':
                    for (int j = Li + 1; j < (Li + 1) + k; j++) {
                        arr[j] = 0;
                    }
                    Li = Li + k;
                    break;
                default:
                    break;
            }
        }
        else if (t == 'A') {
            if (s == 'L') {
                arr[Li] = insertNum;
                insertNum++, Li--;
            }
            else {
                arr[Ri] = insertNum;
                insertNum++, Ri++;
            }
        }
    }
    for (int i = Li + 1; i < Ri; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
