/*
 ID: dhruv.s2
 PROG: transform
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






#define READY_FOR_SUBMIT 1

using namespace std;

string GetlineX(ifstream& file, unsigned int x){
    file.seekg(ios::beg);
    int i = 0;
    string line;
    while (i < x) {
        getline(file, line);
        i++;
    }
    return line;
}

int stringToInt(string string){
    return atoi(string.c_str());
}

void printIntVector (const vector<int>& v){
    //vector<int> v;
    for (int i = 0; i<v.size();i++){
        cout << v[i];
    }
}

void printTwoDIntVector (vector<vector<int>>& v){
    //vector<int> v;
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector<int>> check1Transformation(vector<vector<int>> original, vector<vector<int>> after, int N) {
    vector<vector<int>> afterTransformations;
    bool isTrue = false;
    for (int j = 0; j < N; j++) {
        vector<int> vertical;
        for (int i = N; i > 0; --i) {
            vertical.push_back(original[i - 1][j]);
        }
        /*
        cout << "N =" << N;
        cout << endl << endl << endl;
        printIntVector(vertical);
        cout << endl << endl << endl;
        // */
        afterTransformations.push_back(vertical);

    }
    if (std::equal(afterTransformations.begin(), afterTransformations.begin() + N, after.begin())) {
        isTrue = true;
    }
    return afterTransformations;
}

vector<vector<int>>  check2Transformation(vector<vector<int>> original, vector<vector<int>> after, int N) {
    vector<vector<int>> afterTransformations;
    bool isTrue = false;
    for (int j = N; j > 0; j--) {
        vector<int> row;
        for (int i = N; i > 0; --i) {
            row.push_back(original[j - 1][i - 1]);
        }
        afterTransformations.push_back(row);
        
    }
    if (std::equal(afterTransformations.begin(), afterTransformations.begin() + N, after.begin())) {
        isTrue = true;
    }
    return afterTransformations;
}

vector<vector<int>>  check3Transformation(vector<vector<int>> original, vector<vector<int>> after, int N) {
    vector<vector<int>> afterTransformations;
    bool isTrue = false;
    for (int j = N; j > 0; j--) {
        vector<int> vertical;
        for (int i = 0; i < N; i++) {
            vertical.push_back(original[i][j - 1]);
        }
        afterTransformations.push_back(vertical);
        
    }
    if (std::equal(afterTransformations.begin(), afterTransformations.begin() + N, after.begin())) {
        isTrue = true;
    }
    return afterTransformations;
}

vector<vector<int>>  check4Transformation(vector<vector<int>> original, vector<vector<int>> after, int N) {
    vector<vector<int>> afterTransformations;
    bool isTrue = false;
    for (int j = 0; j < N; j++) {
        vector<int> row;
        for (int i = N; i > 0; i--) {
            row.push_back(original[j][i - 1]);
        }
        afterTransformations.push_back(row);
        
    }
    if (std::equal(afterTransformations.begin(), afterTransformations.begin() + N, after.begin())) {
        isTrue = true;
    }
    return afterTransformations;
}

bool  check5Transformation(vector<vector<int>> original, vector<vector<int>> after, int N) {
    vector<vector<int>> afterTransformations;
    afterTransformations = check4Transformation(original, after, N);
    afterTransformations = check1Transformation(afterTransformations, after, N);
    if (std::equal(afterTransformations.begin(), afterTransformations.begin() + N, after.begin())) {
        return true;
    }
    afterTransformations = check2Transformation(afterTransformations, after, N);
    if (std::equal(afterTransformations.begin(), afterTransformations.begin() + N, after.begin())) {
        return true;
    }
    afterTransformations = check3Transformation(afterTransformations, after, N);
    if (std::equal(afterTransformations.begin(), afterTransformations.begin() + N, after.begin())) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[])
{
    ifstream in;
    ofstream out;
    if (READY_FOR_SUBMIT) {
        in.open ("transform.in");
        out.open ("transform.out");
        
    }
    else {
        in.open("/Users/hitesh/Documents/ProblemSolving/USACO/OnlineTraining/Section1.2/Transformation/Transformation/transform.in");
        out.open("/Users/hitesh/Documents/ProblemSolving/USACO/OnlineTraining/Section1.2/Transformation/Transformation/transform.out");
        
    }
    
    int N = stringToInt(GetlineX(in, 1));
    cout << N << endl;
    vector<vector<int>> originalSquare (N);
    vector<vector<int>> newSquare (N);
    
    // Get original square
    string line;
    cout << endl;
    for (int i = 0; i < N; i++) {
        getline(in, line);
        cout << line << endl;
        vector<int> lineVector(N);
        for (int j = 0; j < N; j++) {
            if (line[j] == '@') {
                lineVector[j] = 1;
            }
            else if (line[j] == '-') {
                lineVector[j] = 0;
            }
            else {
                cout << endl << "SOMETHING'S WRONG TERIIBLY" << endl;
                cout << line[j] << endl;
            }
        }
        originalSquare[i].resize(N);
        for (int j = 0; j < N; j++) {
            originalSquare[i][j] = lineVector[j];
        }
        if (i == N - 1) {
            break;
        }
    }
    cout << endl;
    // Get new square
    for (int i = 0; i < N; i++) {
        getline(in, line);
        cout << line << endl;
        vector<int> lineVector(N);
        for (int j = 0; j < N; j++) {
            if (line[j] == '@') {
                lineVector[j] = 1;
            }
            else if (line[j] == '-') {
                lineVector[j] = 0;
            }
            else {
                cout << endl << "SOMETHING'S WRONG TERIIBLY" << endl;
                cout << line[j] << endl;
            }
        }
        newSquare[i].resize(N);
        for (int j = 0; j < N; j++) {
            newSquare[i][j] = lineVector[j];
        }
        if (i == N - 1) {
            break;
        }
    }
    cout << endl << endl;
    printTwoDIntVector(originalSquare);
    cout << endl;
    printTwoDIntVector(newSquare);
    cout << endl << endl;

    string outputStr;
    
    if (std::equal(newSquare.begin(), newSquare.begin() + N, check1Transformation(originalSquare, newSquare, N).begin())) {
        cout << "#1 Transformation" << endl;
        outputStr = "1";
    }
    else if (std::equal(newSquare.begin(), newSquare.begin() + N, check2Transformation(originalSquare, newSquare, N).begin())) {
        cout << "#2 Transformation" << endl;
        outputStr = "2";
    }
    else if (std::equal(newSquare.begin(), newSquare.begin() + N, check3Transformation(originalSquare, newSquare, N).begin())) {
        cout << "#3 Transformation" << endl;
        outputStr = "3";
    }
    else if (std::equal(newSquare.begin(), newSquare.begin() + N, check4Transformation(originalSquare, newSquare, N).begin())) {
        cout << "#4 Transformation" << endl;
        outputStr = "4";
    }
    else if (check5Transformation(originalSquare, newSquare, N)) {
        cout << "#5 Transformation" << endl;
        outputStr = "5";
    }
    else if (std::equal(originalSquare.begin(), originalSquare.begin() + N, newSquare.begin())) {
        cout << "#6 Transformation" << endl;
        outputStr = "6";
    }
    else {
        cout << "#7 Transformation" << endl;
        outputStr = "7";
    }
    ostringstream stream;
    stream << outputStr << endl;
    string output = stream.str();
    out << output;
    cout << endl << endl << endl << output << endl << endl;
    
    return 0;
    
}


