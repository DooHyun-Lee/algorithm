#include<iostream>
#include<vector>
#include<cstring>
#define MOD 1000000007
using namespace std;

int cache[101]; //1~100 까지 사용

int tiling(int num){    // 2*num 형태의 칸에 채우는 방법의 수
    if(num == 1)    return 1;
    if(num ==2)     return 2;
    int& ret = cache[num];
    if(ret != -1)   return ret;
    return ret = (long long)(tiling(num-1) + tiling(num-2)) % MOD;
}

int asymtiling(int num){  // tiling 구현을 이용해 전체 - 대칭인 것의 수로 계산
    if(num ==2) return 0;
    if(num%2)
        return (long long)(tiling(num) - tiling(num/2) + MOD) % MOD;
    int ret = tiling(num);
    ret = (ret - tiling(num/2)+MOD) % MOD;
    ret = (ret - tiling(num/2 -1)+MOD) % MOD;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;  cin>>c;
    memset(cache,-1,sizeof(cache));
    while(c--){
        int n;  cin>>n;
        cout<<asymtiling(n)<<'\n';
    }
    return 0;
}
