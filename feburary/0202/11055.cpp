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
		dp[i] = arr[i];   // 같은 원소로 초기화 하지 않는 경우 예외발생 ex) 50 30 40 
	}
	//dp[1] = arr[1];
	for(int i=2;i<=num;i++){
		for(int j=1;j<i;j++){
			if(arr[j]<arr[i]){
				dp[i] = max(dp[i],dp[j]+arr[i]);    // 11053 과 같은 알고리즘이지만 원소를 더한 다는 점에서 목표가 다름
			}
		}
	}
	int result = *max_element(dp+1,dp+num+1);
	printf("%d\n",result);
	return 0;
}


