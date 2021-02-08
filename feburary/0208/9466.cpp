#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>

#define N 100001
using namespace std;

// visit 배열과 group 배열 생성

int visit[N];
int group[N];
int cnt;

void dfs(int x,vector<int> &vec){
    visit[x] = 1;
    int next = vec[x];
    if(!visit[next]){
        dfs(next,vec);
    }
    else if(!group[next]){   // 방문한 노드 또 방문, but 아직 group 이 아닐 때
        for(int i = next;i!=x;i= vec[i]){
            cnt++;
            group[i] = 1;
        }
        cnt++;
    }
    group[x] =1;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);   
    int t,n;    cin>>t;
    while(t--){
        cin>>n;
        vector<int> vec(n+1);
        for(int i=0;i<n;i++){
            int a;  cin>>a;
            vec[i+1] = a;
        }
        fill_n(visit,n+1,0);
        fill_n(group,n+1,0);
        cnt = 0;
        for(int i=1;i<=n;i++){
            if(!visit[i])   dfs(i,vec);
        }
        cout<<n-cnt<<'\n';
    }
    return 0;    
}


