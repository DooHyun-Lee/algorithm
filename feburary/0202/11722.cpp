#include<iostream>
#include<algorithm>

#define MAX 1001
using namespace std;

int dp[MAX];
int arr[MAX];

int main(){
	int num;	cin>>num;
	for(int i=1;i<=num;i++){
		scanf("%d",&arr[i]);
	}
	fill_n(dp,MAX,1);
	for(int i=2;i<=num;i++){
		for(int j=1;j<i;j++){
			if(arr[j]>arr[i]){    // 증가수열 알고리즘에서 이 조건만 변경
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	int result = *max_element(dp+1,dp+num+1);
	printf("%d\n",result);
	return 0;
}


