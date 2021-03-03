class Solution {
public:
    
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        int dp[n];
        int val = 0;
        for(int i=0;i<n;i++){
            val = max(val,height[i]);
            dp[i] = val;
        }
        val = 0;
        for(int i=n-1;i>=0;i--){
            val = max(val,height[i]);
            dp[i] = min(dp[i],val);
        }
        int ret =0;
        for(int i=0;i<n;i++){
            ret += (dp[i]-height[i]);
        }
        return ret;
    }
};

// calc dp in left to right direction
// calc dp in right to left direction
