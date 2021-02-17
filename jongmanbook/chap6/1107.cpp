// brute force 할 수 있는지부터 계산
// 최대가 500,000 이고 각 자리수마다 최대 10가지 숫자가 올 수 있으므로 최대 10^6 번 예상
// 1초당 처리건수가 10^8 이하이므로 brute force 적용가능
// N이 500,000 일 때 모든 버튼이 막힌 경우를 생각하면 100 ~ 500,000 거리인 499,900 을 더한 999,900 이 탐색해야하는 최대 숫자
// 6자리를 넘어가지 않는다는 점에 유의

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
    for(int i=1;i<7;i++)  // 앞서 분석한 대로 1자리에서 6자리의 수를 구성후 변수 goal 에 얼마나 가까운지 result 에 저장
        findmin(0,0,i);
    cout<<min(result,abs(goal-100))<<'\n';
    return 0;
}
