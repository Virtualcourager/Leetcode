class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        else
            return bisearch(nums,0,nums.size()-1);
    }
    int bisearch(vector<int>& nums,int l,int r)
    {
        if(l>=r) 
            return nums[l];
        int mid=l+(r-l)/2;
        int lmaxn=bisearch(nums,l,mid-1);
        int rmaxn=bisearch(nums,mid+1,r);
        int mmaxn=nums[mid];
        int tmp=nums[mid];
        for(int i=mid-1;i>=l;i--)
        {
            tmp+=nums[i];
            mmaxn=max(mmaxn,tmp);
        }
         tmp=mmaxn;
        for(int i=mid+1;i<=r;i++)
        {
            tmp+=nums[i];
            mmaxn=max(mmaxn,tmp);
        }
        return max(lmaxn,max(rmaxn,mmaxn));
    }
};



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxn=nums[0];
        int tmp=0;
        for(int i=0;i<nums.size();i++)
        {
            tmp+=nums[i];
            maxn=max(maxn,tmp);
            if(tmp<0)
            {
                tmp=0;
            }
        }
        return maxn;
    }
};


