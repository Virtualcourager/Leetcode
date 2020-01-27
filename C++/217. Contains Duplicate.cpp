class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> se;
        for(int i=0;i<nums.size();i++)
        {
            if(se.count(nums[i])!=0)
                return true;
            else
                se.insert(nums[i]);
        }
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i])!=0)
                return true;
            else
                mp[nums[i]]=1;
        }
        return false;
    }
};
