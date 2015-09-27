/*
 ID: dhruv.s2
 PROG: dualpal
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int N, S;

bool isPalindromic(int num) {
    ostringstream strm;
    strm << num;
    string number = strm.str();
    if (number == string(number.rbegin(), number.rend())) {
        return true;
    }
    return false;
}
bool isPalindromicStr(string number) {
    if (number == string(number.rbegin(), number.rend())) {
        return true;
    }
    return false;
}

string baseTenToBaseB(int convert, int B) {
    if (B == 10) {
        ostringstream strm;
        strm << convert;
        string str = strm.str();
        return str;
    }
    int cur = convert;
    int remainder = 0;
    char remChar;
    string remainders;
    while (cur > 0) {
        remainder = cur % B;
        ostringstream strm;
        strm << remainder;
        remChar = (strm.str())[0];
        remainders.push_back(remChar);
        cur /= B;
    }
    reverse(remainders.begin(), remainders.end());
    return remainders;
}

int main(int argc, const char * argv[]) {
    ifstream in("dualpal.in");
    ofstream out("dualpal.out");
    
    in >> N >> S;
    

    int outCount = 0;
    for (int i = S + 1; outCount < N; i++) {
        int numCasesPass = 0;
        for (int j = 2; j < 11; j++) {
            if (isPalindromicStr(baseTenToBaseB(i, j))) {
                numCasesPass++;
            }
            if (numCasesPass == 2) {
                cout << i << endl;
                out << i << endl;
                outCount++;
                break;
            }
        }
    }
    return 0;
}
