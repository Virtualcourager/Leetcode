class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<int> ans;
        if(r<0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>=target)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        if(nums[l]==target)
        {
            ans.push_back(l);
        }
        else
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+(r-l+1)/2;
            if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid;
            }
        }
        ans.push_back(l);
        return ans;
    }
};
