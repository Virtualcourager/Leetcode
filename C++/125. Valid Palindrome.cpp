class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return true;
        int l=0,r=n-1;
        while(l<r)
        {
            while(l<=n-1)
                if(!isAlphanumeric(s[l]))
                    l++;
            else break;
            while(r>=0)
                if(!isAlphanumeric(s[r]))
                    r--;
            else break;
            if(r<l)
                return true;
            if(s[l]>='A'&&s[l]<='Z')
                s[l]+=('a'-'A');
            if(s[r]>='A'&&s[r]<='Z')
                s[r]+=('a'-'A');
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
bool isAlphanumeric(const char c) 
{
    if ('A' <= c && c <= 'Z')
        return true;
    else if ('a' <= c && c <= 'z')
        return true;
    else if ('0' <= c && c <= '9')
        return true;
    return false;
    }
};
