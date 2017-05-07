/* 
 PROG: contact
 LANG: C++11
 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, A, B;
string S;

vector<pair<int, string> > ans;
map<string, int> m;

string binary(unsigned int n) {
    const int size = sizeof(n) * 8;
    string res;
    bool s=0;
    for (int a=0;a<size;a++){
        bool bit=n>>(size-1);
        if (bit)
            s=1;
        if (s)
            res.push_back(bit+'0');
        n<<=1;
    }
    if (!res.size())
        res.push_back('0');
    return res;
}

bool anscomp(const pair<int, string>& a1, const pair<int, string>& a2) {
    if (a1.first == a2.first) {
        if(a1.second.length() == a2.second.length()) {
            return a1.second < a2.second;
        }
        return a1.second.length() < a2.second.length();
    }
    return a1.first > a2.first;
}


int main(int argc, const char * argv[]) {
    ifstream in("contact.in");
    ofstream out("contact.out");
    
    in >> A >> B >> N;
    in.ignore();
    string s;
    while (getline(in, s)) {
        if (s.length() == 0) {
            break;
        }
        S += s;
    }
    cout << S << endl;
    
    for (int i = 0; i < S.length(); i++) {
        for (int j = A; j <= B; j++) {
            if (i + j > S.length()) {
                break;
            }
            if (m[S.substr(i, j)]) {
                m[S.substr(i, j)]++;
            }
            else {
                m[S.substr(i, j)] = 1;
            }
            if(S.substr(i, j) == "00") {
                cout << "LAKSJDHLASKJDH " << i << " " << j << endl;
            }
        }
    }
    
    
    for (auto it = m.begin(); it != m.end(); it++) {
        ans.push_back(make_pair(it->second, it->first));
        cout << ans.back().first << "  " << ans.back().second << endl;
    }
    sort(ans.begin(), ans.end(), anscomp);
    
    int cur = ans[0].first;
    int it = 1;
    int perline = 0;
    
    cout << ans[0].first << endl;
    out << ans[0].first  << endl;
    
    for (int i = 0; i < ans.size(); i++) {
        pair<int, string> cura = ans[i];
        pair<int, string> nxta = ((i < (int)(ans.size() - 1)) ? ans[i + 1] : make_pair(-100, ""));
        
        if (cura.first == cur) {
            if (perline == 6) {
                cout << endl;
                out << endl;
                perline = 0;
            }
            cout << cura.second;
            out << cura.second;
            perline++;

            if (nxta.first == cur && perline < 6) {
                cout << " ";
                out << " ";
            }
        }
        else {
            if (it == N) {
                break;
            }
            
            cout << endl;
            cout << cura.first << endl;
            cout << cura.second;
            
            out << endl;
            out << cura.first << endl;
            out << cura.second;
            
            cur = cura.first;
            if (nxta.first == -100) {
                break;
            }
            
            if (nxta.first == cura.first) {
                cout << " ";
                out << " ";
            }
            it++;
            perline = 1;

        }
    }
    
    cout << endl;
    out << endl;
    return 0;
}
