class Solution {
public:
    int trap(vector<int>& height) {
        int r=height.size()-1;
        int l=0;
        int cur=0;
        int ans=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(cur>height[l])
                  ans+=cur-height[l];
                else
                    cur=height[l];
                l++;
            }
            else
            {
                if(cur>height[r])
                  ans+=cur-height[r];
                else
                    cur=height[r];
                r--;
            }
        }
        return ans;
    }
};
