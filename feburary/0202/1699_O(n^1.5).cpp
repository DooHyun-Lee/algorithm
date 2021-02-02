#include<iostream>
#include<algorithm>
#include<cmath>

#define MAX 100001
using namespace std;

int dp[MAX];

int main(){
    int num;    cin>>num;
    for(int i=1;i<MAX;i++){
        dp[i] = i;  // dp 를 index 와 동일한 값으로 초기화
    }
    for(int i=3;i<=num;i++){
        for(int j=1;j<=sqrt(i);j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);   // 자기 이하의 제곱수들을 뺐을 때 더 작은 값으로 초기화
        }
    }
    printf("%d\n",dp[num]);
    return 0;
    
}
