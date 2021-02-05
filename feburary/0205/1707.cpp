// 가장 중요한 것!!!!!
// bfs로는 모두 연결되어 돌 수 있다는 것을 보장하지 않기 때문에 끊어지는 부분은 새로 돌아가는 형태로 구현해야 함

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define N 20001

using namespace std;

int flag[N];        // -1 for non-visit || 0 and 1 for color
queue<int> qu;

void bfs(int v,vector<vector<int>> &vec){
    fill_n(flag,v+1,-1);  // 방문안한 -1 상태로 초기화
    for(int i=1;i<=v;i++){
        if(flag[i]==-1){
            int start = i;
            qu.push(start);
            flag[start] = 1;    // 첫번째 원소 색은 1
            while(!qu.empty()){
            int t = qu.front();
            qu.pop();
            for(int i=0;i<vec[t].size();i++){   // t 의 인점들에 대해
                if(flag[vec[t][i]]==flag[t]){   // 인접들 중 색이 같은 것이 있다면
                    cout<<"NO"<<'\n';
                    return;
                }    
                else if(flag[vec[t][i]] == -1){    // 아직 안칠함
                    flag[vec[t][i]] = (flag[t]+1)%2; // 반대색으로 색칠 후
                    qu.push(vec[t][i]);     // queue 에 추가
                }
            }
            }
        }
    }
    cout<<"YES"<<'\n';
    return;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int k;  cin>>k;
    while(k--){
        fill_n(flag,N,-1);
        vector<vector<int>> vec(N);
        int v,e;    cin>>v>>e;
        for(int i=0;i<e;i++){
            int a,b;    cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        bfs(v,vec);
        while(!qu.empty())  qu.pop();
    }
    return 0;
}
