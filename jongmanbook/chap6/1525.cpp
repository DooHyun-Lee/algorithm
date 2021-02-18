#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

queue<int> qu;
map<int,int> dist;  // 상태, 경로길이 저장
int movex[4] = {1,-1,0,0};
int movey[4] = {0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m=0;  
    for(int i=0;i<9;i++){
        cin>>n;
        if(!n)  n = 9;
        m = 10*m + n;
    }
    qu.push(m);
    while(!qu.empty()){
        int temp = qu.front(); qu.pop();
        if(temp == 123456789){
            cout<<dist[temp]<<'\n';   return 0;
        }
        string s = to_string(temp);
        int zero = s.find('9'); // 뽑아낸 숫자에서 9, 즉 0 의 위치를 추출
        int y = zero/3; int x = zero%3;
        for(int i=0;i<4;i++){
            int ny = y+movey[i];    int nx = x+movex[i];
            if(ny>=3 || ny<0 || nx>=3 || nx<0)  continue;   // 범위밖으로 나가면 다른 경우
            int nextzero = 3*ny+nx;
            string ns = s;
            swap(ns[zero],ns[nextzero]);   // 원래 0이 였던 것과 새로운 0이 갈 원소 둘 swap
            int next = stoi(ns);
            if(!dist[next]){
                dist[next] = dist[temp]+1;
                qu.push(next);
            }
        }
    }
    cout<<"-1\n";
    return 0;
}
