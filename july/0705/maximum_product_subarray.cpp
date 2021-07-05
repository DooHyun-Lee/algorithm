// using kaden's algorithm
// but in both ways not to miss case like [3,-1,4]

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int ret = nums[0];
        for(int i=0;i<nums.size();i++){
            ret = max(ret,prod*nums[i]);
            prod *= nums[i];
            if(prod==0)
                prod = 1;
        }
        prod =1;
        for(int j=nums.size()-1;j>=0;j--){
            ret = max(ret,prod*nums[j]);
            prod *= nums[j];
            if(prod==0)
                prod = 1;
        }
        return ret;
    }
};
