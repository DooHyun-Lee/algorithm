#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define N 1001

using namespace std;

int flag[N];        // 받문시 1, 안하면 0

void dfs_real(int n,vector<vector<int>> &vec){    // dfs 재귀함수
    flag[n] = 1;
    for(int i=0;i<vec[n].size();i++){
        if(!flag[vec[n][i]])
            dfs_real(vec[n][i],vec);
    }
}

int dfs(int n,vector<vector<int>> &vec,int v){  // 점의 개수 v전달  n 은 시작점
    int count = 0;
    fill_n(flag,v+1,0);
    for(int i=1;i<=v;i++){
        if(!flag[i]){   // 아직 방문안했을 경우
            for(int j=0;j<vec[i].size();j++){
                if(!flag[vec[i][j]]){
                    dfs_real(vec[i][j],vec);
                }
            }
        count++;    // dfs 나와서 방문하지 않은 새로운 점을 찾을 때마다 사이클을 시작하기 때문에
        }
    }
    return count;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int k;  cin>>k;
    while(k--){
        vector<vector<int>> vec(N);
        int num;    cin>>num;
        for(int i=1;i<=num;i++){
            int to; cin>>to;
            vec[i].push_back(to);
        }
        cout<<dfs(vec[1][0],vec,num)<<'\n';
    }
    return 0;
}



