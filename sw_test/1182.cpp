#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 987654321
#define MIN -987654321

int n,s;
vector<int> arr;
int result;

void findall(int curidx,int ret){
    if(ret == s){
        result++;     // 이분에서 바로 return 하게 될 경우 s= 0 이고 0이 연속으로 올 경우 모든 경우를 count 해 줄 수 없으므로 return 문을 빼고 생각 
    }
    if(curidx == n-1) return;  
    for(int i= curidx+1;i<n;i++){
        findall(i,ret+arr[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>s;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        findall(i,arr[i]);
    }
    cout<<result<<'\n';
    return 0;
}   
