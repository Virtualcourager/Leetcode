class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0)
            return 0;
        int i=0;
        int n=str.size();
        int ans=0;
        while(i<n&&str[i]==' ')
            i++;
        if(i==n)
            return 0;
        if(str[i]!='+'&&str[i]!='-'&&(str[i]<'0'||str[i]>'9'))
            return 0;
        bool flag=false;
        if(str[i]=='-')
        {
            i++;
            flag=true;
        }
        else if(str[i]=='+')
            i++;
        while(str[i]>='0'&&str[i]<='9'&&i<n)
        {
            int tmp=str[i]-'0';
            if(ans<=((INT_MAX/10)-1)&&ans>=((INT_MIN/10)))
            {
                ans*=10;
                ans+=tmp;
            }
            else
            {
                if(ans==(INT_MAX/10))
                {
                    if(!flag&&tmp>7)
                        return INT_MAX;
                    else if(flag&&tmp>8)
                        return INT_MIN;
                    else
                    {
                        if(flag)
                        {
                            ans=-ans;
                            flag=false;
                            ans*=10;
                            ans-=tmp;
                            i++;
                            continue;
                        }
                        ans*=10;
                        ans+=tmp;
                    }
                }
                else
                {
                    if(flag||ans<0)
                       return INT_MIN;
                    else
                        return INT_MAX;
                }
                
            }
            i++;
        }
        if(flag)
            return -ans;
        else
            return ans;
    }
};
