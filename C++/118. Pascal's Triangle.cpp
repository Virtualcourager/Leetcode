class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0)
            return res;
        vector<int> ans;
        int i=1;
        res.push_back({1});
        while(i<numRows)
        {
            ans.push_back(1);
            for(int j=1;j<res[i-1].size();j++)
            {
                ans.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            ans.push_back(1);
            res.push_back(ans);
            ans.clear();
            i++;
        }
        return res;
    }
};
