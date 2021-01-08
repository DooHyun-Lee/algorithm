    #include<iostream>
    #include<queue>
    #include<vector>
    #include<utility>

    #define MAX 2147483640

    using namespace std;

    int dist[801];
    vector<pair<int,int>> vec[801];

    int dijkstra(int start,int end){    // start~end 까지 최단거리 반환
        for(int i=0;i<801;i++){
            dist[i] = MAX;  // 이동거리 배열 초기화
        }
        priority_queue<pair<int,int>> pq;
        dist[start] = 0;
        pq.push(make_pair(dist[start],start));
        while(!pq.empty()){
            int distance = pq.top().first * -1;
            int cur = pq.top().second;
            pq.pop();
            if(distance>dist[cur])  continue;
            for(int i=0;i<vec[cur].size();i++){
                int nextdist = distance + vec[cur][i].second;
                int next = vec[cur][i].first;
                if(nextdist<dist[next]){
                    dist[next] = nextdist;
                    pq.push(make_pair(-dist[next],next));
                }
            }
        }
        return dist[end];
    }

    int main(){
        int N,E;
        cin>>N>>E;
        for(int i=0;i<E;i++){
            int a,b,c;
            cin>>a>>b>>c;
            vec[a].push_back(make_pair(b,c));
            vec[b].push_back(make_pair(a,c));   // (a ~ b) 와 (b ~ a) 양방향임에 주의
        }
        int mid1,mid2;
        cin>>mid1>>mid2;
        int result1,result2,result3,result1_p,result2_p,result3_p;  // 이 부분 중요 !! mid1->mid2 와 mid2->mid1 모두 고려
        result1 = dijkstra(1,mid1);
        result2 = dijkstra(mid1,mid2);
        result3 = dijkstra(mid2,N);
        result1_p = dijkstra(1,mid2);
        result2_p = dijkstra(mid2,mid1);
        result3_p = dijkstra(mid1,N);

        bool mid1mid2 = (result1==MAX || result2 == MAX || result3 == MAX);
        bool mid2mid1 = (result1_p == MAX || result2_p == MAX || result3_p == MAX);
        
        if(mid1mid2){
            if(mid2mid1)
                printf("-1\n");
        
            else
                printf("%d\n",result1_p+result2_p+result3_p);
        }
        else if(!mid1mid2){
            if(mid2mid1)
                printf("%d\n",result1+result2+result3);
            else{
                int result = result1+result2+result3>result1_p+result2_p+result3_p ? result1_p+result2_p+result3_p
                : result1+result2+result3;
                printf("%d\n",result);
        }
        return 0;
    }
    }