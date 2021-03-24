#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 987654321
#define MIN -987654321

vector<int> arr;
vector<int> op;
int n;
int minret = MAX;
int maxret = MIN;

void findmax(int cnt,int cur){
    if(cnt == n-1){
        minret = min(cur,minret);
        maxret = max(cur,maxret);
        return;
    }
    for(int i=0;i<4;i++){
        if(op[i]>0){
            op[i]--;
            switch(i){
                case 0:
                    findmax(cnt+1,cur+arr[cnt+1]);
                break;
                case 1:
                    findmax(cnt+1,cur-arr[cnt+1]);
                break;
                case 2:
                    findmax(cnt+1,cur*arr[cnt+1]);
                break;
                case 3:
                    findmax(cnt+1,cur/arr[cnt+1]);
                break;
            }
            op[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    arr.assign(n,0);
    op.assign(4,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<4;i++){
        cin>>op[i];
    }
    findmax(0,arr[0]);
    cout<<maxret<<'\n'<<minret<<'\n';
    return 0;
}   
