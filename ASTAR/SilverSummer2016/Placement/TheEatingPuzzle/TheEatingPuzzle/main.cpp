//
//  main.cpp
//  TheEatingPuzzle
//
//  Created by Dhruv Shah on 6/15/15.
//  Copyright (c) 2015 DhruvShah. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> sums(vector<int> numbers) {
    vector<int> sums;
    size_t count = numbers.size();
    vector<int> indexes(count);
    
    return sums;
}
void printIntVector (const vector<int>& v){
    //vector<int> v;
    for (int i = 0; i < (int)v.size();i++){
        cout << v[i] << endl;
    }
}
bool isSubsetSum(vector<int> set, size_t n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
    
    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum);
    
    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int main(int argc, const char * argv[]) {
    
    int C, B;
    cin >> C >> B;

    vector<int> set;
    int outputNumber = 0;
    for (int i = 0; i < B; i++) {
        int number;
        cin >> number;
        set.push_back(number);
    }
    for (int i = C; i > 0; i--) {
        if (isSubsetSum(set, set.size(), i) == true) {
            outputNumber = i;
            break;
        }
    }
    
    cout << outputNumber << endl;
}