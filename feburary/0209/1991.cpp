#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<utility>
#define N 27
using namespace std;

vector<pair<int,int>> vec(27);  // 1 idx 시작

void prefix(){  // dfs 와 동일
    stack<int> st;
    st.push(1);
    while(!st.empty()){
        int t = st.top();
        cout<<(char)(t+64);
        st.pop();
        if(vec[t].second!=0)
            st.push(vec[t].second);
        if(vec[t].first!=0)
            st.push(vec[t].first);
    }
}

void inorder(int t){
    
    if(vec[t].first)    inorder(vec[t].first);
    cout<<(char)(t+64);
    if(vec[t].second)   inorder(vec[t].second);
    
    
}

void postorder(int t){

    if(vec[t].first)    postorder(vec[t].first);
    if(vec[t].second)    postorder(vec[t].second);
    cout<<(char)(t+64);
    
} 


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;  cin>>n;
    for(int i=0;i<n;i++){
        char temp;  cin>>temp;
        char a,b;   cin>>a>>b;
        if(a=='.')  a = 64;
        if(b=='.')  b = 64;
        vec[(int)temp-64] = make_pair((int)a-64,(int)b-64);
    }
    
    prefix();   cout<<'\n';
    inorder(1); cout<<'\n';
    postorder(1);   cout<<'\n';
    
    /*for(int i=1;i<=N;i++){
        cout<<arr[i]<<' ';
    }*/
    return 0;
}


