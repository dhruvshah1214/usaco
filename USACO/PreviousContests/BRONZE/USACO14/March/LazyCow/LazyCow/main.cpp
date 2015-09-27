//
//  main.cpp
//  LazyCow
//
//  Created by Dhruv Shah on 7/21/15.
//  Copyright (c) 2015 DhruvShah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct patch {
    int gi, xi;
    patch(int a, int b) {
        gi = a;
        xi = b;
    }
    patch() {
        
    }
    
};

bool sortPos(const patch& p1, const patch& p2)
{
    return (p1.xi < p2.xi);
}
bool sortGrass(const patch& p1, const patch& p2)
{
    return (p1.gi < p2.gi);
}

int N, K, grasses[100000], grassesCount = 0, xs[100000];
patch patches[100000];

int binarySearch(int sortedArray[], int first, int last, int key) {
    // function:
    //   Searches sortedArray[first]..sortedArray[last] for key.
    // returns: index of the matching element if it finds key,
    //         otherwise  -(index where it could be inserted)-1.
    // parameters:
    //   sortedArray in  array of sorted (ascending) values.
    //   first, last in  lower and upper subscript bounds
    //   key         in  value to search for.
    // returns:
    //   index of key, or -insertion_position -1 if key is not
    //                 in the array. This value can easily be
    //                 transformed into the position to insert it.
    
    while (first <= last) {
        int mid = (first + last) / 2;  // compute mid point.
        if (key > sortedArray[mid])
            first = mid + 1;  // repeat search in top half.
        else if (key < sortedArray[mid])
            last = mid - 1; // repeat search in bottom half.
        else
            return mid;     // found it. return position /////
    }
    return -(first + 1);    // failed to find key
}

int main(int argc, const char * argv[]) {
    ifstream in("lazy.in");
    ofstream out("lazy.out");
    
    in >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b;
        in >> a >> b;
        patches[i] = patch(a, b);
        xs[i] = b;
    }
    std::sort(patches, patches + N, sortPos);
    std::sort(xs, xs + N);
    
    int maxX = patches[N - 1].xi;
    int minX = patches[0].xi;

    for (int i = minX; i <= maxX; i++) {
        int grassEdible = 0;
        int minRange = i - K;
        if (minRange < 1) {
            minRange = 1;
        }
        int maxRange = i + K;
        for (int j = minRange; j <= maxRange; j++) {
            int indx = binarySearch(xs, 0, N, j);
            if (indx > -1) {
                cout << patches[indx].gi << endl;
                grassEdible += patches[indx].gi;
            }
        }
        grasses[grassesCount] = grassEdible;
        grassesCount++;

    }
    std::sort(grasses, grasses + grassesCount, greater<int>());
    cout << endl << grasses[0] << endl;
    out << grasses[0] << endl;

    return 0;
}

