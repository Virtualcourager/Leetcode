class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        bool dp[m+1][n+1];
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=false;
            }
        dp[0][0]=1;
        if(p[0]=='*')
        {
            for(int i=1;i<=m;i++)
            dp[i][1]=true;
        }
        for(int j=1;j<=n;j++)
        {
            if(p[j-1]=='*')
            {
                dp[0][j]=true;
            }
            else break;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-1]||dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
