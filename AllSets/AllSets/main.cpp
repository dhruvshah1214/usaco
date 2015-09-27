//
//  main.cpp
//  AllSets
//
//  Created by Dhruv Shah on 6/18/15.
//  Copyright (c) 2015 DhruvShah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int M;
vector<int> digits;
ofstream out("setall.out");

void sets(int current, int N) {
    if(N == 0) {
        cout << current << endl;
        out << current << endl;
    }
    else    {
        for(int i = 0; i < digits.size(); i++) {
            sets(current * 10 + digits[i], N - 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream in("setall.in");
    in >> M;
    for (int i = 0; i < M; i++) {
        int number;
        in >> number;
        digits.push_back(number);
    }
    sets(0, 5);
    

}
