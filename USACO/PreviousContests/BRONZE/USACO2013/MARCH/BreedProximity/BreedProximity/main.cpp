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





#define READY_FOR_SUBMIT 1

using namespace std;

void output(string outputString);
ifstream in;
ofstream out;
vector<int> allProximities;

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

void repeating(vector<int> arr, size_t size)
{
    int *count = (int *)calloc(sizeof(size_t), (size - 2));
    int i;
    
    printf(" Repeating elements are ");
    for(i = 0; i < size; i++)
    {
        if(count[arr[i]] == 1) {
            printf(" %d ", arr[i]);
            allProximities.push_back(arr[i]);
        }
        else
            count[arr[i]]++;
    }
    
}

int main(int argc, const char * argv[])
{
    
    if (READY_FOR_SUBMIT) {
        in.open ("proximity.in");
        out.open ("proximity.out");
        
    }
    else {
        in.open("/Users/hitesh/Documents/ProblemSolving/USACO/PreviousContests/BRONZE/USACO2013/MARCH/BreedProximity/BreedProximity/proximity.in");
        
    }
    int N = stringToInt(getWords(GetlineX(in, 1), 2)[0]);
    int K = stringToInt(getWords(GetlineX(in, 1), 2)[1]);
    vector<int> breed_ids(N);

    string line;
    for (int lineNumber = 0; getline(in, line); lineNumber++) {
        if (lineNumber != 0) {
            breed_ids.at(lineNumber - 1) = stringToInt(line);
        }
    }
    
        for (int i = 0; i < N; i++) {
        }
     // */
    cout << endl;
    // printVector(breed_ids);
    cout << endl;
    int curr_BreedId = 0;
    
    for (int i = 0; i < N; i++) {
        curr_BreedId = breed_ids[i];
        if (allProximities.size() != 0) {
            if (curr_BreedId < allProximities.back()) {
                continue;
            }
        }
        
        cout << "CURRBRID: " << curr_BreedId << " i " << i << endl;
        size_t index;
        if (i != N - 2) {
            index = std::find(breed_ids.begin() + i + 1, breed_ids.end(), curr_BreedId) - breed_ids.begin();
        }
        else {
            if (breed_ids[N - 2] == breed_ids[N - 1]) {
                index = breed_ids[N - 1];
            }
        }
        cout << "INDEX: " << index << endl;
        if (index < breed_ids.size()) {
            if ((index - i) <= K) {
                    allProximities.push_back(curr_BreedId);
            }
        }
        sort(allProximities.begin(), allProximities.end());
    }
    
    sort(allProximities.begin(), allProximities.end());
    cout << endl;
    if (!READY_FOR_SUBMIT) {
        printVector(allProximities);
    }
    if (allProximities.size() == 0) {
        cout << endl << endl << -1 << endl << endl;
        output(to_string(-1));
    }
    else {
        cout << endl << endl << allProximities.back() << endl;
        output(to_string(allProximities.back()));
    }
    return 0;
    
}

void output(string outputString){
    ostringstream stream;
    stream << outputString;
    string output = stream.str();
    out << output;
}




