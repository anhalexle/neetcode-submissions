class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto pre : prerequisites)
        {
            graph[pre[0]].push_back(pre[1]);
        }
        vector<int> state(graph.size(), 0); //0 : not visited, 1: process, 2: finished
        for (int i = 0; i < graph.size(); i++)
        {
            if (!dfs(i, graph, state)) return false;
        }
        return true;
    }
private:
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& state)
    {
        if (state[i] == 1) return false;
        if (state[i] == 2) return true;
        state[i] = 1; // process
        // for (int index = 0; index < graph[i].size(); index++)
        for (auto edge : graph[i])
        {
            if (!dfs(edge, graph, state)) return false;
        }
        state[i] = 2; // finish
        return true;
    }
};
