/*
 ID: dhruv.s2
 PROG: milk
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct farmerMilk {
    int cost, maxSell;
    farmerMilk(int a, int b) {
        cost = a;
        maxSell = b;
    }
    farmerMilk() {
        
    }
};

bool costSort (farmerMilk m1, farmerMilk m2) {
    return (m1.cost < m2.cost);
}

bool maxSort (farmerMilk m1, farmerMilk m2) {
    return (m1.maxSell < m2.maxSell);
}

int N, M;
farmerMilk milks[5000];

int main(int argc, const char * argv[]) {
    ifstream in("milk.in");
    ofstream out("milk.out");
    
    in >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        in >> a >> b;
        milks[i] = farmerMilk(a, b);
    }
    
    sort(milks, milks + M, costSort);
    
    int milkSum = 0;
    int curCost = 0;

    for (int i = 0; i < M; i++) {
        farmerMilk curFarmer = milks[i];
        if (milkSum + curFarmer.maxSell <= N) {
            milkSum += curFarmer.maxSell;
            curCost += curFarmer.cost * curFarmer.maxSell;
        }
        else {
            int sub = N - milkSum;
            curCost += curFarmer.cost * sub;
            break;
        }
    }
    
    cout << curCost << endl;
    out << curCost << endl;
    
    return 0;
}
