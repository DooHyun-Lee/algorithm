// 부모, 자식에 대한 관계 없이 두 숫자만 주어졌으므로 양방향으로 연결 후 bfs로 탐색하면서 자기보다 전에 언급된 원소에 대해 부모 배열에 저장 후 출력


#include<iostream>
#include<vector>
#include<queue>
#define N 100001
using namespace std;

int parent[N];
int flag[N];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;  cin>>n;
    vector<vector<int>> vec(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;    cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    parent[1] = 1;
    flag[1] = 1;
    queue<int> qu;
    qu.push(1);
    while(!qu.empty()){
        int t =qu.front();
        qu.pop();
        for(int i=0;i<vec[t].size();i++){
        if(!flag[vec[t][i]]){
            flag[vec[t][i]] = 1;
            qu.push(vec[t][i]);
            parent[vec[t][i]] = t;
        }
        }
    }
    for(int i=2;i<=n;i++)
        cout<<parent[i]<<'\n';
}


