#include<iostream>
#include<vector>

using namespace std;

int tiles[4][3][2] = {{{0,0},{0,1},{1,0}},{{0,0},{0,1},{1,1}},{{0,0},{1,0},{1,1}},{{0,0},{1,0},{1,-1}}};  // p. 162 그림 참조

bool set(vector<vector<int>> &vec,int y,int x,int type,int delta){  // type: 블록 모양 , delta: 추가 or 제거
    bool ok = true;
    for(int i=0;i<3;i++){
        int ny = y+ tiles[type][i][0];
        int nx = x+ tiles[type][i][1];
        if(ny<0 || ny>=vec.size() || nx<0 || nx>=vec[0].size())     // 조각일부가 판 벗어날 경우 false 판별
            ok = false;
        else if((vec[ny][nx]+=delta)>1)       // 블록 가려는 부분이 이미 덮인 판인 경우 2 이상으로 만들고 false 판별
            ok = false;
    }
    return ok;
}

int cover(vector<vector<int>> &vec){
    int y = -1, x = -1;
    for(int i = 0;i<vec.size();i++){
        for(int j =0;j<vec[i].size();j++){
            if(vec[i][j]==0){
                y = i;  x = j;
                break;
            }
        }
        if(y != -1)
            break;
    }
    if(y==-1)   return 1;   // 모두 채원진 default case
    int ret = 0;
    for(int type = 0;type<4;type++){
        if(set(vec,y,x,type,1)){    // 해당 모양 블록이 가능할 경우 깊숙히 탐색하여 ret 에 추가
            ret += cover(vec);
        }
        set(vec,y,x,type,-1);   // 다른 경우 탐색을 위해 블록 걷어내는 작업
    }
    return ret;
}

vector<int> ans;

void vecprinter(vector<vector<int>> vec){
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[0].size();j++)
            cout<<vec[i][j];
        cout<<endl;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;  cin>>c;
    while(c--){
        int h,w;    cin>>h>>w;
        vector<vector<int>> vec(h);
        for(int i=0;i<h;i++){
            string str; cin>>str;
            for(int j=0;j<w;j++){
                if(str[j]=='#')
                    vec[i].push_back(1);    // 검은색이 1
                else
                    vec[i].push_back(0);    // 흰색이 0
            }
        }
        ans.push_back(cover(vec));
    }
    for(auto i:ans)
        cout<<i<<'\n';

    return 0;
}
