class Solution {
public:
    double myPow(double x, int n) {
        double result=1;
        if(n<0&&x!=0)
        {
            x=1/x;
            if(n==INT_MIN)
            {
                n>>=1;
                x*=x;
            }
            n=abs(n);
        }
            
        if(n==0)
            return 1;
        while(n>0)
        {
            if(n&1)
            {
                result=x*result;
            }
            n>>=1;
            x*=x;
        }
        return result;
    }
};
