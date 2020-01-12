class Solution {
public:
    bool isMatch(string s, string p) {
        int m,n;
        m=s.length();
        n=p.length();
        bool dp[m+1][n+1];
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=0;
            }
        dp[0][0]=true;
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=false;
        }
        for(int j=1;j<=n&&p[j]=='*';j+=2)
        {
            dp[0][j+1]=true;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                {
                    if(p[j-2]!=s[i-1]&&p[j-2]!='.')
                    {
                        dp[i][j]=dp[i][j-2];
                    }
                    else if(p[j-2]==s[i-1]||p[j-2]=='.')
                    {
                        dp[i][j]=(dp[i][j-2]||dp[i-1][j]);
                    }
                }
                else if(s[i-1]==p[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                } 
            }
        }
        return dp[m][n];
    }
};
