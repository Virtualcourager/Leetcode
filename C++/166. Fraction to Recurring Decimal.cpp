class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        string ans;
        long n= numerator;
        long m=denominator;
        if(m==0)
            return ans;
        if((n<0&&m>0)||(n>0&&m<0))
            res+='-';
        n=abs(n);
        m=abs(m);
        if(n%m==0)
        {
            return res+to_string(n/m);
        }
        else
        {
            res+=to_string(n/m);
            res+='.';
            n%=m;
        }
        unordered_map<long,long> mp;
        int pos=0;
        while(1)
        {
            if(n==0)
            {
                res+=ans;
                return res;
            }
            else
            {
                if(mp.find(n)!=mp.end())
                {
                    for(int i=0;i<mp[n];i++)
                        res+=ans[i];
                    res+='(';
                    for(int i=mp[n];i<ans.size();i++)
                        res+=ans[i];
                    res+=')';
                    return res;
                }
                mp[n]=pos;
                n*=10;
                ans+=to_string(n/m);
                n%=m;
                pos++;
            }
        }
        
    }
};
