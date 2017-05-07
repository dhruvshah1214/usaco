//
//  main.cpp
//  Total Flow
//
//  Created by Dhruv Shah on 6/17/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define INF 1 << 29

using namespace std;

int N, mat[805][805];

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            mat[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        if(a >= 'a' && a <= 'z')
            a += 'Z' + 1 - 'a';
        if(b >= 'a' && b <= 'z')
            b += 'Z' + 1 - 'a';
        mat[a - 'A'][b - 'A'] += c;
        mat[b - 'A'][a - 'A'] += c;
    }
    bool changed; //flag to tell us if the graph has changed this iteration
    do
    {
        changed = false;
        for(int i = 0 ; i < 52 ; i++)
            if(i != 0 && i != 25)
            {
                int first = -1;
                int second = -1;
                bool bad = false;
                for(int j = 0 ; j < 52 ; j++)
                {
                    if(mat[i][j] != 0)
                    {
                        if(first == -1)
                            first = j;
                        else if(second == -1)
                            second = j;
                        else
                            bad = true;
                    }
                }
                
                //bad is set if vertex i has more than three pipes connected to it
                if(bad)continue;
                if(second != -1)//use the first simplification rule
                {
                    mat[first][second] += min(mat[first][i], mat[i][second]);
                    mat[second][first] += min(mat[first][i], mat[i][second]);
                    mat[first][i] = 0;
                    mat[second][i] = 0;
                    mat[i][first] = 0;
                    mat[i][second] = 0;
                    
                    changed = true;
                }
                else if(first != -1)//use the third simplification rule
                {
                    mat[first][i] = mat[i][first] = 0;
                    changed = true;
                }
            }
    } while(changed);
    
    cout << mat[0]['Z' - 'A'] << endl;
    return 0;
}
