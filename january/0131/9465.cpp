#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

#define TOT 100001

using namespace std;

int arr[2][TOT];
int Count[2][TOT];
vector<int> result;

int sticker(int n){
    for(int i=3;i<=n;i++){
        Count[0][i] = max(Count[1][i-2],Count[1][i-1]) + arr[0][i]; // count[0][i-2] 고려하지 않는 이유 -> count[1][i-1] 경로에 포함되므로 무조건 더 작음
        Count[1][i] = max(Count[0][i-2],Count[0][i-1]) + arr[1][i];
    }
    return max(Count[0][n],Count[1][n]);    
}


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        for(int j=0;j<2;j++){
            for(int k=1;k<=n;k++){
                scanf("%d",&arr[j][k]);
            }
        }
        memset(Count,0,sizeof(Count));
        Count[0][1] = arr[0][1];
        Count[1][1] = arr[1][1];
        Count[0][2] = arr[0][2] + Count[1][1];
        Count[1][2] = arr[1][2] + Count[0][1];  // 위의 for문에서 i-2 하면 out of bound
        result.push_back(sticker(n));
    }
    for(int i=0;i<t;i++){
        printf("%d\n",result[i]);
    }
    return 0;
}
