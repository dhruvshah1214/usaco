/* 
 TASK: fracdec
 LANG: C++11
 */

#include <iostream>
#include <fstream>
using namespace std;

int a, b, z, q;
int r[100005], rp, cycp;
int de[100005], dn;

int main()
{
    ifstream in("fracdec.in");
    ofstream out("fracdec.out");
    in >> a >> b;
    z = a/b;
    a -= z*b;
    while(true)
    {   
        if(r[a])
        {
            cycp=r[a];
            break;
        }
        r[a]=++rp;
        a*=10;
        q = a/b;
        a = a-q*b;
        de[++dn]=q;
        if(a==0)
        {
            rp=-1;
            break;
        }       
    }
    int cnt =2;
    for(int i=z;i>9;i/=10)
        cnt++;
    out << z << ".";
    for(int i=1;i<=dn;i++,cnt++)
    {
        if(cnt%76==0)
            out << endl;
        if(i==cycp)
        {
            out << "(";
            cnt++;
        }
        out << de[i];
        if(i==rp)
            out << ")";
    }   
    out << endl;
    return 0;
}
