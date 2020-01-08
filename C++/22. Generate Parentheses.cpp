class Solution {
public:
    vector<string> generateParenthesis(int n) {
        typedef struct alpabet
        {
            string s;
            int total,allow;
        }alpha;
        vector<alpha> a;
        alpha tmp;
        tmp.s='(';
        tmp.total=1;
        tmp.allow=1;
        a.push_back(tmp);
        vector<alpha> t;
        for(int i=1;i<2*n;i++)
        {
            for(int j=0;j<a.size();j++)
            {
                if(a[j].allow==0)
                {
                    a[j].s+='(';
                    a[j].allow++;
                    a[j].total++;
                    t.push_back(a[j]);
                }
                else
                {
                    if(a[j].total==n)
                    {
                        a[j].s+=')';
                        a[j].allow--;
                        t.push_back(a[j]);
                    }
                    else
                    {
                        tmp=a[j];
                        a[j].s+='(';
                        a[j].allow++;
                        a[j].total++;
                        t.push_back(a[j]);
                        tmp.s+=')';
                        tmp.allow--;
                        t.push_back(tmp);
                    }
                }
            }
            a=t;
            t.clear();
        }
        vector<string> ans;
        for(int i=0;i<a.size();i++)
        {
            ans.push_back(a[i].s);
        }
        return ans;
    }
};
