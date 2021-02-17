// queue를 이용한 bfs 적용 
// 각 수 다음으로 올 수 있는 4*10 가지 경우에 대해 방문하지 않은 경우 && 소수일 경우 queue에 넣어 다음 단계로
// 각 단계마다 while(sz--) 로 구분지어 단계 진행에 따른 회수 계산


#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

bool nextprime(int n){
    if((n&1)==0)
        return n==2;
    for(int i=3;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;  cin>>t;
    while(t--){
        bool visited[9000] = {false};   // 해당 소수 방문여부
        int start,end,cnt =0,num[4];  cin>>start>>end;
        bool flag = false;
        queue<int> qu;
        qu.push(start);
        visited[start-1000] = true;
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                int temp = qu.front();  qu.pop();
                if(temp == end){
                    flag = true;    break;
                }
                for(int i=0;i<4;i++){
                    int j;
                    for(i==0? j = 1:j=0;j<10;j++){
                        num[0] = temp/1000;
                        num[1] = (temp%1000)/100;
                        num[2] = ((temp%1000)%100)/10;
                        num[3] = temp%10;
                        num[i] = j;
                        int nextnum = num[0]*1000+num[1]*100+num[2]*10+num[3];
                        if(!visited[nextnum-1000] && nextprime(nextnum)){
                            visited[nextnum-1000] = true;
                            qu.push(nextnum);
                        }
                    }
                }
            }
            if(flag)    break;
            cnt++;
        }
        flag? cout<<cnt<<'\n':cout<<"Impossible"<<'\n';
    }
}
