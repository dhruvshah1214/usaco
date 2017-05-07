/*
 PROG: preface
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, ct10[5], ct5[4];
char t[4] = {'I', 'X', 'C', 'M'}, f[3] = {'V', 'L', 'D'};

/*
 CT10
 0...I
 1...X
 2...C
 3...M
 */

/*
 CT5
 0...V
 1...L
 2...D
 */

void roman(int dec) {
    int i, cur = 0;
    while (dec != cur) {
        for (i = 0; i <= 4; i++) {
            if (pow(10, i) > dec - cur) {
                i--;
                break;
            }
        }
        if ((dec - cur) / (int)pow(10, i) < 4) {
            ct10[i] += ((dec - cur) / (int)pow(10, i));
            cur += ((dec - cur) / (int)pow(10, i)) * (int)pow(10, i);
        }
        else if((dec - cur) / (int)pow(10, i) == 4) {
            ct10[i]++;
            ct5[i]++;
            cur += 4 * (int)pow(10, i);
        }
        else if((dec - cur) / (int)pow(10, i) == 9) {
            ct10[i]++;
            ct10[i + 1]++;
            cur += 9 * (int)pow(10, i);
        }
        else if((dec - cur) / pow(10, i) == 5){
            ct5[i]++;
            cur += 5 * (int)pow(10, i);
        }
        else {
            ct5[i]++;
            cur += 5 * (int)pow(10, i);
            ct10[i] += ((dec - cur) / (int)pow(10, i));
            cur += ((dec - cur) / (int)pow(10, i)) * (int)pow(10, i);
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream in("preface.in");
    ofstream out("preface.out");

    in >> N;
    
    
    for (int i = 1; i <= N; i++) {
        roman(i);
    }
    
    for (int i = 0; i < 4; i++) {
        if (ct10[i] == 0) {
            break;
        }
        cout << t[i] << " " << ct10[i] << endl;
        out << t[i] << " " << ct10[i] << endl;
        if (i == 3) {
            break;
        }
        if (ct5[i] == 0) {
            break;
        }
        cout << f[i] << " " << ct5[i] << endl;
        out << f[i] << " " << ct5[i] << endl;
    }
    
    
    return 0;
}
