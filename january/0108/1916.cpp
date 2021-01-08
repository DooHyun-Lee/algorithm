#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
#define MAX 987654321

int dist[1001]; // 처음에는 무한대로 초기화
vector<pair<int,int>> vec[100001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;   // {거리, 정점} 형태로 저장
    dist[start] = 0;    // 시작점~시작점 거리는 0 

    pq.push(make_pair(dist[start],start));
    while(!pq.empty()){
        int distance = pq.top().first * -1;     // min heap 을 원하므로 -1 곱
        int cur = pq.top().second;
        pq.pop();

        if(distance>dist[cur])  continue;   // flag 배열 쓰는 대신 다음과 같이 필터링

        for(int i=0;i<vec[cur].size();i++){
            int next = vec[cur][i].first;
            int nextdist = distance + vec[cur][i].second;  // vec[cur] 에는 {점,거리} 로 인접 점들이 저장
            if(nextdist<dist[next]){
                dist[next] = nextdist;
                pq.push(make_pair(-nextdist,next));     // min heap 을 원하므로 -1 곱
            }
        }
    }
}

int main(){
    int n,m;
    int start,end;
    for(int i=0;i<=1000;i++){
        dist[i] = MAX;
    }
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vec[a].push_back(make_pair(b,c));
    }
    cin>>start>>end;
    dijkstra(start);
    cout<<dist[end]<<endl;

}