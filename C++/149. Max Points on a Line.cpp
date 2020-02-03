class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0)
            return 0;
        int res=1;
        for(int i=0;i<n;i++)
        {
            map<pair<int,int>,int> mp;
            int dup=1;
            for(int j=i+1;j<n;j++)
            {
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1])
                {
                    dup++;
                    continue;
                }
                int dx=points[i][0]-points[j][0];
                int dy=points[i][1]-points[j][1];
                int d=gcd(dx,dy);
                mp[{dx/d,dy/d}]++;
            }
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                res=max(res,dup+it->second);
            }
            res=max(res,dup);
        }
        return res;
    }
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }
};
