#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
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

char reversecalc(int a,int b){    // a->b 로 갈 때 어떤 연산을 거쳐야 하는지 return
    int numres;
    for(int i=0;i<4;i++){
        if(b == calculator(a,i)){
            numres = i;
        }
    }
    switch(numres){
        case 0:
            return 'D';
        case 1:
            return 'S';
        case 2:
            return 'L';
        case 3: 
            return 'R';
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;  cin>>t;
    while(t--){
        int start,end;  cin>>start>>end;
        queue<int> qu;  // for bfs search
        int visited[10000] = {false};  // 각 숫자가 어디에서 왔는지 역추적 기록용
        qu.push(start);
        visited[start] = 987654321;
        while(!qu.empty()){
            int temp = qu.front();  qu.pop();
            if(temp == end) break;
            for(int i=0;i<4;i++){
                int reg = calculator(temp,i);
                if(visited[reg]==0 && reg!=start){
                    qu.push(reg);    // 네가지 연산 결과를 qu에 저장
                    visited[reg] = temp;    // 어디에서 유도된 결과인지 기록
                }
            }
        }
        stack<char> ans;
        int current = end;
        int prev = visited[current];
        while(prev!=987654321){
            ans.push(reversecalc(prev,current));
            current = prev;
            prev = visited[prev];
        }
        while(!ans.empty()){
            cout<<ans.top();
            ans.pop();
        }
        cout<<'\n';
    }
}
