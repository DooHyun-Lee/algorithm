#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> path;
vector<int> heights;
vector<int> ans;

void search(vector<int>& path, int lastidx,int heightsum){
    if(path.size() == 7 && heightsum == 100){
        ans = path;
        return;
    }
    if(path.size()>7 || heightsum>100)  return;
    for(int i=lastidx+1;i<9;i++){
        path.push_back(heights[i]); 
        heightsum += heights[i];
        search(path,i,heightsum);
        path.pop_back();
        heightsum -= heights[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    heights.assign(9,0);
    for(int i=0;i<9;i++)
        cin>>heights[i];
    search(path,-1,0);
    sort(ans.begin(),ans.end());
    for(auto i:ans)
        cout<<i<<'\n';
    return 0;
}
