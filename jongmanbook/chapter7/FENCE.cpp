#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int findarea(int start,int end,vector<int> vec){
    if(start == end)    return  vec[start];
    int mid = (start+end)/2;
    int ret = max(findarea(start,mid,vec),findarea(mid+1,end,vec));
    int left = mid; int right = mid+1;
    int height = min(vec[left],vec[right]);
    ret = max(ret,2*height);
    while(left>start && right<end){
        if(right<end && (left == start || vec[left-1]<vec[right+1])){
            ++right;
            height = min(height,vec[right]);
        }
        else{
            --left;
            height = min(height,vec[left]);
        }
        ret = max(ret,(right-left +1)*height);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            int temp;   cin>>temp;
            vec[i] = temp;
        }
        cout<<findarea(0,n-1,vec)<<'\n';
    }
    return 0;
}
