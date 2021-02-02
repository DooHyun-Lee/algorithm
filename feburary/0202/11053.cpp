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
	fill_n(dp,100,1);	// initialize dp array as 1
	for(int i=2;i<=num;i++){
		for(int j=1;j<i;j++){       // arr[i] 로 돌면서 arr[j] 보다 크면 자기 원래 dp[i]와 새로운 dp[j]+1 의 크기를 비교해 큰 것으로 
			if(arr[j]<arr[i]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	int result = *max_element(dp+1,dp+num+1);
	printf("%d\n",result);
	return 0;
}
