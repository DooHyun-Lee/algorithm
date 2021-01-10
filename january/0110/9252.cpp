#include<iostream>
#include<string>
#include<stack>

using namespace std;
int arr[1001][1001];  //(m,n) 까지 공통 문자열 개수 저장

int max(int a,int b){
    return a>b?a:b;
}

int main(){
    stack<char> st;
    string X;
    string Y;
    cin>>X; cin>>Y;

    int Xm = X.length();
    int Yn = Y.length();
    for(int i=1;i<=Xm;i++){
        for(int j=1;j<=Yn;j++){
            if(X[i-1]==Y[j-1]){     // arr 과 달리 X와 Y는 첫 원소기준이 index 0 이므로
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else{
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    printf("%d\n",arr[Xm][Yn]);
    
    int a = Xm; int b = Yn;
    while(arr[a][b]!=0){
        if(arr[a-1][b]==arr[a][b])
            a -=1;
        else if(arr[a][b-1] == arr[a][b])
            b -=1;
        else if(arr[a][b] -1 == arr[a-1][b-1]){
            st.push(X[a-1]);
            a -=1;
            b -=1;
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}