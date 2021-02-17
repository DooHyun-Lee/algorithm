#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<stack>

using namespace std;

int calculator(int num,int mod){
    int arr[4];
    switch (mod)
    {
    case 0: // D
        return 2*num>9999?(2*num)%10000:2*num;
        break;
    case 1: // S
        return num==0?9999:num-1;
        break;
    case 2: // L
        arr[0] = num/1000;
        arr[1] = (num%1000)/100;
        arr[2] = ((num%1000)%100)/10;
        arr[3] = num%10;
        return arr[1]*1000+arr[2]*100+arr[3]*10+arr[0];
        break;
    case 3: // R
        arr[0] = num/1000;
        arr[1] = (num%1000)/100;
        arr[2] = ((num%1000)%100)/10;
        arr[3] = num%10;
        return arr[3]*1000+arr[0]*100+arr[1]*10+arr[2];
        break;
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;  cin>>t;
    while(t--){
        int start,end;  cin>>start>>end;
        bool visited[10000] = {false};
        queue<pair<int,string>> qu;  // for bfs search
        qu.push(make_pair(start,""));
        visited[start] = true;
        while(!qu.empty()){
            auto temp = qu.front();  qu.pop(); 
            if(temp.first == end){
                cout<<temp.second<<'\n';
                break;
            }
            for(int i=0;i<4;i++){
                int reg = calculator(temp.first,i);
                if(visited[reg]==0){
                    switch(i){
                        case 0: 
                        qu.push(make_pair(reg,temp.second+"D"));  // 여태까지 해온 경로에 이어붙이기
                        break;
                        case 1:
                        qu.push(make_pair(reg,temp.second+"S"));
                        break;
                        case 2:
                        qu.push(make_pair(reg,temp.second+"L"));
                        break;
                        case 3:
                        qu.push(make_pair(reg,temp.second+"R"));
                        break;
                    }
                    visited[reg] = true;    // 어디에서 유도된 결과인지 기록
                }
            }
        }
    }
}
