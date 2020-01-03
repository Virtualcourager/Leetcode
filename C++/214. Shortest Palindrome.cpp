class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length()==0)
        {
            return "";
        }
        string n="@#";
        for(int i=0;i<s.length();i++)
        {
            n+=s[i];
            n+='#';
        }
        vector<int> P(n.size(),0);
        int right=0,id=0;
        int maxlen=1,maxpoint=0,type=0;
        for(int i=1;i<n.size();i++)
        {
            P[i]=right>i?min(P[2*id-i],right-i):1;
            while(n[i+P[i]]==n[i-P[i]])
                P[i]++;
            if(i+P[i]>right)
            {
                right=i+P[i];
                id=i;
            }
            if(i==P[i]&&P[i]>maxlen)
            {
                maxlen=P[i];
                maxpoint=i;
                type=0;
            }
        }
        
        int start=(maxpoint-maxlen)/2;
        int r=maxlen-1;
        string pali;
        string rest;
        pali=s.substr(start,r);
        //cout<<pali<<endl;
        rest=s.substr(start+r,s.size()-r);
        //cout<<rest;
        string ans;
        reverse(rest.begin(),rest.end());
        ans=rest;
        ans+=pali;
        reverse(rest.begin(),rest.end());
        ans+=rest;
        return ans;
    }
};
