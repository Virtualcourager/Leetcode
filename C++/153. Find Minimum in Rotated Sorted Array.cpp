class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        else
            return bisearch(nums,0,nums.size()-1);
    }
    int bisearch(vector<int>& nums,int l,int r)
    {
        int f=nums[0];
        while(l<r-1)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>f)
                l=mid;
            else
                r=mid;
        }
        return min(nums[l],min(f,nums[r]));
    }
};
