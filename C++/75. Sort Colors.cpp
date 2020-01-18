class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l,r,cur;
        l=cur=0;
        r=nums.size()-1;
        while(cur<=r)
        {
            if(nums[cur]==0)
            {
                swap(nums[l],nums[cur]);
                l++;
                cur++;
                continue;
            }
            else if(nums[cur]==2)
            {
                swap(nums[r],nums[cur]);
                r--;
                continue;
            }
            cur++;
        }
        return;
    }
};
