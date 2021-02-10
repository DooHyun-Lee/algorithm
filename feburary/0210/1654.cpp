#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#define N 10001
using namespace std;

int arr[N]; // 길이 정보 저장

int num(int len,int n){
    int result = 0;
    for(int i=1;i<=n;i++){
        result += arr[i]/len;
    }
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,k;  cin>>k>>n;
    for(int i=1;i<=k;i++){
        cin>>arr[i];
    }
    long long left = arr[1]/n;
    if(left ==0)
        left = 1;
    long long right =0;
    for(int i=1;i<=k;i++){
        right += arr[i];
    }
    right /= n; // 최적 으로 나눴을 때 최대 길이
    long long mid,ans;
    
    while(left<=right){
        mid = (left+right)/2;
        if(num(mid,k)>=n){
            left = mid+1;
            ans = mid;
        }
        else {
            right = mid-1;
        }
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
