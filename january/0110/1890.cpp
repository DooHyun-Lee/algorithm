#include<iostream>

using namespace std;


int arr[101][101];
long long count[101][101];  // 경로의 수 조건 범위 맞추기 위해

int main(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int num;
            scanf("%d",&arr[i][j]);
        }
    }
    count[1][1] = 1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int move = arr[i][j];
            if(i!=N && i+move<=N)
                count[i+move][j] += count[i][j];    //아래로 가는 경우
            if(j!=N && j+move<=N)
                count[i][j+move] += count[i][j];    // 위로 가는 경우
        }
    }

    printf("%lld\n",count[N][N]);
    
}