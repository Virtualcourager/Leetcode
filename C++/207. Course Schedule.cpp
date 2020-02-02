class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> visit(numCourses);
        for (auto a : prerequisites) 
		{
            graph[a[1]].push_back(a[0]);
        }
        for (int i = 0; i < numCourses; ++i) 
		{
            if (!dfs(graph, visit, i)) return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& visit, int i) {
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        visit[i] = -1;
        for (auto a : graph[i]) 
		{
            if (!dfs(graph, visit, a)) return false;
        }
        visit[i] = 1;
        return true;
    }
};
