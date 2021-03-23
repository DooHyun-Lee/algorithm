#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> given;

bool nextpermutation(vector<int>& arr){
    int n = arr.size();
    int i = n-1;
    while(arr[i-1]>=arr[i])
        i--;
    if(i<=0) return false;
    int j = n-1;
    while(arr[i-1]>=arr[j])
        j--;
    swap(arr[i-1],arr[j]);
    j = n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;    j--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;  cin>>n;
    for(int i=0;i<n;i++){    
        int temp; cin>>temp;
        given.push_back(temp);
    }
    if(nextpermutation(given)){
        for(auto i:given)
            cout<<i<<' ';
    }
    else{
        cout<<-1<<'\n';
    }
    return 0;
    
}
