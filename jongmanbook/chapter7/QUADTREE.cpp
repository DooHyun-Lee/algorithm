#include<iostream>
#include<vector>
#include<string>

using namespace std;

string reverse(string::iterator &it){
    char head = *it;
    it++;
    if(head == 'b' || head == 'w')
        return string(1,head);
    string uleft = reverse(it);
    string uright = reverse(it);
    string lleft = reverse(it);
    string lright = reverse(it);
    return string("x") + lleft + lright + uleft + uright;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;  cin>>t;
    while(t--){
        string str;     cin>>str;
        string::iterator it = str.begin();
        cout<<reverse(it)<<'\n';
    }
    return 0;
}
