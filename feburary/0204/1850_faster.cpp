// basically same thing but faster printing


#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char ans[5000001];

long long gcd(long long a,long long b){ //assume a is bigger than b
    return b?gcd(b,a%b):a;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long a,b,val;
    cin>>a>>b;
    val = gcd(a,b);
    memset(ans,'1',val);
    puts(ans);
    return 0;
}
