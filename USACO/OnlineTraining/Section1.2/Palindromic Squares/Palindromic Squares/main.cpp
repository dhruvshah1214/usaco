/*
 ID: dhruv.s2
 PROG: palsquare
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
int B;

char nth_letter(int n)
{
    if (n >= 1 && n <= 26) {
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n-1];
    }
    return ' ';
}

bool isPalindromic(string number) {
    if (number == string(number.rbegin(), number.rend())) {
        return true;
    }
    return false;
}

string baseTenToBaseB(long int convert) {
    long int cur = convert;
    int remainder = 0;
    char remChar;
    string remainders;
    while (cur > 0) {
        remainder = cur % B;
        if (remainder > 9) {
            remChar = nth_letter(remainder - 9);
        }
        else {
            ostringstream strm;
            strm << remainder;
            remChar = (strm.str())[0];
        }
        remainders.push_back(remChar);
        cur /= B;
    }
    reverse(remainders.begin(), remainders.end());
    return remainders;
}

int main(int argc, const char * argv[]) {
    ifstream in("palsquare.in");
    ofstream out("palsquare.out");

    in >> B;
    
    for (int i = 1; i < 301; i++) {
        long int iSquared = i * i;
        ostringstream strm;
        strm << baseTenToBaseB(iSquared);
        string numberStr = strm.str();
        if (isPalindromic(numberStr)) {
            cout << baseTenToBaseB(i) << " " << numberStr << endl;
            out << baseTenToBaseB(i) << " " << numberStr << endl;
        }
    }
    return 0;
}
