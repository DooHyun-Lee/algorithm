#include<iostream>
#include<queue>
#include<utility>
#include<string>

using namespace std;

int maze[100][100];
int count[100][100];    //count initialized as 0 (전역변수)

int xmove[4] = {1,-1,0,0};
int ymove[4] = {0,0,-1,1}; // 동서남북에 대한 x,y 방향 순서쌍

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string st;
        cin>>st;
        for(int j=0;j<M;j++){
            maze[i][j] = st[j] - '0';   // convert string st into int
        }
    }

    count[0][0] = 1;
    queue<pair<int,int>> qu;    // operate bfs
    qu.push(make_pair(0,0));    
    while(!qu.empty()){
        auto node = qu.front();
        qu.pop();
        if(node.first == N-1 && node.second == M-1) // 도착 조건    node(y,x) 로 해석
            break;
        for(int i=0;i<4;i++){
            int x_next = node.second + xmove[i];    // 여기서부터 인접행렬은 [y][x] 를 나타냄에 유의
            int y_next = node.first + ymove[i];
            if(x_next>=0 && x_next<M && y_next>=0 && y_next<N){
                if(maze[y_next][x_next]==1 && count[y_next][x_next]==0){
                    qu.push(make_pair(y_next,x_next));
                    count[y_next][x_next] = count[node.first][node.second]+1;   // fisrt 가 y 이므로
                }
            }
        }
    }

    cout<<count[N-1][M-1]<<endl;
    return 0;
}

