#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int arr[25][25];
int flag[25][25];  // 모든 원소 0으로 초기화
int xmove[4] = {1,-1,0,0};
int ymove[4] = {0,0,-1,1}; // 동서남북
int ans; 

void bfs(int y, int x,int N){
    ans++;
    flag[y][x]++;
    queue<pair<int,int>> qu;
    qu.push(make_pair(y,x));
    while(!qu.empty()){
    auto node = qu.front();
    qu.pop();
    for(int i =0;i<4;i++){
        int x_next = node.second+xmove[i];
        int y_next = node.first+ymove[i];
        if(x_next>=0 && x_next<N && y_next>=0 && y_next<N){ // 4방향 중 범위안의 점에 대해 
            if(flag[y_next][x_next]==0 && arr[y_next][x_next]==1){   // arr 1 이고 아직 세지 않은 점일 경우
                ans++;
                flag[y_next][x_next]++;    // count 했다는 표시
                qu.push(make_pair(y_next,x_next));
            }
        }
    }
    }

}

int main(){
    int N;
    vector<int> vec;    // 동 별 아파트 개수 저장
    cin>>N;
    for(int i=0;i<N;i++){
        string st;
        cin>>st;
        for(int j=0;j<N;j++){
            arr[i][j] = st[j] - '0';    // string을 int로 변환
        }
    }
 
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==1 && flag[i][j]==0){
                ans = 0;
                bfs(i,j,N);
                vec.push_back(ans);
            }
        }
    }

    sort(vec.begin(),vec.end());
    cout<<vec.size()<<endl;
    for(auto i:vec)
        cout<<i<<endl;

    return 0;

}