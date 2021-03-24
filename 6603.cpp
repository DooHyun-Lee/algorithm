#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 987654321

vector<int> arr;
vector<int> path;
int n = 1;

void printarr(int curidx,vector<int>& path,int cnt){
    if(cnt == 6){
        for(auto i:path)    cout<<i<<' ';
        cout<<'\n';
        return;
    }
    for(int i=curidx+1;i<n;i++){
        path.push_back(arr[i]);
        printarr(i,path,cnt+1);
        path.pop_back();
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    while(n){
        arr.assign(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<=n-6;i++){
            path.push_back(arr[i]);
            printarr(i,path,1);
            path.clear();
            cout<<'\n';
        }
        cin>>n;
    }

    return 0;
}   
