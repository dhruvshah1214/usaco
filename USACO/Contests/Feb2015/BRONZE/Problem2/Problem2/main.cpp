

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
vector<vector<string>> grid = {{"R", "R", "R", "R"}, {"R", "R", "B", "R"}, {"R", "B", "B", "R"}, {"R", "R", "R", "R"}};


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
int countPaths(int x, int y) {
    if(x == grid.size() - 1 && y == grid[x].size() -1) {
        /* We arrived at the destination. */
        return 1;
    }
    
    /* Otherwise try all valid next moves and sum the total number of paths. */
    int ret = 0;
    for(int i = x+1; i < grid.size(); i++) {
        for(int j = y + 1; j < grid[i].size(); j++) {
            cout << "IJ: (" << i << ", " << j << ")   XY: (" << x << ", " << y << ")" << endl;
            if(grid[i][j] != grid[x][y]) {
                ret += countPaths(i, j);
            }
        }
    }
    cout << endl;
    return ret;
}


int main(int argc, const char * argv[])
{
    /*
       ifstream in;
    ofstream out;

    if (READY_FOR_SUBMIT) {
        in.open ("cow.in");
        out.open ("cow.out");
    }
    else {
        in.open("/Users/hitesh/Documents/ProblemSolving/USACO/Contests/Feb2015/BRONZE/Problem2/Problem2/p2.in");
        out.open("/Users/hitesh/Documents/ProblemSolving/USACO/Contests/Feb2015/BRONZE/Problem2/Problem2/p2.out");
        
    }
    int N;
    string S;
    in >> N >> S;
    
    long long NC = 0;
    long long NO = 0;
    long long NW = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'C') {
            NC++;
        } else if (S[i] == 'O') {
            NO += NC;
        } else if (S[i] == 'W') {
            NW += NO;
        }
    }
    
    cout << NW << endl;
    if (READY_FOR_SUBMIT) {
        out << to_string(NW);
    }
    
    
    return 0;
     */
    
        
    size_t r, c;
    r = grid.size();
    c = grid[0].size();
    
        
    /* Compute the answer! */
    
    cout << countPaths(0, 0) << endl;
    

    
}





