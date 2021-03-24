#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int result = 987654321;
int goal;   // 목표하는 채널
int err[10];
vector<int> okay;   // 괜찮은 버튼 모음

void findmin(int cnt,int value,int num){    // cnt: 몇 번 했는지 카운트, value: 현재 채널, num: 몇 자리수 만들건지
    if(cnt == num){
        result = min(result,abs(goal-value)+num);
        return;
    }
    for(int i=0;i<okay.size();i++){
        findmin(cnt+1,10*value+okay[i],num);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>goal;
    int m;  cin>>m;
    for(int i=0;i<m;i++){
        int temp;   cin>>temp;
        err[temp] = 1;
    }    
    for(int i=0;i<10;i++){
        if(!err[i])
            okay.push_back(i);
    }
    for(int i=1;i<7;i++)
        findmin(0,0,i);
    cout<<min(result,abs(goal-100))<<'\n';
    return 0;
}
