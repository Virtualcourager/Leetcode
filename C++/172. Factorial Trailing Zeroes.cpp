class Solution {
public:
    int trailingZeroes(int n) {
        int i=5;
        int ans=0;
        while(i<=n)
        {
            ans+=n/i;
            if(i<=INT_MAX/5)
                i*=5;
            else
                break;
        }
        return ans;
    }
};
