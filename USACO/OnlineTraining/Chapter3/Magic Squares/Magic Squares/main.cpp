/*
 TASK: msquare
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <map>

#define INF 1 << 29

using namespace std;

string S = "        ";
map<string, int> depth;
int best;
string bestPath;

int toBaseTen(string c) {
    int n = stoi(c,0,8);
    return n;
}

string toBaseEight(int b10 ) {
    return "";
}

string A(string conf) {
    reverse(conf.begin(), conf.end());
    return conf;
}

string B(string conf) {
    string top = conf.substr(0, 3);
    char c = conf[3];
    top.insert(0, 1, c);
    
    string bottom = conf.substr(5, 3);
    c = conf[4];
    bottom += c;
    
    return top + bottom;
}

string C(string conf) {
    string s = conf;
    s[5] = conf[2];
    s[6] = conf[5];
    s[1] = conf[6];
    s[2] = conf[1];
    return s;
}

pair<int, string> bfs() {
    queue<pair<string, string> > q;
    q.push({"", "01234567"});
    while (!q.empty()) {
        string s = q.front().first;
        string conf = q.front().second;
        q.pop();
        if (s.length() >= depth[(conf)] && depth[(conf)] > 0) {
            continue;
        }
        int curDepth = depth[(conf)] = (int)s.length();
        
        if (conf == S) {
            return {s.length(), s};
        }
        
        string newString;
        newString = A(conf);
        if (newString == S) {
            return make_pair(s.length() + 1, s + "A");
        }
            q.push({s + "A", newString});
        
        
        newString = B(conf);
        if (newString == S) {
            return make_pair(s.length() + 1, s + "B");
        }
            q.push({s + "B", newString});
        
        
        newString = C(conf);
        if (newString == S) {
            return make_pair(s.length() + 1, s + "C");
        }
            q.push({s + "C", newString});
        
    }
    return {-1, "NP"};
}



int main(int argc, const char * argv[]) {
    cout << "HELL" << endl;

    ifstream in("msquare.in");
    ofstream out("msquare.out");
    

    for (int i = 0; i < 8; i++) {
        int a;
        in >> a;
        a--;
        S[i] = a + '0';
    }
    
    
    pair<int, string> p = bfs();
    
    cout << p.first << endl << p.second << endl;
    out << p.first << endl << p.second << endl;

    return 0;
}
