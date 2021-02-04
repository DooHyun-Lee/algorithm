#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#define N 1001

using namespace std;

vector<vector<int>> point(N); // i 번째 점들의 인접 점들을 저장
int flag[N];    // 초기 0으로 설정 , 방문시 1로 변환
stack<int> st;
queue<int> qu;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int e,v,start;  cin>>e>>v>>start;
    for(int i=0;i<v;i++){
        int a,b;    cin>>a>>b;
        point[a].push_back(b);    
        point[b].push_back(a);    // 양방향 점 서로연결
    }
    
    for (int i = 1; i < N; i++) {
		sort(point[i].begin(), point[i].end());
	}
    
    st.push(start);
    while(!st.empty()){
        int t = st.top();
        st.pop();
        if(flag[t]) // 이미 방문한 점이면 다시 pop 진행
            continue;   
        cout<<t<<" ";
        flag[t] = 1;
        for(int i=point[t].size()-1;i>=0;i--){
            if(!flag[point[t][i]]){
                st.push(point[t][i]);
            }
        }
    }
    cout<<'\n';
    
    fill_n(flag,N,0);
    
    qu.push(start);
    while(!qu.empty()){
        int t = qu.front();
        qu.pop();
        if(flag[t])
            continue;
        cout<<t<<" ";
        flag[t] =1;
        for(int i=0;i<point[t].size();i++){
            if(!flag[point[t][i]]){
                qu.push(point[t][i]);
            }
        }
    }
    
    cout<<'\n';
    return 0;
}
