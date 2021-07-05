// my original idea
 
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end())
                return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};

*/

// if you want to use less memory 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto iter = unique(nums.begin(),nums.end());
        return iter != nums.end();
    }
};

// actually less memory and less time!!
