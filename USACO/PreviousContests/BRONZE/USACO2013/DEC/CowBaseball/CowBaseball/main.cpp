//
//  main.cpp
//  CowBaseball
//
//  Created by Dhruv Shah on 8/5/15.
//  Copyright (c) 2015 DhruvShah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int N;
long cows[1001];
int numberTriples = 0;

void rec(long numbers[], int numS, int firstNumIndex) {
    if (numS == 3) {
        numberTriples++;
        return;
    }
    for (int i = firstNumIndex + 1; i < N; i++) {
        if (numS == 1) {
            long* arr = numbers;
            arr[1] = cows[i];
            rec(arr, numS + 1, i);
        }
        if (numS == 2) {
            long* arr = numbers;
            long r1 = numbers[1] - numbers[0];
            long r2 = r1 * 2;
            if (r1 <= cows[i] - numbers[1] && cows[i] - numbers[1] <= r2) {
                arr[2] = cows[i];
                rec(arr, numS + 1, i);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream in("baseball.in");
    
    in >> N;
    for (int i = 0; i < N; i++) {
        long number;
        in >> number;
        cows[i] = number;
    }
    sort(cows, cows + N);
    
    for (int i = 0; i < N; i++) {
        long firstNum[1] = {cows[i]};
        rec(firstNum, 1, i);
    }
    
    int answer = numberTriples;
    cout << answer << endl;
    ofstream out("baseball.out");
    out << answer << endl;

    return 0;
}
