/*
 TASK: fact4
 LANG: C++11
 */
#include <fstream>

int main(int argc, const char * argv[]) {
    std::ifstream in("fact4.in");
    std::ofstream out("fact4.out");
    int f,mod = 100000,b=1;
    in >> f;
    for(int i=2;i<=f;i++)
    {
        b=b*i%mod;
        while(b%10==0) b/=10;
    }
    b %= 10;
    out << b << std::endl;
}
