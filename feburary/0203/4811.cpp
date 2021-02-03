#include<iostream>

#define N 31

using namespace std;

long long dp[N];

long long drug(int n){
    if(dp[n]!=0){       // 이미 계산된 경우 바로 반환
        return dp[n];
    }
    
    int idx=2;
    while(dp[idx]!=0){
        idx++;
    }   // 계산안된 가장 작은 인덱스
    
    for(int i=idx;i<=n;i++){
        for(int j=0;j<=i-1;j++){
            dp[i] += dp[j]*dp[i-1-j];
        }
    }
    // 알약 n개의 경우 큰 알을 우선적으로 먼저 먹어야 하고 -1 되었다고 생각하면 나머지 부분 문제는 n-1에 대한 값을 구성하는 방법을 모두 더하면 된다
    // 반쪽 자리 알약은 순서에 영향을 주지 않으므로 
    return dp[n];
}

int main(){
    int num;    cin>>num;
    dp[0] =1;
    dp[1] = 1;
    while(num){
        printf("%lld\n",drug(num));
        scanf("%d",&num);
    }
    return 0;
}

