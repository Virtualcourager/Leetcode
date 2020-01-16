class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<n)
            swap(m,n);
        m--;
        n--;
        long long ans=1;
        m=m+n;
        int k=n;
        for(int i=0;i<k;i++)
        {
            ans*=m;
            m--;
        }
        for(int i=0;i<k;i++)
        {
            ans/=n;
            n--;
        }
        return (int)ans;
    }
};
