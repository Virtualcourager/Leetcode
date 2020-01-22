class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> Dict(wordDict.begin(),wordDict.end());
        vector<int> check;
        check.push_back(0);
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<check.size();j++)
            {
                if(Dict.find(s.substr(check[j],i-check[j]+1))!=Dict.end())
                {
                    check.push_back(i+1);
                    break;
                }
            }
        }
        if(check[check.size()-1]==s.size())
            return true;
        else
            return false;
    }
};
