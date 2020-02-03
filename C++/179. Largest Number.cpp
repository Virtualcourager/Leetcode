class Solution {
public:

    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0; i<nums.size();i++) 
        {
            res+=to_string(nums[i]);
        }
        if(res[0]=='0')
            return "0";
        else 
            return res;
    }
    static bool cmp(const int&a, const int&b)
    {
        if(to_string(a)+to_string(b)>to_string(b)+to_string(a))
            return true;
        else
            return false;
    }

};
