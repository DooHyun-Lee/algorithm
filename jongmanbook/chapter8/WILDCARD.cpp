    #include<string>
    #include<iostream>
    #include<vector>
    #include<cstring>
    #include<algorithm>

    using namespace std;

    int cache[101][101];

    bool match(string wild,string str,int w,int s){
        int ret = cache[w][s];
        if(ret != -1)   return ret;
        while(w<wild.size() && s<str.size() && (wild[w] == str[s] || wild[w] == '?')){
            w++;    s++;
        }
        if(w == wild.size())
            return ret = (s==str.size());
        if(wild[w] == '*'){
            for(int step = 0;step+s<=str.size();step++){  // 이 step+s 가 str.size() 까지 넘어가야 하는 이유 * 관련 생각해보기
                if(match(wild,str,w+1,s+step))
                    return ret = 1;   // 다음 w+1,s+step 에서 성공하면 match에 해당하므로 return으로 반환
            }
        }
        return ret = 0;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t;  cin>>t;
        while(t--){
            vector<string> ans;
            vector<string> arr;
            string wild, str;   int n;
            cin>>wild;  cin>>n;
            for(int i=0;i<n;i++){
                string temp;
                cin>>temp;    arr.push_back(temp);
            }
            for(auto i:arr){
                memset(cache,-1,sizeof(cache));
                if(match(wild,i,0,0))
                    ans.push_back(i);
            }
            sort(ans.begin(),ans.end());
            for(auto i:ans)
                cout<<i<<'\n';
        }
        return 0;
    }
