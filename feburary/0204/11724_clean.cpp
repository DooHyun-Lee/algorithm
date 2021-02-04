#include <stdio.h>
#include<vector>
#include <algorithm>
int n, m, x[10009], y[10009], check[10009] = {0, }, cnt = 0;
using namespace std;
vector<int> p[1009];

void dfs(int x){
    check[x] = 1;
    for (int i=0;i<p[x].size();i++){
        if(check[p[x][i]] == 0){
            dfs(p[x][i]);
        }
    }
}

int main(){
    int i, j, k;
    scanf ("%d %d", &n, &m);
    for (i=0;i<m;i++){
        scanf ("%d %d", &x[i], &y[i]);
        p[x[i]].push_back(y[i]);
        p[y[i]].push_back(x[i]);
    }
    for (i=1;i<=n;i++){
        if(check[i]==0){
            dfs(i);
            cnt++;
        }
    }
    
    printf ("%d", cnt);
    
    
    return 0;
}
