class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size();
        for(int start=0;start<n;start++)
        {
            int tank=gas[start]-cost[start];
            int cur=start;
            if(tank<0)
                continue;
            cur=(cur+1)%n;
            while(cur!=start)
            {
                tank+=gas[cur];
                tank-=cost[cur];
                if(tank<0)
                    break;
                cur=(cur+1)%n;
            }
            if(cur==start)
                return start;
        }
        return -1;
    }
};
