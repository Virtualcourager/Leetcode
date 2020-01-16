class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size();
        while(left<right)
        {
            int l=left,r=right-1;
            int tar=nums[left];
            while(l<=r)
            {
                while(l<=r&&nums[l]>=tar)
                    l++;
                while(l<=r&&nums[r]<tar)
                    r--;
                if(l<r)
                {
                    swap(nums[l],nums[r]);
                    l++,r--;
                }
            }
            swap(nums[left],nums[r]);
            if(r==k-1)
                return nums[r];
            else if (r<k-1)
                left=r+1;
            else
                right=r;
        }
        return 1;
    }
};
