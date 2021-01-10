#include<iostream>
#include<memory.h>

using namespace std;
// 아이디어: dfs 로만 풀 경우 각 정점당 4번의 탐색을 쌩으로 하면 4^V 의 연산발생
// 경로를 구해놓은 정점은 dp 배열에 저장한 후 이 값을 가져와 사용함으로 연산 수 감소


int arr[501][501];  // 둘다 index 1부터 사용
int dp[501][501];   // 각 점의 경로 개수 저장 배열
int x[4] = {1,-1,0,0};
int y[4] = {0,0,-1,1}; // 동서남북
int m,n;

int dfs(int a,int b){   // 경로 개수 반환 해주는 함수
    if(dp[a][b]!=-1)
        return dp[a][b];    // 이미 탐색되었다는 뜻
    if(a==1 && b ==1)
        return 1;   // base case
    if(a>m || a<=0 || b>n || b<=0)
        return 0;   // out of range 일 때 경로 없음

    dp[a][b] = 0; // 위의 세가지 예외 아닐 경우 탐색되었다는 뜻
    for(int i=0;i<4;i++){   // 자신 주변 동서남북 탐색해 더 큰 점에 이르는 경로 모두 합
        int xnext = b + x[i];
        int ynext = a + y[i];
        if(arr[ynext][xnext] > arr[a][b]){
            dp[a][b] += dfs(ynext,xnext);
        }
    }
    return dp[a][b];
    
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp)); // 탐색되지 않은 dp를 -1로 초기화
    printf("%d",dfs(m,n));
    return 0;
}