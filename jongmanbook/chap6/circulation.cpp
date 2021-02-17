#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<int> vec;

void printvec(vector<int> path){
    for(int i=0;i<path.size();i++){
        cout<<vec[path[i]]<<' ';
    }
    cout<<'\n';
    return;
}


// vec 증에서 n 개를 고르는 circulation(오름차순 되어있다고 가정)
// path 에는 vec 에서 뽑은 index 를 저장
void printcircultation(int n,vector<int> &path,int tot){  // n :여태까지 고른 개수 , path: 고른 목록, tot: 총 목표개수
    if(n == tot)
        printvec(path);
    int smallest = path.empty() ? 0 : path.back() +1;
    for(int i= smallest;i<vec.size();i++){
        path.push_back(i);
        printcircultation(n+1,path,tot);
        path.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;  cin>>n;
    for(int i=0;i<n;i++){
        int temp;   cin>>temp;
        vec.push_back(temp);
    }
    vector<int> path;
    printcircultation(0,path,4);        // 예시, n개 중에서 4개를 뽑는 경우의 수를 print
    return 0;
}
