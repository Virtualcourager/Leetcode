class Solution {
public:
    typedef struct n{
        int cnt;
        int num;
        bool operator < (const n& x) const
        { 
		return cnt>x.cnt;
        }
    }n;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        
        vector<n> s;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            n tmp;
            tmp.cnt=it.second;
            tmp.num=it.first;
            s.push_back(tmp);
        }

        sort(s.begin(),s.end());
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(s[i].num);
        }
        return ans;
    }
};
