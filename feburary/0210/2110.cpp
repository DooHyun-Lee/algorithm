#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#define N 1000001
using namespace std;

int arr[N]; // 길이 정보 저장




int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,c;    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n+1);
    int left = 1; 
    int right = arr[n]-arr[1];  // 첫집과 끝집 거리를 max로 설정
    int mid,ans;
    while(left<=right){
        int cnt = 1;
        int current = arr[1];
        mid = (left+right)/2;
        for(int i=2;i<=n;i++){
            if(arr[i]-current>=mid){    // 공유기 살 수 있는 경우를 모델링
                current = arr[i];     // 지금 집을 시작으로 다시 이동하기위해
                cnt++;
            }
        }
        if(cnt>=c){     // 총 공유기 설치 회수가 목표수를 넘은 경우
            left = mid+1;
            ans = mid;
        }
        else
            right = mid-1;
    }
    cout<<ans<<'\n';
    
    return 0;
}
