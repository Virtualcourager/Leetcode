class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> num;
        num.insert(n);
        while(n!=1)
        {
            int tmp=0;
            while(n!=0)
            {
                int k=n%10;
                n/=10;
                tmp+=k*k;
            }
            if(num.find(tmp)!=num.end())
                return false;
            n=tmp;
            num.insert(n);
        }
        return true;
    }
};
