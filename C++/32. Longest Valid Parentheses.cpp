class Solution {
public:
    int longestValidParentheses(string s) {
        int size=s.length();
        if(!size)
            return 0;
        int dp[size];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<size;i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    if(i>=2)
                        dp[i]=dp[i-2]+2;
                    else
                        dp[i]=2;
                    ans=max(ans,dp[i]);
                }
                else if(s[i-1]==')')
                {
                    if(i-dp[i-1]-1>=0)
                    if(s[i-dp[i-1]-1]=='(')
                        dp[i]=dp[max(i-1,0)]+dp[max(i-dp[i-1]-2,0)]+2;
                    ans=max(ans,dp[i]);
                }
                    
            }
        }
        return ans;
    }
};
