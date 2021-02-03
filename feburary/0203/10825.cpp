#include<iostream>
#include<utility>
#include<queue>
#include<string>

using namespace std;

struct ppl{
    string name;
    int kuk,young,su;
};

struct cmp{
    bool operator()(ppl &a,ppl &b){
        if(a.kuk!=b.kuk)
            return a.kuk<b.kuk;
        else{
            if(a.young!=b.young)
                return a.young>b.young;
            else{
                if(a.su!=b.su)
                    return a.su<b.su;
                else{
                    return a.name>b.name;
                }
            }
        }
    }
};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<ppl,vector<ppl>,cmp> pq;
    int num;    cin>>num;
    for(int i=0;i<num;i++){
        ppl p;
        string name;
        int kuk,young,su;
        cin>>name>>kuk>>young>>su;
        p.name = name;  p.kuk = kuk;    p.young = young; p.su = su;
        pq.push(p);
    }
    while(!pq.empty()){
        cout<<pq.top().name<<"\n";
        pq.pop();
    }
    
    return 0;
}
