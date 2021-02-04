#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#define N 1001

using namespace std;

stack<int> st;
vector<vector<int>> vec(N);

int flag[N];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int e,v;    cin>>e>>v;
    for(int i=0;i<v;i++){
        int a,b;    cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int left = e;   //  아직 방문되지 않은 점의 개수 표시
    int count = 0; //   총 연결 개수 표시
    int start;
    while(left){   //  남은 점이 한개도 없는 경우까지
        for(int i=1;i<=e;i++){
            if(flag[i]==0){ // 아직 방문되지 못한 부분이 있으면 start로 설정 후 dfs 사이클 시작
            start = i;
            break;
            }
        }
        st.push(start);
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(flag[t])     // 이미 방문한 경우 아래 남은 과정 모두 생략
                continue;
            flag[t] = 1;
            left--;
            for(int i=0;i<vec[t].size();i++){
                if(!flag[vec[t][i]]){   // 연결된 점 중 아직 방문이 안되었다면
                    st.push(vec[t][i]);
                }
            }
        }
        count++;    // 서로 연결된 점끼리 한바퀴 돌았을 떄
    }
    cout<<count<<'\n';
    return 0;
}



