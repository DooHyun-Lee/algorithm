#include<iostream>
#include<algorithm>

#define MAX 301
using namespace std;

int arr[MAX];
int dp[MAX];

int main(){
    int num;    cin>>num;
    for(int i=1;i<=num;i++){
        scanf("%d",&arr[i]);
    }
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    for(int i=3;i<=num;i++){
        dp[i] = max(arr[i] + dp[i-2],arr[i]+arr[i-1]+dp[i-3]);    // arr[i] 가 필수이기 때문에 arr[i] 만 선택 후 i-2 까지 최대 값 합 or 
        // arr[i] 와 arr[i-1] 선택 후 i-3까지 최대 합 인 경우 비교하여 큰 값으로 선택 
        // 마지막 계단이 필수선택이므로 i-1까지 최대 합은 고려대상이 
    }
    printf("%d\n",dp[num]);
    return 0;
}
