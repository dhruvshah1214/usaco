//
//  main.cpp
//  FIBB
//
//  Created by Dhruv Shah on 7/15/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;


int fibb(int n) {
    if (n <= 2) {
        return 1;
    }
    int f1 = 1, f2 = 1, nf = 2;
    for (int i = 3; i <= n; i++) {
        // cout << f1 << " " << f2 << endl;
        nf = f1 + f2;
        f1 = f2;
        f2 = nf;
    }
    return nf;
}

int main(int argc, const char * argv[]) {
    cout << fibb(6) << endl;
    return 0;
}
