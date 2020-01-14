class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int size=nums.size();
        vector<int> flag(size, 0);
        DFS(nums,flag,cur,ans);
        return ans;
    }
    void DFS(vector<int>& nums,vector<int>& flag,vector<int>& cur,vector<vector<int>>& ans)
    {
        if(cur.size()==nums.size())
        {
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(flag[i]==1)
                continue;
            flag[i]=1;
            cur.push_back(nums[i]);
            DFS(nums,flag,cur,ans);
            cur.pop_back();
            flag[i]=0;
        }
    }
};
