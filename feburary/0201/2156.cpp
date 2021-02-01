#include<iostream>

#define N 10001

using namespace std;

int arr[N];
int count[N];

int max(int a,int b,int c){
    int big = a>=b?a:b;
    return big>=c?big:c;
}

int main(){
    int num;       cin>>num;
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i+1]);
    }
    count[1] = arr[1];
    count[2] = arr[2]+arr[1];
    for(int i=3;i<=num;i++){
        count[i] = max(count[i-1],arr[i]+count[i-2],arr[i]+arr[i-1]+count[i-3]);
        // 끝에 0개 , 끝에 1개, 끝에 2개 마실 경우 중 최대값 선정
    }
    printf("%d\n",count[num]);
    return 0;
}