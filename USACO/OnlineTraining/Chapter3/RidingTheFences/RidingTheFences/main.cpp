/*
 PROG: fence
 LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int F;
vector<int> fences[505];
int degree[505];
int circuit[505];
int circuitPos = 0;
int inter = 0;

void find_circuit(int i) {
    if (fences[i].size() == 0) {
        circuit[circuitPos++] = i;
    }
    else {
        while (fences[i].size() > 0) {
            int j = fences[i][0];
            fences[i].erase(fences[i].begin());
            fences[j].erase(remove(fences[j].begin(), fences[j].end(), i), fences[j].end());
            find_circuit(j);
        }
        circuit[circuitPos++] = i;
    }
}
/*
if node i has no neighbors then
 circuit(circuitpos) = node i
 circuitpos = circuitpos + 1
else
 while (node i has neighbors)
    pick a random neighbor node j of node i
    delete_edges (node j, node i)
    find_circuit (node j)
 circuit(circuitpos) = node i
 circuitpos = circuitpos + 1
*/

int main(int argc, const char * argv[]) {
    ifstream in("fence.in");
    ofstream out("fence.out");    
    
    
    bool debug = 0;
    
    if (debug) {
        cin >> F;
        for (int i = 0; i < F; i++) {
            int a, b;
            cin >> a >> b;
            degree[a]++;
            degree[b]++;
            fences[a].push_back(b);
            fences[b].push_back(a);
            
            inter = max(inter, max(a, b));
        }
    }
    
    else {
        in >> F;
        for (int i = 0; i < F; i++) {
            int a, b;
            in >> a >> b;
            degree[a]++;
            degree[b]++;
            fences[a].push_back(b);
            fences[b].push_back(a);  
            
            inter = max(inter, max(a, b));

        }
    }
    
    for (int i = 0; i <= inter; i++) {
        sort(fences[i].begin(), fences[i].end());
    }
    
    int i = 1;
    for (; i <= inter; i++) {
        if (degree[i] % 2 == 1) {
            find_circuit(i);
            break;
        }
    }
    if (i > inter) {
        find_circuit(1);
    }
    for (int i = circuitPos - 1; i >= 0; i--) {
        cout << circuit[i] << endl;
        out << circuit[i] << endl;
    }
    
    
    
    return 0;
}
