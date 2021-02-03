#include<iostream>
#include<string>
using namespace std;

int count[5001];    // 각 자리의 암호 해석 가능 개수를 저장하는 배열 & index 1부터 사용
int num[5001];  // 입력받은 숫자를 각 자리별로 저장 & index 1부터 사용

int main(){
    
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++){
        num[i+1] = str[i] - '0';
    }
    
    count[0] = 1;
    for(int i=1;i<=str.length();i++){
        if(num[i]>0)
            count[i] = count[i-1] % 1000000;
        if(num[i-1]==1 || (num[i-1]==2 && num[i]<=6))
            count[i] = (count[i]+count[i-2]) % 1000000;
    }
    printf("%d\n",count[str.length()]%1000000);
}
