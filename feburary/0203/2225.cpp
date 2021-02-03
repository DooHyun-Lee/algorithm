#include<iostream>
#define N 201
#define MOD 1000000000
using namespace std;

long long dp[N][N];     // dp[k][n] 의 원소집합

int main(){
    int n,k;    cin>>n; cin>>k;
    for(int i=0;i<=n;i++){  // base 설정
        dp[1][i] = 1;   // 1개로 i 만드는 경우 총 1가지 
    }
    for(int i=0;i<=k;i++){
        dp[i][0] = 1;   // i개로 0 만드는 경우 총 1가지
    }
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD; // 왼쪽과 위의 합
        }
    }
    printf("%lld\n",dp[k][n]);
    return 0;
} 


// n^3 -> n^2 으로 만들기 위해 원래 dp[k][N] = sigma(dp[k-1][N-L] * dp[1][L](->1)) = dp[k][N-1] + dp[k-1][N] 임을 이용
// 배열 그림으로 그려보면 이해
