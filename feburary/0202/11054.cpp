#include<iostream>
#include<algorithm>

#define MAX 1001
using namespace std;

int dp_i[MAX];  // dp increase
int dp_d[MAX];  // dp increase _backward
int arr[MAX];

int main(){
	int num;	cin>>num;
	for(int i=1;i<=num;i++){
		scanf("%d",&arr[i]);
	}
	fill_n(dp_d,MAX,1);
	fill_n(dp_i,MAX,1);
	for(int i=2;i<=num;i++){
		for(int j=1;j<i;j++){
			if(arr[j]<arr[i]){
			   dp_i[i] = max(dp_i[i],dp_i[j]+1);  // 정방향 최장길이 증가수열 계산
			}
		}
	}
	for(int i=num-1;i>=1;i--){
		for(int j=i+1;j<=num;j++){
			if(arr[j]<arr[i]){
			   dp_d[i] = max(dp_d[i],dp_d[j]+1);  // 역방향 최장길이 증가수열 계산
			}
		}
	}
	
	for(int i=1;i<=num;i++){
	    dp_i[i] += dp_d[i];
	}   // save total result to dp_i
	int result = *max_element(dp_i+1,dp_i+num+1)-1;   // 결과값은 자기 자신을 두 수열에 동시포함하므로 -1 
	printf("%d\n",result);
	return 0;
}


