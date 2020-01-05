class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int i=0,j=size-1;
        if(size<=1)
            return 0;
        int ans=0;
        while(i!=j)
        {
            int cur=min(height[i],height[j])*(j-i);
            cout<<cur<<" "<<i<<j<<endl;
            ans=max(ans,cur);
            if(height[i]>height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
