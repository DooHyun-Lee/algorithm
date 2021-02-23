#include<iostream>
#include<vector>
#include<cstring>
#define N 101

using namespace std;

int arr[N][N];
int cache[N][N];    // 방문 안하면 -1, 방문 한 경우 결과를 0 또는 1로 저장

bool able(int y,int x,int n){   // y,x 에서 끝점에 도달할 수 있는지
    if(y>n || y<=0 || x>n || x<=0)
        return false;   // base condition
    if(y==n && x ==n)   // 목표에 도달
        return true;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    return ret = able(y+arr[y][x],x,n) || able(y,x+arr[y][x],n);  // 둘 중 한 경로가 가능해도 되는 경우로 판별 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;  cin>>c;
    while(c--){
        int n;  cin>>n;
        memset(arr,0,sizeof(arr));
        memset(cache,-1,sizeof(cache));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cin>> arr[i][j];
        }
        able(1,1,n)?cout<<"YES"<<'\n':cout<<"NO"<<'\n';
    }
    return 0;
}
