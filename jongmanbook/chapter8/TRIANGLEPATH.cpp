#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int tri[101][101];
int cache[101][101];

int summax(int y,int x,int n){    // 좌표 y,x에서 시작해 얻을 수 있는 최대합 (이전 부분에 영향받지 않는 최적 부분 구조 설계)
    if(y == n)
        return tri[n][x];
    int& ret = cache[y][x];
    if(ret != -1)   return ret;
    ret = 0;
    ret = max(summax(y+1,x+1,n),summax(y+1,x,n)) + tri[y][x]; 
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;  cin>>c;
    while(c--){
        int n;  cin>>n;
        memset(tri,0,sizeof(tri));
        memset(cache,-1,sizeof(cache));
        for(int i=1;i<=n;i++){
            for(int j =1;j<=i;j++){
                cin>>tri[i][j];
            }
        }
        cout<<summax(1,1,n)<<'\n';
    }
    return 0;
}
