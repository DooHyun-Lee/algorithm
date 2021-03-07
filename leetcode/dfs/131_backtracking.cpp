class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
  
  
    bool isPalindrome(const string& s, int l, int r) {
     while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }
    void dfs(string s,int start,vector<string>& path ,vector<vector<string>>& ans){
        if(start == s.length()){
            ans.push_back(path);
        }
        for(int i =start; i<s.length();i++){
            if(ispalindrome(s,start,i)){
                path.push_back(s.substr(start,i-start+1));
                dfs(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        dfs(s,0,path,ans);
        return ans;
    }
};
