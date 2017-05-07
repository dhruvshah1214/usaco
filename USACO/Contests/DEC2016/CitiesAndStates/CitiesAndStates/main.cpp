//
//  main.cpp
//  CitiesAndStates
//
//  Created by Dhruv Shah on 12/17/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int N;
map<string, int> m;

int ans = 0;

string rev(string i) {
    return i.substr(2, 2) + i.substr(0, 2);
}

int main(int argc, const char * argv[]) {
    ifstream in("citystate.in");
    ofstream out("citystate.out");
    
    in >> N;
    
    for (int i = 0; i < N; i++) {
        string a, b;
        
        in >> a >> b;
        
        if (a.substr(0, 2) != b.substr(0, 2)) {
            m[a.substr(0, 2) + b.substr(0, 2)];
            m[rev(a.substr(0, 2) + b.substr(0, 2))];
            m[a.substr(0, 2) + b.substr(0, 2)]++;
        }
        
    }
    
    
    for (std::map<string,int>::iterator it=m.begin(); it!=m.end(); it++) {
        //cout << it->first << " " << it->second << " " << m[rev(it-> first)] << endl;
        if(it->second > 0)
            ans += (it->second * m[rev(it->first)]);
    }
    
    cout << ans/2 << endl;
    out << ans/2 << endl;
    
    
    return 0;
}

/*
 6
 AB AA
 AA AC
 AA AB
 AA AB
 AB AA
 AB AC
 */
