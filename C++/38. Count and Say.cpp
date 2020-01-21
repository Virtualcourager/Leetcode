class Solution {
public:
    string countAndSay(int n) {
        string s;
        s="1";
        for(int i=0;i<n-1;i++)
        {
            string ans;
            for(int j=0;j<s.size();)
            {
                int cnt=0;
                char cur=s[j];
                while(j<s.size()&&s[j]==cur)
                {
                    j++;
                    cnt++;
                }
                ans.append(to_string(cnt));
                ans+=cur;
            }
            s=ans;
        }
        return s;
    }
};
