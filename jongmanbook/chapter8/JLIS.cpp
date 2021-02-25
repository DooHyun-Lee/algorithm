#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int arr1[100];
int arr2[100]; 
int cache[105][105];
const long long MIN = numeric_limits<long long>::min();

int jlis(int idx1,int idx2,int n, int m){
    int& ret = cache[idx1+1][idx2+1];   // 시작을 -1에서 할 것이므로 
    if(ret != -1)   return ret;
    ret = 2;
    long long a = ((idx1 == -1)? MIN:arr1[idx1]);
    long long b = ((idx2 == -1)? MIN:arr2[idx2]);
    long long maxelement = max(a,b);
    for(int next1 = idx1+1;next1<n;next1++){
        if(maxelement<arr1[next1]){
            ret = max(ret,jlis(next1,idx2,n,m)+1);
        }
    }
    for(int next2 = idx2+1;next2<m;next2++){
        if(maxelement<arr2[next2]){
            ret = max(ret,jlis(idx1,next2,n,m)+1);
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
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        memset(cache,-1,sizeof(cache));
        int n,m;    cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        for(int i=0;i<m;i++)
            cin>>arr2[i];
        cout<<jlis(-1,-1,n,m)-2<<'\n';
    }
    return 0;
}
