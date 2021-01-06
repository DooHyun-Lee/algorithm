#include<iostream>
#include<queue>

using namespace std;

#define MAX 100000

int flag[MAX+1];  // 경로 도달에 필요한 비용을 저장
bool check[MAX+1];  // 이미 지나온 부분인지 판단 도움

int main(){
    int N,K;    cin>>N>>K;
    queue<int> qu;
    qu.push(N);
    flag[N] = 0;
    check[N] = true;
    while(!qu.empty()){
        int ind = qu.front();
        qu.pop();
        if(ind+1<=MAX && !check[ind+1]){    // 여기서부터 갈 수 있는 세 가지 경로 모두 진행
            qu.push(ind+1);
            flag[ind+1] = flag[ind]+1;
            check[ind+1] = true;
        }
        if(ind-1<=MAX && ind-1>=0 && !check[ind-1]){
            qu.push(ind-1);
            flag[ind-1] = flag[ind]+1;
            check[ind-1] = true;
        }
        if(ind*2<=MAX && !check[ind*2]){    // 마지막 가능한 경로
            qu.push(ind*2);
            flag[ind*2] = flag[ind]+1;
            check[ind*2] = true;
        }
    }
    cout<<flag[K]<<endl;
    

}
