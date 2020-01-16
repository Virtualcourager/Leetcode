class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxn=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i<=maxn)
            {
                maxn=max(maxn,i+nums[i]);
                if(maxn>=n-1)
                    return true;
            }
            else 
                return false;
        }
        return false;
    }
};
