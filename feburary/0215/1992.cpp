#include<iostream>
#define N 65

using namespace std;

int arr[N][N];

void video(int x,int y,int size){
    int fir = arr[y][x];
    if(size ==1){
        cout<<fir;
        return;
    }
    for(int i = y;i<y+size;i++){
        for(int j = x;j<x+size;j++){
            if(fir != arr[i][j]){
                cout<<"(";  // 분할해야 할 경우만 괄호 출력하는 성질 반영
                for(int q = 0;q<2;q++){
                    for(int p=0;p<2;p++){
                        video(x+p*(size/2),y+q*(size/2),size/2);    // 사분면 탐색 순서 주의!
                    }
                }
                cout<<")";
                return;   // 일치하지 않는 원소 존재경우 함수 종료조건 주의
            }
        }
    }
    cout<<fir;      // 모든 원소가 일치하는 경우 
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;    cin>>num;
    for(int i=1;i<=num;i++){
        string str;
        cin>>str;
        for(int j=0;j<str.length();j++){
            arr[i][j+1] = str[j] - '0';
        }
    }
    video(1,1,num);
    return 0;
}
