class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>>graph(numCourses, vector<int>(0));
        vector<int> in(numCourses,0);
        int n=prerequisites.size();
        for(int i=0;i<n;i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            ans.push_back(tmp);
            for(int i=0;i<graph[tmp].size();i++)
            {
                in[graph[tmp][i]]--;
                if(in[graph[tmp][i]]==0)
                    q.push(graph[tmp][i]);
            }
        }
        if(ans.size()!=numCourses)
            ans.clear();
        return ans;
    }
};
