#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

float cache[105][55];
int arr[105][55];
int deg[51];    // i 번째 마을 차수 계산
int n,d,p;  // 마을 개수, 지난 일수, 교도소 번호

void memsetf(float cache[105][55]){
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++)
            cache[i][j] = -1;
    }
}

void degcalc(int deg[51]){
    for(int i=0;i<n;i++){
        int result = 0;
        for(int j=0;j<n;j++){
            if(arr[i][j])
                result++;
        }
        deg[i] = result;
    }
}

float percentage(int day,int num){    // 마을 num에 day 지난 후 있을 확률
    if(day == 0)
        return num == p ? 1: 0;
    float& ret = cache[day][num];
    if(ret > -0.5 )   return ret;
    ret = 0.0;
    for(int i=0;i<n;i++){
        if(arr[num][i]){
            ret += (percentage(day-1,i) / deg[i]);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;  cin>>c;
    while(c--){
        cin>>n>>d>>p;
        memsetf(cache);
        memset(arr,0,sizeof(arr));
        memset(deg,0,sizeof(deg));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        }
        int t;  cin>>t;
        vector<int> vec;    // 확률이 궁금한 마을번호들이 들어있음
        for(int i=0;i<t;i++){
            int temp;   cin>>temp;
            vec.push_back(temp);
        }
        degcalc(deg);
        for(int i=0;i<vec.size();i++){
            cout<<percentage(d,vec[i])<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
