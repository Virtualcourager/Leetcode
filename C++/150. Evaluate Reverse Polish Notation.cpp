class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int n=tokens.size();
        if(n==0)
            return 0;
        for(int i=0;i<n;i++)
        {
            if(tokens[i].size()==1&&(tokens[i][0]=='+'||tokens[i][0]=='-'||tokens[i][0]=='*'||tokens[i][0]=='/'))
            {
                int a,b;
                a=nums.top();
                nums.pop();
                b=nums.top();
                nums.pop();
                if(tokens[i][0]=='+')
                {
                    a+=b;
                }
                else if(tokens[i][0]=='-')
                {
                    a-=b;
                }
                else if(tokens[i][0]=='*')
                {
                    a*=b;
                }
                else if(tokens[i][0]=='/')
                {
                    a=b/a;
                }
                nums.push(a);
            }
            else
            {
                int a=std::stoi(tokens[i]);
                nums.push(a);
            }
        }
        return nums.top();
    }
};
