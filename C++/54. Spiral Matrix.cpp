class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> ans;
        if(n==0)
            return ans;
        int m=matrix[0].size();
        bool visited[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                visited[i][j]=false;
        int i=0;
        int j=0;
        bool flag=true;
        int dic=3; //1:right, 2:left, 3:up, 4:down. First move should go right. So, initialize it to 3.
        while(ans.size()<m*n)
        {
            if(flag)
            {
                j--;
                flag=false;
            }
            switch(dic)
            {
                    case 1:
                        dic=4; //go down
                        i++;
                        for(i;i<n&&visited[i][j]==false;i++)
                        {
                            ans.push_back(matrix[i][j]);
                            visited[i][j]=true;
                        }
                        i--;
                        break;
                    case 2:
                        dic=3; //go up
                        i--;
                        for(i;i>=0&&visited[i][j]==false;i--)
                        {
                            ans.push_back(matrix[i][j]);
                            visited[i][j]=true;
                        }
                        i++;
                        break;
                    case 3:
                        dic=1;
                        j++;
                        for(j;j<m&&visited[i][j]==false;j++)
                        {
                            ans.push_back(matrix[i][j]);
                            visited[i][j]=true;
                        }
                        j--;
                        break;
                    case 4:
                        dic=2;
                        j--;
                        for(j;j>=0&&visited[i][j]==false;j--)
                        {
                            ans.push_back(matrix[i][j]);
                            visited[i][j]=true;
                        }
                        j++;
                        break;
            }
        }
        return ans;
    }
    
};
