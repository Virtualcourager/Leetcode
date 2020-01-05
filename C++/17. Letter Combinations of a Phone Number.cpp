class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> a;
        if(!digits.size())
            return a;
        a.push_back("abc");
        a.push_back("def");
        a.push_back("ghi");
        a.push_back("jkl");
        a.push_back("mno");
        a.push_back("pqrs");
        a.push_back("tuv");
        a.push_back("wxyz");
        vector<string> ans{""};
        for(int i=0;i<digits.size();i++)
        {
            vector<string> t;
            string  str=a[digits[i]-'2'];
            for(int j=0;j<str.size();j++)
            {
                for(string s:ans) t.push_back(s+str[j]);
            }
            ans=t;
        }
        return ans;
    }
};
