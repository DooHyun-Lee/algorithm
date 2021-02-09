#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#define N 100001
using namespace std;

int flag[N];


// 방식: 점 1에서 가장 먼점 탐색, 이후 그 점에서 가장 먼저 까지 거리 계산
// 1에서 가장 먼 점이 지름의 한 끝이 되는 이유?
// 지름의 한 끝이 아니라고 가정 https://stonejjun.tistory.com/149 그림 참조 시 모순!

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;  cin>>n;
    vector<vector<pair<int,int>>> vec(n+1); // (점이름, 점까지 거리) 저장
    for(int i=1;i<=n;i++){
        int point;  cin>>point;
        int a;  cin>>a;
        while(a!=-1){
            int b; cin>>b;
            vec[point].push_back(make_pair(a,b));
            cin>>a;
        }
    }
    
    vector<long long> dist(n+1,0);
    
    // 1에서 최장거리 계산
    stack<int> st;
    st.push(1); flag[1] = 1;
    int point =1;   // 1에서 가장 먼점 계산
    while(!st.empty()){
        int t = st.top();   st.pop();
        for(int i=0;i<vec[t].size();i++){
            if(!flag[vec[t][i].first]){
                st.push(vec[t][i].first);
                flag[vec[t][i].first] =1;
                dist[vec[t][i].first] = dist[t] + vec[t][i].second;
            }
        }
    }
    
   point = distance(dist.begin(),max_element(dist.begin(),dist.end()));

    fill_n(flag,n+1,0); // flag 비우고 다시 가장 먼점에서 반대쪽 지름까지 거리 계산
    for(int i=0;i<=n;i++)
        dist[i] = 0;
    st.push(point); flag[point] = 1;
    while(!st.empty()){
        int t = st.top();   st.pop();
        for(int i=0;i<vec[t].size();i++){
            if(!flag[vec[t][i].first]){
                st.push(vec[t][i].first);
                flag[vec[t][i].first] =1;
                dist[vec[t][i].first] = dist[t] + vec[t][i].second;
            }
        }
    }
    
    cout<<*max_element(dist.begin(),dist.end())<<'\n';
    
    return 0;
}


