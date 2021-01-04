#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stack>
using namespace std;

bool flag[1001] = {false};

class Number{
public:
    int n;
    set<int> s;
    Number(int num):n(num){}
};

void bfs(vector<Number> vec,int V){
    queue<Number> qu;
    qu.push(vec[V]);
    while(!qu.empty()){
        Number temp = qu.front();
        qu.pop();
        if(!flag[temp.n]){  // 안 거친 노드에 대해서만 아래의 과정을 수행
        flag[temp.n] = true;    // 한번 거친 node는 true로 표기
        for(auto k = temp.s.begin(); k!=temp.s.end();k++){
            if(!flag[*k]){  // temp 가 가진 set(인접) 목록 중 아직 안거친 false 에 대해서만 push
                qu.push(vec[*k]);
            }
        }
        cout<<temp.n<<" ";
        }
    }
}

/*void dfs(vector<Number> vec,int V){
    stack<Number> st;
    st.push(vec[V]);
    flag(vec[V].n) = true;
    cout<<V<<" ";
    // 계속 인접한 노드들이 존재하는 동안
    while(!st.empty()){
        bool indicator = false; // 인접한 node 중 탐색되지 않은 노드를 추가했는지 여부 판단
        Number temp = st.top();
        if(!temp.s.empty()){    // 스택 꼭대기와 연결된 node들이 존재할 경우
        for(auto k = temp.s.begin();k!=temp.s.end();k++){
            if(!flag[*k]){
                st.push(vec[*k]);
                flag([*k]) = true;  // 탐색 되었음 
                cout<<*k<<" ";
                indicator = true;
                break;  // 인접한 node 중 탐색되지 않은 가장 작은 것을 stack에 추가
            }
        }   
        }
        if(!indicator){ // 탐색되지 않은 노드가 없을 경우 
            st.pop();
        }
    }
    
}*/


void dfs(vector<Number>& vec,int V){    // vec 을 계속 복사해서 쓰지 않기 위해 참조형으로 선언
    flag[vec[V].n] = true;
    cout<<vec[V].n<<" ";

    bool result = true;
    // set의 전체 flag 가 모두 true일 때 base condition
    for(auto k = vec[V].s.begin(); k!=vec[V].s.end(); k++){
        result = result && flag[*k];
        if(!flag[*k]){  
                break;  // 하나라도 false 면 탈출
            }
        
    }
    if(result)
        return;

    for(auto k = vec[V].s.begin(); k!=vec[V].s.end(); k++){
        if(!flag[*k]){  
                dfs(vec, *k);
            }
    }
}


int main(){
    int N,M,V;
    cin>>N>>M>>V;
    vector<Number> vec;
    for(int i=0;i<=N;i++){
        vec.push_back(Number(i));
    }
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        vec[a].s.insert(b);
        vec[b].s.insert(a);
    }
    dfs(vec,V);
    printf("\n");
    for(int i=0;i<=M;i++)   // flag 초기화 과정
        flag[i] = false;

    bfs(vec,V);
    printf("\n");


    return 0;
}