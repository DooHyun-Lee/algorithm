// for kaden's algorithm, look for https://sustainable-dev.tistory.com/23

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int localmax,globalmax;
        localmax = globalmax = nums[0];
        for(int i=1;i<nums.size();i++){
            localmax = max(nums[i],localmax+nums[i]);
            if(globalmax < localmax)
                globalmax = localmax;
        }
        return globalmax;
    }
};


// maybe use this style?
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prod = 0;
        int ret = nums[0];
        for(int i=0;i<nums.size();i++){
            ret = max(ret,prod+nums[i]);
            prod += nums[i];
            if(prod<0)
                prod = 0;
        }
        return ret;
    }
};
