class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n<=0)
            return "";
        return bistr(strs,0,n-1);
    }
    string bistr(vector<string>& strs,int l,int r)
    {
        if(l==r)
            return strs[l];
        else if(r-l==1)
        {
            string ans;
            for(int i=0;i<min(strs[l].size(),strs[r].size());i++)
            {
                if(strs[l][i]==strs[r][i])
                    ans+=strs[l][i];
                else
                    break;
            }
            return ans;
        }
        string s1=bistr(strs,l,l+(r-l)/2);
        string s2=bistr(strs,(l+(r-l)/2)+1,r);
        string ans;
        for(int i=0;i<min(s1.size(),s2.size());i++)
        {
            if(s1[i]==s2[i])
                ans+=s1[i];
            else
                break;
        }
        return ans;
    }
        
};
