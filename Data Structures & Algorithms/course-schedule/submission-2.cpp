class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // builtGraph
        vector<vector<int>> builtGraph(numCourses);
        for (auto pre : prerequisites)
        {
            int a = pre[0];
            int b = pre[1];
            builtGraph[a].push_back(b);
            // no builtGraph[b].push_back(a) // because one way
        }
        vector<int> state (numCourses, 0); // 0: unvisited, 1: cycle, 2: finished
        // [[0, 1]] -> [[1], []]
        for (int i = 0; i < numCourses; i++)
        {
            if(!dfs(i, builtGraph, state)) return false;
        }
        return true;
    }
private:
    bool dfs(int index, vector<vector<int>>& graph, vector<int>& state)
    {
        if (state[index] == 1) return false;
        if (state[index] == 2) return true;

        state[index] = 1;
        for (int i: graph[index])
        {
            if (!dfs(i, graph, state)) return false;
        }
        state[index] = 2;
        return true;
    }
};
