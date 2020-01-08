class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0)
            return ;
        int flag=-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                flag=i;
                break;
            }
        }
        if(flag<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            int j=-1;
            for(int i=flag+1;i<nums.size();i++)
            {
                if(nums[i]<=nums[flag])
                {
                    j=i-1;
                    break;
                }
            }
            if(j<0)
            {
                int tmp=nums[flag];
                nums[flag]=nums[nums.size()-1];
                nums[nums.size()-1]=tmp;
            }
            else
            {
                int tmp=nums[flag];
                nums[flag]=nums[j];
                nums[j]=tmp;
            }
            reverse(nums.begin()+flag+1,nums.end());
        }
    }
};
