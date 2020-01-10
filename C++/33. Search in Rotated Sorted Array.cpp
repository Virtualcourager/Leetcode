class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        else
        return bisearch(nums,target,0,nums.size()-1);
    }
    int bisearch(vector<int>& n, int t,int l,int r)
    {
        int f=n[0];
        if(l>=r)
        {
            if(n[l]==t)
                return l;
            else if(n[r]==t)
            {
                return r;
            }
            else 
                return -1;
        }
        int mid=l+(r-l)/2;
        if(n[mid]==t)
        {
            return mid;
        }
        if(t>f)
        {
            if(n[mid]>t)
            {
                return bisearch(n,t,l,mid-1);
            }
            else if(n[mid]<t)
            {
                if(n[mid]<f)
                {
                    return bisearch(n,t,l,mid-1);
                }
                else
                {
                    return bisearch(n,t,mid+1,r);
                }
            }
        }
        else if(t<f)
        {
            if(n[mid]<t)
            {
                return bisearch(n,t,mid+1,r);
            }
            else if(n[mid]>t)
            {
                if(n[mid]<f)
                {
                    return bisearch(n,t,l,mid-1);
                }
                else
                {
                    return bisearch(n,t,mid+1,r);
                }
            }
        }
        else 
            return 0;
        return -1;
    }
};
