class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int m=t.size();
        int n=s.size();
        for(int i=0;i<m;i++)
        {
            mp[t[i]]++;
        }
        int cnt=0,minn=INT_MAX;
        string ans;
        int l=0,r=0;
        while(l<n)
        {
            mp[s[l]]--;
            if(mp[s[l]]>=0)
                cnt++;
            while(cnt==m)
            {
                mp[s[r]]++;
                if(mp[s[r]]>0)
                {
                    cnt--;
                    if(l-r<minn)
                    {
                        minn=l-r+1;
                        ans=s.substr(r,minn);
                    }
                }
                    r++;
            }
                
            l++;
        }
        return ans;
    }
};
