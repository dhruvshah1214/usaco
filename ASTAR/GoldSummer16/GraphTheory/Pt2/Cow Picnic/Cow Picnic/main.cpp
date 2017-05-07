//
//  main.cpp
//  Cow Picnic
//
//  Created by Dhruv Shah on 6/27/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int K, N, M;
vector<int> mat[1005];
int starting[101];
int reachable[1005];
bool visited[1005];

void rec(int start) {
    int cur = start;
    reachable[cur]++;
    visited[cur] = true;
    for (int i = 0; i < (int)mat[cur].size(); i++) {
        int dest = mat[cur][i];
        if (!visited[dest]) {
            rec(dest);
            
        }
    }
}


int main(int argc, const char * argv[]) {
    cin >> K >> N >> M;
    for (int i = 0; i < K; i++) {
        cin >> starting[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
    }
    for (int i = 0; i < K; i++) {
        rec(starting[i]);
        memset(visited, 0, sizeof(visited));
    }
    int num = 0;
    for (int i = 0; i <= N; i++) {
        if (reachable[i] == K) {
            num++;
        }
    }
    
    cout << num << endl;
    
    return 0;
}
