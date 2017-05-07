#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define mp make_pair
using namespace std;
long long N;
pair<long long, pair<long long, long long> > a[100005];
pair<long long, long long> cow[100005];
// a{x, {y, positionOnGraph}}
bool custcomp(pair<long long, pair<long long, long long> > a, pair<long
              long, pair<long long, long long> > b) {
    if (a.second.first != b.second.first) {
        return a.second.first > b.second.first;
    }
    return a.first > b.first;
}
bool insort(pair<long long, long long > a, pair<long long, long long > b) {
    
    return a.first < b.first;
}
int main() {
    cin >> N;
    long long sum = 0;
    for (long long i = 1; i <= N; i++) {
        int a;
        char c;
        scanf("%d %c", &a, &c);
        cow[i].first = a;
        cow[i].second = ((c == 'W') ? 1 : -1);
    }
    sort(cow + 1, cow + N + 1, insort);
    a[0] = mp(0, mp(0, 0));
    for (long long i = 1; i <= N; i++) {
        sum += cow[i].second;
        a[i] = mp(i, mp(sum, cow[i].first));
        //printf("%lld\n",a[i].second.second);
        // b[i] = a[i];
    }
    sort(a, a + N + 1, custcomp);
    long long right = a[0].first;
    long long rightI = 0;
    long long maxn = 0;
    for (long long i = 0; i <= N; i++) {
        //printf("index %lld sum %lld position
        // %lld\n",a[i].first,a[i].second.first,a[i].second.second);
        if (a[i].first > right) {
            right = a[i].first;
            rightI = i;
        }
        else {
            //printf("%lld %lld\n",right,a[i].first);
            if (a[i].second.first <= a[rightI].second.first &&
                a[i].first + 1 > 0 && a[i].first + 1 <= N) {
                if ((right - a[i].first ) % 2 == 0) {
                    maxn = max(maxn, a[rightI].second.second -
                               cow[a[i].first + 1].first);
                }
                else {
                    if (right - 1 >= 0) {
                        maxn = max(maxn, cow[right - 1].first
                                   - cow[a[i].first + 1].first);
                    }
                    if (a[i].first + 2 <= N) {
                        maxn = max(maxn,
                                   a[rightI].second.second - cow[a[i].first + 2].first);
                    }
                }
            }
        }
    }
    cout << maxn << endl;
    return 0;
}