class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        if(grid[0].size()==0)
            return 0;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='0')
                    continue;
                dfs(grid,i,j);
                ans++;
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(grid[i][j]=='0')
            return;
        grid[i][j]='0';
        if(i<grid.size()-1)
            dfs(grid,i+1,j);
        if(i>0)
            dfs(grid,i-1,j);
        if(j<grid[0].size()-1)
            dfs(grid,i,j+1);
        if(j>0)
            dfs(grid,i,j-1);
    }
};
