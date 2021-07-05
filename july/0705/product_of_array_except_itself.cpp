// think of two arrays
// pre : 1           [1]     [1]*[2]     [1]*[2]*[3]
// suf : [2]*[3]*[4] [3]*[4] [4]          1
// pre*suf will result in mult except for itself

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        ret.assign(nums.size(),0);
        int left = 1;
        ret[0] = 1;
        for(int i=1;i<nums.size();i++){
            left *= nums[i-1];
            ret[i] = left;
        }
        left = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            ret[i] *= left;
            left *= nums[i]; 
        }
        return ret;
    }
};
