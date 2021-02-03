#include<iostream>
#include<string>
#include<stack>
#define N 100001

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str; cin>>str;
    stack<int> st;
    int count = 0;  // 총 조각 개수
    for(int i=0;i<str.length()-1;i++){  // (i+1) idx 접근을 안전하게 하기 위해서
        if(str[i]=='(' && str[i+1] != ')'){ // 레이저 아닌 나무조각
            st.push(0);    // 0은 그냥 indicator
            count++;
        }
        else if(str[i]=='(' && str[i+1]== ')'){  // 레이저 의미
            count += st.size();
            i = i+1;    // 다음 것을 이미 검사했으므로 
        }
        else if(str[i]==')'){
            st.pop();
        }
    }
    cout<<count<<"\n";
    return 0;
}


// 입력이 레이저인 경우 stack 에 있는 막대수만큼 count를 증가시키고 입력이 막대 출발인 경우 stack 과 count 1씩 증가, 막대 끝인 경우 stack 에서 제거
