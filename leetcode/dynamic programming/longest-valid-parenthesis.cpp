class Solution {
public:
    
    
    int longestValidParentheses(string s) {
    int n=s.size();
    if(n<=1)
        return 0;
    int dp[n];
    dp[0]=0;
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='(')
            dp[i]=0;
        else
        {
            dp[i]=0;
            if(s[i-1]=='(')
            {
                dp[i]=2;
                if(i-2>=0)
                    dp[i]=2+dp[i-2];
                
            }
            else
            {
                int x=dp[i-1]+1;
                if(i-x>=0&&s[i-x]=='(')
                {
                    dp[i]=dp[i-1]+2;
                    if(i-x-1>=0)
                        dp[i]=dp[i]+dp[i-x-1];
                }
                
            }
        }
        res=max(res,dp[i]);
    }
    return res;
}
};
