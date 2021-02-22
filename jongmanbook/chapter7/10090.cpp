#include<iostream>
#include<vector>
#define MAX 1000001
using namespace std;

int arr[MAX];
long long cnt = 0;
// 병합 정렬하면서 inversion 된 횟수와 동일 

void merge(int start,int end){      // start ~ mid & mid ~ end 가 각각 정렬되어있다고 가정
    int temp[end-start+1];
    int mid = (start+end)/2;
    int left = start;   int right = mid+1;  int idx = 0;
    while(left<=mid && right <= end){
        if(arr[left]<=arr[right])
            temp[idx++] = arr[left++];
        else{
            temp[idx++] = arr[right++];
            cnt += mid-left+1;  // 작은게 큰 거 앞으로 올 때 왼쪽 부분에 남아있는 원소만큼 count
        }
    }

    int idx2 = left>mid? right : left;
    while(idx<end-start+1)
        temp[idx++] = arr[idx2++];

    for(int i=0;i<(end-start+1);i++){
        arr[start+i] = temp[i];
    }
}

void merge_sort(int start,int end){
    int mid = (start+end)/2;
    if(start<end){
        merge_sort(start,mid);
        merge_sort(mid+1,end);
        merge(start,end);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;  cin>>n;

    for(int i=0;i<n;i++){       // 1 ~ n 까지 index 사용
        cin >> arr[i+1];
    }
    merge_sort(1,n);
    cout<<cnt<<'\n';
}
