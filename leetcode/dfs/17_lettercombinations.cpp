class Solution {
public:
    
    vector<string> dic{"","","abc","def","ghi","jkl","mno", "pqrs", "tuv", "wxyz"};
    queue<string> path;
    
    void dfs(int start,string digits,queue<string>& path){
        if(start == digits.length()-1){
            int idx = digits[start] - '0';
            for(int i=0;i<dic[idx].length();i++){
                string s;   s += dic[idx][i];
                path.push(s);
            }
            return;
        }
        dfs(start+1,digits,path);
        int cursize = path.size();
        for(int i=0;i<cursize;i++){       // 원래 있던 원소들에 새로운 start 번 알파벳 결합한 단어들을 
            string stemp = path.front();
            path.pop();
            
            int idx = digits[start] - '0';
            for(int j= 0;j<dic[idx].length();j++){
                string s;   s += dic[idx][j];
                path.push(s + stemp);
            }
        }
        
    }
    
    vector<string> letterCombinations(string digits){
        if(!digits.length()) return {};
        vector<string> vec;
        dfs(0,digits,path);
        while(!path.empty()){
            string s = path.front();
            path.pop();
            vec.push_back(s);
        }
        return vec;
    }
};
