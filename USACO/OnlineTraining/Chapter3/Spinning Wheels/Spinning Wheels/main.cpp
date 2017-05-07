/*
 TASK: spin
 LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

int speed[5];
int numW[5];
int wedge[5][5][2];
int t = 0;

bool pass(int l1[22], int l2[2], int wn) {
    if (t == 357) {
        cout << wn << endl;
    }
    if (wn == 5) {
        return true;
    }
    // cout << "WHEEL " << wn << endl;
    int ll1[22], ll2[22], ll = 0;
    for (int i = 0; i < 22; i++) {
        if (l1[i] != -1) {
            int s = l1[i], e = ((l1[i] + l2[i]) % 360);
            if (t == 357) {
                cout << "WEDGE GOTTA FIT THRU " << s << " " << e << endl; 
            }
            for (int j = 0; j < numW[wn]; j++) {
                int ns = wedge[wn][j][0], ne = (wedge[wn][j][0] + wedge[wn][j][1]) % 360;
                if (s <= e && ns <= ne) {
                    int rs = max(s, ns), re = min(e, ne);
                    if (rs <= re) {
                        ll1[ll] = rs % 360;
                        ll2[ll] = re - rs;
                        ll++;
                        if (t == 357) {
                            cout << "NEW PASS " << rs << " " << re << endl;
                        }
                    }
                }
                else {
                    // case one s > e
                    if (s >= e && ns <= ne) {
                        int noe = e + 360;
                        int nns = ns + 360, nne = ne + 360;
                        int rs = max(s, nns), re = min(nne, noe);
                        if (rs <= re) {
                            ll1[ll] = rs % 360;
                            ll2[ll] = re - rs;
                            ll++;
                            if (t == 357) {
                                cout << "NEW PASS " << rs << " " << re % 360 << endl;
                            }
                        }
                    }
                    // case two ns > ne
                    else if (s <= e && ns >= ne) {
                        // two segments
                        int s1ns = ns, s1ne = 359;
                        int rs = max(s, s1ns), re = min(e, s1ne);
                        if (rs <= re) {
                            ll1[ll] = rs  % 360;
                            ll2[ll] = re - rs;
                            ll++;
                            if (t == 357) {
                                cout << "NEW PASS " << rs << " " << re % 360 << endl;
                            }
                        }
                        int s2ns = 0, s2ne = ne;
                        rs = max(s, s2ns), re = min(e, s2ne);
                        if (rs <= re) {
                            ll1[ll] = rs % 360;
                            ll2[ll] = re - rs;
                            ll++;
                            if (t == 357) {
                                cout << "NEW PASS " << rs << " " << re % 360 << endl;
                            }
                        }
                        
                    }
                    //case 3 both
                    else if (s >= e && ns >= ne) {
                        
                        
                    }
                }
            }
        }
    }
    if (ll == 0) {
        return false;
    }
    while (ll < 22) {
        ll1[ll] = -1;
        ll2[ll] = -1;
        ll++;
    }
    if (t == 357) {
        cout << endl;
    }
    
    return pass(ll1, ll2, wn + 1);
}

int main(int argc, const char * argv[]) {
    ifstream in("spin.in");
    ofstream out("spin.out");
    
    for (int i = 0; i < 5; i++) {
        in >> speed[i] >> numW[i];
        for (int j = 0; j < numW[i]; j++) {
            in >> wedge[i][j][0] >> wedge[i][j][1];
     
        }
        speed[i] %= 360;
    }
    
    int a[22];
    int b[22];
    a[0] = 0;
    b[0] = 359;
    for (int i = 1; i < 22; i++) {
        a[i] = b[i] = -1;
    }
    
    //cout << pass(a, b, 0) << endl;
    
    
    
    while (!pass(a, b, 0)) {
        t++;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < numW[i]; j++) {
                wedge[i][j][0] += speed[i];            
                wedge[i][j][0] %= 360;
            }
        }
        /*
        for (int i = 0; i < 5; i++) {
            cout << speed[i] << " " << numW[i] << " ";
            for (int j = 0; j < numW[i]; j++) {
                cout << wedge[i][j][0] << " " << wedge[i][j][1] << " ";
                
            }
            cout << endl;
        }
        cout << endl << endl << endl << endl;
        */
        if (t > 361) {
            cout << "none" << endl;
            out << "none" << endl;
            return 0;
        }
        if (t == 357) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < numW[i]; j++) {
                    int ns = wedge[i][j][0], ne = (wedge[i][j][0] + wedge[i][j][1]) % 360;
                    cout << ns << " " << ne << " ";
                    
                }
                cout << endl;
            }
        }
    }
    
    cout << t << endl;
    out << t << endl;

    
    /*
     1 1 140 359 
     1 1 200 359 
     1 1 4 1 
     2 1 6 1 
     1 1 300 300 
     */
    
    return 0;
}
