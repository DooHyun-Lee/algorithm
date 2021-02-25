#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int arr[505];
int cache[505];

int lis(int start,int n){
    int& ret = cache[start+1];
    if(ret != -1)   return ret;
    ret = 1;
    for(int next = start+1 ;next<n;next++){
        if(start == -1 || arr[start]<arr[next]){
            ret = max(ret,lis(next,n)+1);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;  cin>>c;
    while(c--){
        memset(arr,0,sizeof(arr)); 
        memset(cache,-1,sizeof(cache));
        int n;  cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<lis(-1,n)-1<<'\n';
    }
    return 0;
}
