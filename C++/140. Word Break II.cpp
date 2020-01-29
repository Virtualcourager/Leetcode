class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string>> mp;
        return dfs(s,wordDict,mp);
    }
    vector<string> dfs(string s, vector<string>& wordDict,unordered_map<string,vector<string>> &mp)
    {
        if(mp.count(s))
            return mp[s];
         if(s.empty())
            return {""};
        vector<string> res;
        for (string word:wordDict) 
        {
            if (s.substr(0, word.size())!=word) 
                continue;
            vector<string> rem=dfs(s.substr(word.size()),wordDict,mp);
            for (string str : rem)
            {
                res.push_back(word + (str.empty()?"":" ") + str);
            }
        }
        return mp[s] = res;
    }
};
