//
//  main.cpp
//  Forgotten Password
//
//  Created by Dhruv Shah on 6/23/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L, NW;
string dict[1005];
string P;
string chosen[1025];

int main(int argc, const char * argv[]) {
    cin >> L >> NW;
    cin >> P;
    for (int i = 0; i < NW; i++) {
        cin >> dict[i];
    }
    sort(dict, dict + NW);
    
    for (int i = L - 1; i >= 0; i--) {
        for (int j = 0; j < NW; j++) {
            long z = i + dict[j].length();
            if (z <= L && (z == L || (chosen[z] != ""))) {
                string curCom = dict[j];
                string oriComp = P.substr(i, curCom.length());
                
                int k;
                for (k = 0; k < curCom.length(); k++) {
                    if (curCom[k] == oriComp[k]) {
                        continue;
                    }
                    else if (oriComp[k] == '?') {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                if (k == curCom.length() && (chosen[i] == "" || chosen[i] > dict[j] + chosen[z])) {
                    chosen[i] = dict[j] + chosen[z];
                }
            }
            
            
        }
    }
    
    cout << chosen[0] << endl;
    return 0;
}
