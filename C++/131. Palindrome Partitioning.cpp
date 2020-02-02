class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>res;
        if(n==0)
            return res;
        vector<vector<bool>> dp(n,vector<bool>(n));
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j <= i; ++j) 
            {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                }
            }
        }
        vector<string> ans;
        dfs(s,0,ans,res,dp);
        return res;
    }
    void dfs(string s,int start,vector<string> &ans,vector<vector<string>>& res,vector<vector<bool>> dp)
    {
        if(start==s.size())
        {
            res.push_back(ans);
            return ;
        }
        for(int i=start;i<s.size();i++)
        {
            if(dp[start][i]==true)
            {
                ans.push_back(s.substr(start,i-start+1));
                dfs(s,i+1,ans,res,dp);
                ans.pop_back();
            }
        }
        return;
    }
};
