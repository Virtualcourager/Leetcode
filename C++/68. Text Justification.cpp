class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int sum=words.size();
        int i=0;
        while(i<sum)
        {
            int start=i;
            int space=maxWidth;
            int cnt=0;
            while(space>=words[i].length()&&space>0)
            {
                space-=words[i].size();
                cnt++;
                i++;
                space--;
                if(i==sum)
                    break;
            }
            space++;
            string ans;
            if(i==sum)
            {
                for(int j=start;j<sum;j++)
                {
                    ans.append(words[j]);
                    if(j!=i-1)
                        ans+=" ";
                }
                for(int j=0;j<space;j++)
                {
                    ans+=" ";
                }
                res.push_back(ans);
            }
            else
            {
                int avg;
                int rest;
                if(i-start>1)
                {
                    avg=space/(i-start-1);
                    rest=space%(i-start-1);
                }
                else
                {
                    avg=-1;
                    rest=space;
                }
                for(int j=start;j<i;j++)
                {
                    ans.append(words[j]);
                    if(j!=i-1)
                        ans+=" ";
                    for(int k=0;k<avg&&j!=i-1;k++)
                    {
                        ans+=" ";
                    }
                    if(rest>0)
                    {
                        ans+=" ";
                        rest--;
  
                    }
                    if(avg==-1)
                    {
                        for(int k=0;k<space-1;k++)
                            ans+=" ";
                    }
                }
                res.push_back(ans);
            }
        }
        return res;
    }
};
