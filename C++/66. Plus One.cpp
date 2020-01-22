class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        if(n==0)
        {
            ans.push_back(1);
            return ans;
        }
        int flag=1;
        for(int i=n-1;i>=0;i--)
        {
            if(flag==0)
            {
                ans.insert(ans.begin(),digits[i]);
                continue;
            }
            else if(digits[i]==9)
            {
                ans.insert(ans.begin(),0);
                if(i==0)
                    ans.insert(ans.begin(),1);
            }
            else
            {
                ans.insert(ans.begin(),digits[i]+1);
                flag=0;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(n==0)
        {
            return digits;
        }
        for(int i=n-1;i>=0;i--)
        {

            if(digits[i]==9)
            {
                digits[i]=0;
                if(i==0)
                    digits.insert(digits.begin(),1);
            }
            else
            {
                digits[i]+=1;
                return digits;
            }
        }
        return digits;
    }
};
