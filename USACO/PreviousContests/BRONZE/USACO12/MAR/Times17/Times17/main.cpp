/*
 LANG: C++11
 TASK:
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

#define MAXINT 1 << 29


using namespace std;

string binN;
string final;  

int sq(int i) { return i * i; }


int main(int argc, const char * argv[]) {
    ifstream in("times17.in");
    ofstream out("times17.out");
    
    in >> binN;
    final = binN + "0000";
    bool carry = false;
    for (int i = (int)binN.length() - 1; i >= 0; i--) {
        if (final[i + 4] == '0' && binN[i] == '0') {
            if (carry) {
                final[i + 4] = '1';
            }
            carry = false;
        }
        if (final[i + 4] == '0' && binN[i] == '1') {
            if (carry) {
                final[i + 4] = '0';
                carry = true;
            }
            else {
                final[i + 4] = '1';
                carry = false;
            }
        }
        if (final[i + 4] == '1' && binN[i] == '0') {
            if (carry) {
                final[i + 4] = '0';
                carry = true;
            }
            else {
                final[i + 4] = '1';
                carry = false;
            }
        }
        if (final[i + 4] == '1' && binN[i] == '1') {
            if (carry) {
                final[i + 4] = '1';
            }
            else {
                final[i + 4] = '0';
            }
            carry = true;
        }
    }
    if (carry) {
        for (int i = 3; i >= 0; i--) {
            if (i == 0 && final[0] == '1') {
                final[0] = '0';
                final.insert(0, "1");
            }
            else {
                if (final[i] == '0') {
                    final[i] = '1';
                    break;
                }
                if (final[i] == '1') {
                    final[i] = '0';
                } 
            }
            
        }
    }
    cout << final << endl;
    out << final << endl;
    
    return 0;
}


