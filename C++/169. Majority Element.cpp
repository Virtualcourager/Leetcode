class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int res=nums[0];
        for(int i=1;i<n;i++)
        {
            if(cnt==0)
            {
                res=nums[i];
                cnt=1;
            }
            else if(nums[i]==res)
                cnt++;
            else 
                cnt--;
        }
        return res;
    }
};
