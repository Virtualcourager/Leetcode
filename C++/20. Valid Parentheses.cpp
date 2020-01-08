class Solution {
public:
    bool isValid(string s) {
        if(s=="")
            return 1;
        stack<int> judge;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                judge.push(1);
            }
            else if(s[i]=='[')
            {
                judge.push(2);
            }
            else if(s[i]=='{')
            {
                judge.push(3);
            }
            else if(s[i]==')')
            {
                if(judge.empty())
                    return 0;
                if(judge.top()!=1)
                    return 0;
                else
                    judge.pop();
            }
            else if(s[i]==']')
            {
                if(judge.empty())
                    return 0;
                if(judge.top()!=2)
                    return 0;
                else
                    judge.pop();
            }
            else if(s[i]=='}')
            {
                if(judge.empty())
                    return 0;
                if(judge.top()!=3)
                    return 0;
                else
                    judge.pop();
            }
        }
        if(judge.empty())
            return 1;
        else
            return 0;
    }
};
