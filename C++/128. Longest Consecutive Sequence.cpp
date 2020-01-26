class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i])==1)
                continue;
            int left=0,right=0;
            if(mp.count(nums[i]-1)==1)
               left=mp[nums[i]-1];
            if(mp.count(nums[i]+1)==1)
               right=mp[nums[i]+1];
            int cur=left+right+1;
            ans=max(ans,cur);
            mp[nums[i]]=1;
            mp[nums[i]-left]=cur;
            mp[nums[i]+right]=cur;
        }
        return ans;
    }
};
