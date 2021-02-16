#include<iostream>
#include<vector>
using namespace std;

int findways(bool isfriend[10][10],bool visited[10],int num){
    // base case 
    int first = -1;
    int ret = 0;
    for(int i=0;i<num;i++){
        if(!visited[i]){
            first = i;
            break;
        }
    }
    if(first == -1)
        return 1;
    for(int i = first+1;i<num;i++){
        if(isfriend[first][i] && !visited[i]){  // 둘이 친구이고 아직 배정안된 경우
            visited[i] = visited[first] = true; // 둘이 엮어졌다고 가정 후 
            ret += findways(isfriend,visited,num);  // 이후의 케이스들을 진행
            visited[i] = visited[first] = false;    // 나머지 계속 탐색을 위해 다시 안만난 것으로 초기화
        }
    }
    return ret;
}

vector<int> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;  cin>>c;
    while(c--){
        bool isfriend[10][10] = {false};
        bool visited[10] = {false};
        int n,m;    cin>>n>>m;
        for(int i=0;i<m;i++){
            int a,b;    cin>>a>>b;
            isfriend[a][b] = true;
            isfriend[b][a] = true;
        }
        ans.push_back(findways(isfriend,visited,n));
    }
    for(auto i:ans)
        cout<<i<<'\n';
    return 0;
}
