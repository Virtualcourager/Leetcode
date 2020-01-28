class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int res[n+1];
        res[0]=1;
        res[1]=1;
        if(s[0]=='0')
            return 0;
        for(int i=1;i<n;i++)
        {
            int tmp=0;
            if(s[i]=='0'&&(s[i-1]!='1'&&s[i-1]!='2'))
                return 0;
            else if(s[i]=='0')
                res[i+1]=res[i-1];
                
            else
            {
                tmp=(s[i-1]-'0')*10;
                tmp+=(s[i]-'0');
                if(tmp<=26&&tmp>10)
                {
                    res[i+1]=res[i]+res[i-1];
                }
                else
                    res[i+1]=res[i];
            }
            
        }
        return res[n];
    }
};
