#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vec;

long long gcd(long long a,long long b){ //assume a is bigger than b
    return b?gcd(b,a%b):a;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int test;   cin>>test;
    while(test--){
    long long result=0;
    int testnum;    cin>>testnum;
    for(int i=0;i<testnum;i++){
        int in; cin>>in;
        vec.push_back(in);
    }
    for(int i=0;i<testnum;i++){
        for(int j=i+1;j<testnum;j++){
            result += gcd(vec[i],vec[j]);
        }
    }
    cout<<result<<'\n';
    vec.clear();
    }
    return 0;
    
    
}
