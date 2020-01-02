class Solution {
public:
    int mySqrt(int x) {
        double a,b;
        a=0,b=1;
        while(abs(a-b)>1e-9)
        {
            a=b;
            b=((b)+x/b)/2;
        }
        return (int) b;
    }
};
