class Solution {
public:
    string longestPalindrome(string s) {
        int size=s.length();
        if(!size)
            return "";
        bool k[size+1][size+1];
        memset(k,0,sizeof(k));
        int ans1=0,maxn=1;
        for(int i=0;i<size;i++)
        {
            k[i][i]=1;
            if(i)
            {
                if(s[i-1]==s[i])
                {
                    k[i-1][i]=1;
                    maxn=2;
                    ans1=i-1;
                }
                
            }
        }
        for(int j=1;j<size;j++)
        for(int i=0;i<j;i++)
        {
            if(i==size-1)
                continue;
            else
                if(k[i+1][j-1]==1&&s[i]==s[j])
                {
                    k[i][j]=1;
                    if(j-i+1>maxn)
                    {
                         maxn=j-i+1;
                         ans1=i;
                    }
                }
        }
        // cout<<ans1<<maxn;
        return s.substr(ans1,maxn);
    }
};



class Solution {
public:
    string longestPalindrome(string s) {
        string n="@#";
        for(int i=0;i<s.length();i++)
        {
            n+=s[i];
            n+='#';
        }
        vector<int> P(n.size(),0);
        int right=0,id=0;
        int maxlen=0,maxpoint=0;
        for(int i=1;i<n.size();i++)
        {
            P[i]=right>i?min(P[2*id-i],right-i):1;
            while(n[i+P[i]]==n[i-P[i]])
                P[i]++;
            if(i+P[i]>right)
            {
                right=i+P[i];
                id=i;
            }
            if(P[i]>maxlen)
            {
                maxlen=P[i];
                maxpoint=i;
            }
        }
        return s.substr((maxpoint-maxlen)/2,maxlen-1);
        
    }
};
