#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int mark[905];
int key[905];
int G[905][905];

int main() {
    int n, A, B;
    //cin>>n>>x>>y;
    scanf("%d %d %d",&n,&A,&B);
    for(int i=0;i<905;i++){
        for(int j=0;j<905;j++){
            G[i][j] = 1000000000;
        }
    }
    for(int i = 1;i<905;i++){
        key[i] = 100000000;
    }
    char l[100000];
    char c;
    cin.get(c);
    for(int i = 1; i <= n;i++){
        for (int j = 1; j <= n; j++) {
            char a;
            cin.get(a);
            l[n * (i - 1) + j] = a;
        }
        cin.get(c);
    }
    for(int i = 1; i <= n*n; i++){
        if(l[i] == l[i+1] && (i % n) != 0){
            G[i-1][i]= G[i][i-1] = A;
        }
        else if(l[i] != l[i+1] && (i % n) != 0){
            G[i-1][i] = G[i][i-1] = B;
        }
        if(l[i]==l[i+n] && i <= n*(n-1)){
            G[i-1][i+n-1] = G[i+n-1][i-1] =  A;
            
        }
        else if(l[i]!=l[i+n] && i <= n*(n-1)){
            G[i-1][i+n-1] = G[i+n-1][i-1] = B;
            
        }
    }
    
    
    mark[0] = 1;
    int node = 0;
    key[0] = 0;
    key[1]= G[0][1];
    key[n] = G[0][n];
    for(int i = 1; i <= (n * n); i++){
        int lowest = 1000000;
        
        for(int k = 1; k <= n*n; k++){
            if(key[k] < lowest && mark[k]==0){
                
                lowest = key[k];
                node = k;
            }
        }
        
        mark[node] = 1;
        for(int j = 1; j <= node+n;j++){
            if(mark[j] != 1 && key[j] >= key[node] + G[node][j]){
                key[j] = key[node] + G[node][j];
            }
        }
    }
    cout<<key[n*n-1] << endl;
}