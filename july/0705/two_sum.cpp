// to see difference btw map & unordered map visit https://thispointer.com/map-vs-unordered_map-when-to-choose-one-over-another
// try to make run time O(n) rather than O(n^2)


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<len;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
