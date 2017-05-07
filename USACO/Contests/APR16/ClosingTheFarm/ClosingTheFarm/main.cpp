
#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>

#include <queue>

using namespace std;

int N, M, cowo[3001];
vector<vector<int>> adj_list (3002);


bool fullConnect(int goalNodes) {
    int nodesReached = 0;
    bool vis[3002];
    for (int i = 0; i <= N; i++) {
        vis[i] = false;
    }
    
    int stillDere = cowo[N - 1];
    
    stack<int> s;
    s.push(stillDere);
    vis[stillDere] = true;
    
    while (!s.empty()) {
        int b = s.top();
        s.pop();
        nodesReached++;
        
        for (int i = 0; i < adj_list[b].size(); i++) {
            int neigh = adj_list[b][i];
            if (vis[neigh] == false) {
                s.push(neigh);
                vis[neigh] = true;
                // cout << "PUSH " << i << endl;
            }
        }
    }
    
    return (nodesReached >= goalNodes);
}

int main(int argc, const char * argv[]) {
    ifstream in("closing.in");
    ofstream out("closing.out");
    
    in >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        in >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }
    for (int i = 0; i < N; i++) {        
        in >> cowo[i];
        sort(adj_list[i].begin(), adj_list[i].end());
    }
    
    
    string s = (fullConnect(N) ? "YES" : "NO");
    out << s << endl;
    // cout << endl << endl << s << endl << endl;

    
    
    for (int i = 0; i < N - 1; i++) {
        adj_list[cowo[i]].erase(adj_list[cowo[i]].begin(), adj_list[cowo[i]].end());
        for (int j = 1; j <= N; j++) {
            adj_list[j].erase(remove(adj_list[j].begin(), adj_list[j].end(), cowo[i]), adj_list[j].end());
        }
        
        s = (fullConnect(N - (i + 1)) ? "YES" : "NO");
        // cout << s << endl << endl;
        out << s << endl;
    }
    
    
    
    return 0;
}


