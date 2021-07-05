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
