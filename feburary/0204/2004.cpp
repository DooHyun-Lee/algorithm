#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
#define N 1000001

int fives(int n){ // a 이상 b 이하에서 5의 인수개수 count
    int count = 0;
    while(n>0){
        n /= 5;
        count += n;
    }
    return count;
}

int twos(int n){
    int count = 0;
    while(n>0){
        n /= 2;
        count += n;
    }
    return count;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n,m;    cin>>n>>m;
    cout<<min(fives(n)-fives(m)-fives(n-m),twos(n)-twos(m)-twos(n-m))<<'\n';
    return 0;
    
}
