#include<iostream>
#include<vector>
using namespace std;

vector<int> result;

int min(int a,int b){
    return a>b?b:a;
}
// 아이디어: bottom-up 구조 & -1 -> /2 -> /3 순으로 비교
int main(){
    int num;
    int count = 0;
    cin>>num;
    result.resize(num+1,0);
    for(int i=2;i<=num;i++){
        result[i] = result[i-1]+1;
        if(i%2==0){
            result[i] = min(result[i],result[i/2]+1);
        }
        if(i%3==0){
            result[i] = min(result[i],result[i/3]+1);
        }
    }
    cout<<result[num]<<endl;
}