#include<iostream>
#include<utility>
#include<queue>

using namespace std;

//아이디어 : 1에서 시작한 익은 토마토에서 근접 토마토들은 +1 씩 즉 +2, +3 과 같이 최종적으로 ans+1 값으로
// 최대인 토마토가 존재 

int arr[1000][1000];
int xmove[4] = {1,-1,0,0};
int ymove[4] = {0,0,-1,1};  // 동서남북

int main(){
    int N,M;
    cin>>M>>N;
    queue<pair<int,int>> qu;
    int ans = 0;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
        int t;  cin>>t;
        arr[i][j] = t;
        if(t==1){
        qu.push(make_pair(i,j));    // 익은 사과 모두 저장
        }
        }
    }

    while(!qu.empty()){
        auto node = qu.front();
        qu.pop();
        for(int i=0;i<4;i++){   // 동서남북으로 고려하기 위해 
            int x_next = node.second + xmove[i];
            int y_next = node.first + ymove[i];
            if(x_next>=0 && x_next<M && y_next>=0 && y_next<N){ // 범위 안에서 놀 때
                if(arr[y_next][x_next]==0){ // 아직 안익은 토마토를 익히고 큐에 push
                    qu.push(make_pair(y_next,x_next)); 
                    arr[y_next][x_next] = arr[node.first][node.second]+1;   // 익은 토마토 소요 일 수 +1
                }
            }
        }
    }   // bfs 진행

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==0){
                cout<<-1<<endl; // 안익은것이 하나라도 있으면 -1
                return 0;
            }
            if(arr[i][j]>ans)
                ans = arr[i][j];    // 최대 일수 저장
        }
    }

    cout<<ans-1<<endl;
    return 0;
}