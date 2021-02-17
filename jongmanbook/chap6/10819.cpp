// brute force 사용가능 여부부터 조사
// 최대 경우 N 8 이므로 8! 가지 경우에 대해 수식으로 주어진합을 구하는데 최대 8 번의 방문
// 1초당 처리 회수가 10^8 이므로 brute force 사용가능

// 이 문제에서는 next_permutation 사용법에 초점

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<int> vec;

int findabs(vector<int> vec){
    int ret = 0;
    for(int i=0;i<vec.size()-1;i++){
        ret+=abs(vec[i]-vec[i+1]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;  cin>>n;
    for(int i=0;i<n;i++){
        int temp;   cin>>temp;
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());
    int ans = 0;
    do{
        ans = max(ans,findabs(vec));
    }while(next_permutation(vec.begin(),vec.end()));  //  다음 permutation 이 완전 내림차순 일 때 false 반환

    cout<<ans<<'\n';
    return 0;
}
