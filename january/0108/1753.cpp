#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
#define MAX 987654321

vector<pair<int,int>> vec[20001];   // 정점 i에 대해 vec[i] 에 {정점,거리} 순으로 저장
int dist[20001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;   // {비용, 정점} 순으로 저장
    dist[start] = 0;
    pq.push(make_pair(dist[start],start));
    while(!pq.empty()){
        int distance = pq.top().first * -1; // min heap 생성을 위해
        int cur = pq.top().second;
        pq.pop();
        if(distance>dist[cur]) continue;    // flag 대신 다시 탐색할 필요 없음을 알림
        for(int i=0;i<vec[cur].size();i++){
            int nextdist = distance + vec[cur][i].second;
            int next = vec[cur][i].first;
            if(nextdist<dist[next]){
            pq.push(make_pair(-nextdist,next)); // 저장할 때도 거꾸로
            dist[next] = nextdist;
            }
        }
    }
}

int main(){
    int V,E,start;
    cin>>V>>E;
    cin>>start;

    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vec[a].push_back(make_pair(b,c));
    }

    for(int i=0;i<=20000;i++){
        dist[i] = MAX;
    }

    dijkstra(start);

    for(int i=1;i<=V;i++){
        if(dist[i]==MAX)
            cout<<"INF"<<endl;  // 이부분
        else
            cout<<dist[i]<<endl;    // 이부분 printf로 해야 시간 안에 해결 
    }

    return 0;
}
