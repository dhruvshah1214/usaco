/*
 ID: dhruv.s2
 PROG: crypt1
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, digits[10000];

bool val(int num) {
    string numStr = to_string(num);
    int numDigitsValid = 0;
    for (int i = 0; i < numStr.size(); i++) {
        for (int j = 0; j < N; j++) {
            // cout << numStr[i] - '0' << endl;
            if (numStr[i] - '0' == digits[j]) {
                numDigitsValid++;
                break;
            }
        }
    }
    // cout  << (numDigitsValid == numStr.size()) << endl;
    return (numDigitsValid == numStr.size());
}

int calcSolution() {
    int count = 0;
    for (int A = 0; A < N; A++) {
        for (int B = 0; B < N; B++) {
            for (int C = 0; C < N; C++) {
                for (int D = 0; D < N; D++) {
                    for (int E = 0; E < N; E++) {
                        int ABC = 100 * digits[A] + 10 * digits[B] + digits[C];
                        int DE = 10 * digits[D] + digits[E];
                        if (val(ABC*digits[D]) && val(ABC*digits[E]) && val(ABC*DE) && to_string(ABC * DE).length() == 4 && to_string(ABC*digits[D]).length() == to_string(ABC*digits[E]).length() && to_string(ABC*digits[D]).length() == 3) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    ifstream in("crypt1.in");
    ofstream out("crypt1.out");
    
    in >> N;
    cout << "N: " << N << endl << endl;
    for (int i = 0; i < N; i++) {
        in >> digits[i];
    }
    int answer = calcSolution();
    cout << endl << answer << endl;
    out << answer << endl;
    
    return 0;
}
