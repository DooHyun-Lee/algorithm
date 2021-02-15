// 직접 버블 정렬시 제한시간 초과하므로 merge sort를 진행하며 이미 정렬되어있는 두 쌍의 배열에 대해 각각을 가리키는 index 를 각각 i,j라 할 경우
// arr[i] ~ arr[mid] 까지의 원소들은 모두 arr[j] 보다 클 것이므로 arr[j]는 이 수들 만큼의 swap 을 해야 한다. (bubble sort를 할 경우)
// 그러므로 arr[i]> arr[j] 일 경우 mid-i+1 만큼씩 더해준다.

#include<iostream>
#include<vector>
#define N 500001
using namespace std;

long long scount;
int arr[N];


void merge(int start,int mid,int end){
    int temp[end-start+1];
    int i = start;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j])    // 같은 원소 입력이 있을 수 있으므로 이 경우 count 를 하지 않기 위해 
            temp[k++] = arr[i++];
        else
        {
            scount += mid-i+1;
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid)   temp[k++] = arr[i++];
    while(j<=end)   temp[k++] = arr[j++];
    for(i=start,j = 0;i<=end;i++,j++)
        arr[i] = temp[j];
}


void sort(int start,int end){
    if(start<end){    // base case 도달 시 종료를 알리기 위해
    int mid = (start+end)/2;
    sort(start,mid);
    sort(mid+1,end);
    merge(start,mid,end);
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;    cin>>num;
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    sort(0,num-1);
    cout<<scount<<'\n';
    return 0;
}
