//
//  main.cpp
//  CountingHaybales
//
//  Created by Dhruv Shah on 12/17/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
vector<int> pos;

int main(int argc, const char * argv[]) {
    ifstream in("haybales.in");
    ofstream out("haybales.out");
    
    bool debug = false;
    
    if (debug) {
        cin >> N >> Q;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            pos.push_back(a);
        }
    }
    else {
        in >> N >> Q;
        for (int i = 0; i < N; i++) {
            int a;
            in >> a;
            pos.push_back(a);
        }
    }
    
    sort(pos.begin(), pos.end());
    
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << pos[i] << " ";
    }
    cout << endl;
    
    cout << pos.end() - pos.begin() << endl;
    
    for (int i = 0; i < Q; i++) {
        int a1, a2;
        if (debug) {
            cin >> a1 >> a2;
        }
        else {
            in >> a1 >> a2;
        }
        
        int num1 = (int)(lower_bound(pos.begin(), pos.end(), a1) - pos.begin());
        
        int num2 = (int)(lower_bound(pos.begin(), pos.end(), a2) - pos.begin());
        
        
        while (pos[num2] > a2 || num2 == N) {
            num2--;
        }
           
        /*
        cout << a1 << " " << a2 << endl;
        cout << num1 << " " << num2 << endl;
        // */
        
        int ans = (num2 - num1) + 1;
        if (num1 >= N) {
            ans = 0;
        }
        if (num2 < 0) {
            ans = 0;
        }
         
        
        cout << ans << endl;
        out << ans << endl;
        //  */

    }
    
    
    
    return 0;
}
