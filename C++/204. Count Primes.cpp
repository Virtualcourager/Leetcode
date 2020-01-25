class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        for(int i=2;i<n;i++)
            prime[i]=false;
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(prime[i]==true)
                continue;
            else
            {
                ans++;
                if(i>sqrt(n))
                    continue;
                for(int k=2;k*i<=n;k++)
                {
                    prime[k*i]=true;
                }
            }
        }
        return ans;
    }
};
