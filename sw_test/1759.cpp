#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 987654321
#define MIN -987654321

int l,c;
vector<char> str;
vector<char> path;
int v,o;

bool isv(char c){
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

void findall(int cur,int cnt,vector<char>& path){
    if(cnt == l){
        if(v>=1 && o>=2){
            for(auto i:path)    cout<<i;
            cout<<'\n';
        }
        return;
    }
    for(int i = cur+1;i<c;i++){
        path.push_back(str[i]);
        if(isv(str[i])) v++;
        else o++;
        findall(i,cnt+1,path);
        path.pop_back();
        if(isv(str[i])) v--;
        else o--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>l>>c;
    for(int i=0;i<c;i++){
        char ctmp;  cin>>ctmp;
        str.push_back(ctmp);
    }
    sort(str.begin(),str.end());
    for(int i=0;i<=c-l;i++){
        v = o = 0;
        if(isv(str[i])) v++;
        else o++;
        path.push_back(str[i]);
        findall(i,1,path);
        path.pop_back();
        if(isv(str[i])) v--;
        else o--;
    }
    return 0;
}   
