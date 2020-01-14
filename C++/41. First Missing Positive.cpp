class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]<=size&&nums[i]>0&&nums[nums[i]-1]!=nums[i])
                swap(nums[nums[i]-1],nums[i]);
            // else i++;
        }
        int i;
        for(i=0;i<size;i++)
        {
            if(nums[i]!=i+1)
                break;
        }
        return i+1;
    }
};
