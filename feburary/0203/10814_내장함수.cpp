#include<iostream>
#include<utility>
#include<queue>
#include<string>

using namespace std;

struct ppl{
    int idx;
    int age;
    string name;
};

struct cmp{
    bool operator()(ppl &a,ppl &b){
        if(a.age!=b.age)
            return a.age>b.age;
        else
            return a.idx>b.idx;
    }
};

int main(){
    priority_queue<ppl,vector<ppl>,cmp> pq;
    int num;    cin>>num;
    for(int i=0;i<num;i++){
        int age;
        string name;
        scanf("%d",&age); cin>>name;
        ppl p;
        p.idx = i;  p.age = age; p.name = name;
        pq.push(p);
    }
    while(!pq.empty()){
        printf("%d %s\n",pq.top().age,pq.top().name.c_str());
        pq.pop();
    }
    
    return 0;
}
