//https://casterian.net/archives/92 참조

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

struct Point{
  int x,y;  
};

int dist(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}

struct Comp{
    bool x_or_y;
    Comp(bool x) : x_or_y(x) {}
    bool operator()(Point a, Point b){  // true 이면 x 오름차순, false 이면 y 오름차순
        return (this->x_or_y ? a.x < b.x : a.y < b.y);
    }
};

int closest_pair(vector<Point>::iterator it,int n){
    if(n==2)
        return dist(it[0],it[1]);
    if(n==3)
        return min({dist(it[0], it[1]), dist(it[1], it[2]), dist(it[2], it[0])});
    int line = (it[n/2].x+it[n/2-1].x)/2;   // x 좌표의 중간지점에 선을 긋는다.
    int d = min(closest_pair(it,n/2),closest_pair(it+n/2,n-n/2));    // min x ~ 중간 || 중간 ~ 끝 중 최소쌍]

    vector<Point> mid;  // 중간지점에 걸치는 점들을 고려해주기 위한 저장공간
    for(int i=0;i<n;i++){
        int t = it[i].x - line;
        if(t*t<d){      // 위에서 그린 중간 선에서 거리가 d 이하인 점들만 계산해주기
            mid.push_back(it[i]);
        }
    }
    sort(mid.begin(),mid.end(),Comp(false));    // y 좌표 기준으로 정렬하여 밑에서부터 서로 거리 측정
    int mid_sz = mid.size();
    for(int i=0;i<mid_sz -1;i++){
        for(int j = i+1;j<mid_sz && (mid[i].y - mid[j].y)*(mid[i].y - mid[j].y)<d)
            d = min(d,dist(mid[i],mid[j]));
    }

    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;  cin>>n;
    vector<Point> points(n);
    for(auto it = points.begin();it != points.end();it++){
        cin >> it->x >> it->y;
    }
    sort(points.begin(),points.end(),Comp(true));   // x 좌표 기준으로 정렬 후 시작
    cout<< closest_pair(points.begin(),n) <<'\n';
    return 0;
}
