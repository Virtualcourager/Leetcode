class Solution {
public:
    int reverse(int x) {
        if(x==0)
            return x;
        int tmp=x;
        while(tmp%10==0)
            tmp/=10;
        int ans=0;
        while(tmp!=0)
        {
            if(ans>INT_MAX/10||ans<INT_MIN/10)
                return 0;
            ans*=10;
            ans+=tmp%10;
            tmp/=10;
        }
        return ans;
    }
};
