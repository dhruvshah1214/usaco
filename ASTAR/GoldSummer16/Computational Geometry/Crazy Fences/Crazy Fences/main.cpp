//
//  main.cpp
//  Crazy Fences
//
//  Created by Dhruv Shah on 6/30/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

struct vec {
    long long x, y;
    vec() {
        
    }
    vec(long long a, long long b) {
        x = a, y = b;
    }
    vec operator+(vec b) const {
        vec ans;
        ans.x = x + b.x;
        ans.y = y + b.y;
        return ans;
    }
    vec operator-(vec b) const {
        vec ans = vec(x - b.x, y - b.y);
        return ans;
    }
    long long operator*(vec b) const {
        return (x * b.y) - (y * b.x);
    }
    bool operator==(vec b) const {
        return ((x == b.x) && (y == b.y));
    }
    bool operator<(vec b) const {
        if(x == b.x) {
            return y < b.y;
        }
        return x < b.x;
    }
};

struct line {
    vec a, b;
    line(long long w, long long x, long long y, long long z) {
        a = vec(w, x);
        b = vec(y, z);
    }
    line(vec v1, vec v2) {
        a = v1;
        b = v2;
    }
    line() {
        
    }
    bool interU(line linea, line lineb) {
        vec lb = lineb.b - lineb.a;
        long long res1 = (lb * (linea.a - lineb.a));
        long long res2 = (lb * (linea.b - lineb.a));
        return (res1 * res2) < 0;
    }
    bool inter(line lineb) {
        return (interU(*this, lineb) && interU(lineb, *this));
    }
};

bool insPoly2(vec P, vector<line> poly) {
    long long cnt = 0;
    for (int i = 0; i < poly.size(); i++) {    // edge poly[i]
        if (((poly[i].a.y <= P.y) && (poly[i].b.y > P.y))     // an upward crossing
            || ((poly[i].a.y > P.y) && (poly[i].b.y <=  P.y))) { // a downward crossing
            // compute  the actual edge-ray intersect x-coordinate
            long double vt = (long double)(P.y  - poly[i].a.y) / (poly[i].b.y - poly[i].a.y);
            if (P.x <  poly[i].a.x + vt * (poly[i].b.x - poly[i].a.x)) // P.x < intersect
                ++cnt;   // a valid crossing of y=P.y right of P.x
        }
    }
    return ((cnt % 2) == 1);
}
/*
bool insidePolygon(vec l, vector<line> polygon) {
    long long n = 0;
    for(long long i = 0; i < (long long)polygon.size(); i++) {
        line v = polygon[i];
        if(line(l, vec(-1, -1)).inter(v)) {
            n++;
        }
    }
    return ((n % 2) == 1);
}
*/


long long N, C;
map<vec, vector<vec> > m;
pair<long long, long long> cowloc[1005];

long long polyN = 1;
vector<line> poly[2000];

vector<long long> cow[1005];
string cowSortVals[1005];


set<vec> visited;

string toStr(long long i) {
    stringstream ss;
    ss << i << " ";
    string str = ss.str();
    return str;
}


string cowvalia(vector<long long> v1) {
    string s;
    for (int i = 0; i < v1.size(); i++) {
        s.append(toStr(v1[i]));
    }
    return s;
}

int polysc = 0;

void dfs(vec v, long long polyn, vec start) {
    bool found = 0;
    vec n;
    visited.insert(v);
    
    for (int i = 0; i < m[v].size(); i++) {
        n = m[v][i];
        if (visited.count(n)) {
            continue;
        }
        poly[polyn].push_back(line(v, n));
        polysc++;
        found = 1;
        // cout << "PUSH BACK " << v.x << " " << v.y << " - " << n.x << " " << n.y << endl;
        dfs(n, polyn, start);
        // cout << "DONE" << endl;
    }
    if (!found) {
        poly[polyn].push_back(line(v, start));
        polysc++;
        // cout << "PUSH BACK " << v.x << " " << v.y << " - " << start.x << " " << start.y << endl;
        return;
    }
}
 // */

int main() {
    //freopen("5.in", "r", stdin);
    //freopen("crazy.out", "w", stdout);
    

    scanf("%lld %lld", &N, &C);
    
    for (long long i = 0; i < N; i++) {
        long long a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        vec va = vec(a, b);
        vec vb = vec(c, d);
        m[va].push_back(vb);
        m[vb].push_back(va);

    }
    
    
    for (long long i = 0; i < C; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        cowloc[i].first = a,  cowloc[i].second = b;
    }
    
    
    for (map<vec, vector<vec> >::iterator it = m.begin(); it != m.end(); it++) {
        vec v = (it -> first);
        if (!visited.count(v)) {
            polysc = 0;
            dfs(v, polyN, v);
            if (polysc >= 3) {
                polyN++;
            }
            else {
                poly[polyN].clear();
            }
        }
    }
    polyN--;
    
    
    for (long long j = 1; j <= polyN; j++) {
        // cout << "POLYGON " << j << endl;
        for (int i = 0; i < poly[j].size(); i++) {
            //cout << poly[j][i].a.x << " " << poly[j][i].a.y << " - " << poly[j][i].b.x << " " << poly[j][i].b.y << endl;
        }
    }
    // */
    
    
    for (long long i = 0; i < C; i++) {
        
         //cout << "Cow " << i << " IS IN POLY ";
        
        for (long long j = 1; j <= polyN; j++) {
            if (insPoly2(vec(cowloc[i].first, cowloc[i].second), poly[j])) {
                
                 //cout << j << " ";
                
                
                cow[i].push_back((int)j);
            }
        }
        if (cow[i].size() == 0) {
            cow[i].push_back(0);
        }
        
        //cout << endl;
        
    }
    
    for (long long i = 0; i < C; i++) {
        vector<long long> vv = cow[i];
        cowSortVals[i] = cowvalia(vv);
        
    }
    
    sort(cowSortVals, cowSortVals + C);
    
    long long cur = 1;
    long long longest = 0;
    for (long long i = 1; i < C; i++) {
        if (cowSortVals[i] == cowSortVals[i - 1]) {
            cur++;
        }
        else {
            longest = max(longest, cur);
            // cout << endl << endl << cur << endl << longest << endl << endl;
            cur = 1;
        }
        // cout << cowSortVals[i] << endl;
    }
    
    printf("%lld\n", max(longest, cur));

    // */
        
    return 0;
}
