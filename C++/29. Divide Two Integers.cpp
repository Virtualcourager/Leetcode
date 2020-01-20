class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag=false;
        long n=dividend,m=divisor;
        if(n<0)
        {
            flag=!flag;
            if(n==INT_MIN&&m==-1)
                return INT_MAX;
            n=-n;
        }
        if(m<0)
        {
            flag=!flag;
            m=-m;
        }        
        long ans=0;
        long tmp=1;
        while(n>=m)
        {
            m<<=1;
            tmp<<=1;
        }
        m>>=1;
        tmp>>=1;
        ans+=tmp;
        n-=m;
        while(tmp>=1)
        {
            m>>=1;
            tmp>>=1;
            if(n>=m)
            {
                ans+=tmp;
                n-=m;
            }
        }
        if(!flag)
            return ans;
        else 
            return -ans;
    }
};
