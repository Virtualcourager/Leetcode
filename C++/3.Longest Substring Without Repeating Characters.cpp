class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.size();
        int check[200];
        memset(check,0,sizeof(check));
        int i=0,j=0;
        int cur=0,maxn=0;
        while(j<size)
        {
            check[s[j]]++;
            if(check[s[j]]==2)
            {
                maxn=max(cur,maxn);
                while(check[s[i]]!=2&&i<size)
                {
                    cur--;
                    check[s[i]]--;
                    i++;
                }
               check[s[i]]=1;
                i++;
                cur--;
            }
            cur++;
            j++;
        }
        maxn=max(maxn,cur);
        return maxn;
    }
};
