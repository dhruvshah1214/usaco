#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct link {
    string value;
    int count;
    link *next;
};

link* hashtable[28000000];

int letterHash(char c) {
    return c - min('a', 'A');
}

long long hash_func(string word) {
    long long hash = 0;
    int i = word.length() - 1;
    for(char c : word) {
        hash += letterHash(c) * pow(26, i);
        i--;
    }
    return hash;
}

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    for(string w : magazine) {
        long long hf = hash_func(w);
        link *l = hashtable[hf];
        if(l == NULL) {
            hashtable[hf] = new link;
            hashtable[hf]->value = w;
            hashtable[hf]->count = 1;
        }
        bool ins = 1;
        while(l != NULL) {
            if (l->value == w) {
                l->count++;
                ins = 0;
                break;
            }
            l = l->next;
        }
        if (ins) {
            link *nl = new link;
            nl->value = w;
            nl->count = 1;
            l = nl;
        }
        
    }
    for(string w : ransom) {
        link *l = hashtable[hash_func(w)];
        if(l == NULL) {
            return false;
        }
        else {
            bool found = 0;
            while(l != NULL) {
                if(l->value == w) {
                    if (l->count > 0) {
                        l->count--;
                        found = 1;
                        break;
                    }
                }
                l = l->next;
            }
            if(found == 0) {
                return false;
            }
        }
    }
    return 1;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
        cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
        cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    
    return 0;
}
