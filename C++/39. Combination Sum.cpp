class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size()==0)
            return ans;
        vector<int> cur;
        conbine(candidates,target,0,cur,ans);
        return ans;
    }
    void conbine(vector<int>& candidates,int target,int start,vector<int>& cur, vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(cur);
            return ;
        }
        else if(target<0)
            return;
        else
        {
            for(int i=start;i<candidates.size();i++)
            {
                cur.push_back(candidates[i]);
                target-=candidates[i];
                conbine(candidates,target,i,cur,ans);
                target+=candidates[i];
                cur.pop_back();
            }
        }
    }
};
