#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MOD 10000000
using namespace std;

int cache[101][101];

int poly(int n,int first){  // 첫째줄에 first 개 있는 총 n개로 이뤄진 poly
    if(n == first) return 1;
    int& ret = cache[n][first];
    if(ret != -1)  return ret;
    ret = 0;
    for(int i=1;i<=n-first;i++){
        ret += ((first+i-1)*poly(n-first,i));
        ret = ret % MOD;
    }
    return ret;
}

int finalpoly(int n){
    int result = 0;
    for(int i=1;i<=n;i++){
        result += poly(n,i);
    }
    return result % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;  cin>>c;
    memset(cache,-1,sizeof(cache));
    while(c--){
        int n;  cin>>n;
        cout<<finalpoly(n)<<'\n';
    }
    return 0;
}
