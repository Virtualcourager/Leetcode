class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size();
        int dp[n][m]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=INT_MAX;
            }
        }
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i!=n-1)
                {
                        dp[i+1][j]=min(dp[i+1][j],dp[i][j]+grid[i+1][j]);
                }
                if(j!=m-1)
                {
                        dp[i][j+1]=min(dp[i][j+1],dp[i][j]+grid[i][j+1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size(); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if (i == 0 && j == 0) 
                   continue;
                if (i == 0) 
                    grid[0][j] += grid[0][j - 1];
                else if (j == 0) 
                    grid[i][0] += grid[i - 1][0];
                else 
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[n-1][m-1];
    }
};
