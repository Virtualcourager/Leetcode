class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                continue;
            if(i>0&&nums[i]==nums[i-1])
                continue;
            vector<int> cur;
            cur.push_back(nums[i]);
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[j]+nums[k]==-nums[i])
                {
                    cur.push_back(nums[j]);
                    cur.push_back(nums[k]);
                    ans.push_back(cur);
                    k--;
                    j++;
                    while(nums[k]==nums[k+1]&&k>0)
                        k--;
                    while(nums[j]==nums[j-1]&&j<=k)
                        j++;
                    cur.clear();
                    cur.push_back(nums[i]);
                }
                else if(nums[j]+nums[k]>-nums[i])
                {
                    k--;
                    while(nums[k]==nums[k+1]&&j<k)
                        k--;
                }
                else 
                {
                    j++;
                    while(nums[j]==nums[j-1]&&j<k)
                        j++;
                }
            }
        }
         return ans;
    }
};
