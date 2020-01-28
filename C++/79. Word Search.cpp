class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if(m==0)
        {
            return false;
        }
        int n=board[0].size();
        int k=word.size();
        if(k==0)
            return true;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                    if(dfs(board,word,i,j,0)==true)
                        return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int cur)
    {
        if(cur==word.size())
            return true;
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1)
            return false;
        if(board[i][j]==word[cur])
        {
            char tmp=board[i][j];
            board[i][j]='$';
            bool res=dfs(board,word,i+1,j,cur+1)||dfs(board,word,i,j+1,cur+1)||dfs(board,word,i-1,j,cur+1)||dfs(board,word,i,j-1,cur+1);
            board[i][j]=tmp;
            return res;
        }
        else
            return false;
    }
};
