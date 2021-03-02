class Solution {
public:
    
    void maxpalindrome(int left, int right,int &maxlen,int& start,string s){
        while(left>=0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        if(maxlen<right-left-1){
            start = left+1;
            maxlen = right -left-1;
        }
    }
    
    string longestPalindrome(string s) {
        if(s.length()<2)    return s;
        int start,maxlen;
        start = maxlen = 0;
        for(int i=0;i<s.length();i++){
            maxpalindrome(i,i,maxlen,start,s);
            maxpalindrome(i,i+1,maxlen,start,s);
        }
        return s.substr(start,maxlen);
    }
};
