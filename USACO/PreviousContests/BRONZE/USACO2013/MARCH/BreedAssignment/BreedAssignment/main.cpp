/*
 ID: dhruv.s2
 PROG: proximity
 LANG: C++11
 */

#include <algorithm>
#include <bitset>
#include <limits>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <stdio.h>





#define READY_FOR_SUBMIT 0

using namespace std;

void output(string outputString);
ifstream in;
ofstream out;
vector<int> finalVector;


string GetlineX(ifstream& file, unsigned int x){
    file.seekg(ios::beg);
    int i = 0;
    string line;
    while (i < x) {
        getline(file, line);
        i++;
    }
    file.seekg(ios::beg);
    return line;
}

vector<string> getWords(string line, int noOfWords){
    stringstream ss(line);
    string word;
    
    vector<string> words;
    
    for (int i = 0; i < noOfWords; i++)
    {
        ss >> word;
        words.push_back(word);
    }
    return words;
}
void printVector(vector<int> vector){
    for (size_t i = 0; i < vector.size(); i ++) {
        cout << vector[i] << endl;
    }
}

int stringToInt(string string){
    return atoi(string.c_str());
}

vector<int> checkDuplicates( vector<int> array, size_t n)
{
    std::sort(array.begin(), array.begin() + n);
    int i;
    for( i = 0; i < n-1; i++)
    {
        if(array[i] == array[i+1] ) {
            return {array[i], array[i+1]};
        }
    }
    return {};
}

int main(int argc, const char * argv[])
{
    
    if (READY_FOR_SUBMIT) {
        in.open ("assign.in");
        out.open ("assign.out");
        
    }
    else {
        in.open("/Users/hitesh/Documents/ProblemSolving/USACO/PreviousContests/BRONZE/USACO2013/MARCH/BreedAssignment/BreedAssignment/assign.in");
        
    }
    int N = stringToInt(getWords(GetlineX(in, 1), 2)[0]);
    int K = stringToInt(getWords(GetlineX(in, 1), 2)[1]);
    int A = 1;
    finalVector.resize(N);

    string line;
    for (int lineNumber = 0; getline(in, line); lineNumber++) {
        if (lineNumber != 0) {
            cout << line << endl;
            bool same = ((line.at(0) == 'S') ? true : false);
            if (same) {
                int firstNumber = stringToInt((getWords(line, 3))[1]);
                int secondNumber = stringToInt((getWords(line, 3))[2]);
                finalVector.at(firstNumber - 1) = A;
                finalVector.at(secondNumber - 1) = A;
                A++;
            }
            else {
                int firstNumber = stringToInt((getWords(line, 3))[1]);
                int secondNumber = stringToInt((getWords(line, 3))[2]);
                if (finalVector.at(firstNumber - 1) != 0) {
                    finalVector.at(secondNumber - 1) = A;
                    A++;
                }
                else {
                    finalVector.at(firstNumber - 1) = A;
                    A++;
                    finalVector.at(secondNumber - 1) = A;
                    A++;
                }
            }
        }
    }
    if (!READY_FOR_SUBMIT) {
        cout << endl << endl;
        printVector(finalVector);
    }
    sort(finalVector.begin(), finalVector.end());

    int finalAns = 1;
    int B = finalVector[0];
    int C = 3;
    for (int i = 0; i < N; i++) {
        if (finalVector.at(i) == B) {
            finalAns *= C;
            B++;
            C--;
        }
        else if (finalVector.at(i) == 0) {
            finalAns *= 3;
        }
    }
    cout << endl << endl << endl << finalAns << endl << endl;
   
    if (finalVector.size() == 0) {
        cout << endl << endl << -1 << endl << endl;
        output(to_string(-1));
    }
    else {
        output(to_string(finalAns));
    }
    return 0;
    
}

void output(string outputString){
    ostringstream stream;
    stream << outputString;
    string output = stream.str();
    out << output;
}




