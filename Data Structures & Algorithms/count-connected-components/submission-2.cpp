class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // built Graph
        // edges = [[0,1],[1,2],[3,4]]
        // [vertex 0:[1] , vertex 1: [0,1], vertex 2: [1], vertex 3:[4], vertex 4: [3]]
        vector<vector<int>> builtGraph(n);
        for (auto edge: edges)
        {
            builtGraph[edge[0]].push_back(edge[1]);
            builtGraph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(builtGraph.size(), false);
        int count = 0;
        for (int i = 0; i < builtGraph.size(); i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, builtGraph, visited);
            }
        }
        return count;
    }
private:
    void dfs(int i, vector<vector<int>>& graph, vector<bool>& visited)
    {
        if (visited[i]) return;
        visited[i] = true;
        for (auto adj : graph[i])
        {
            dfs(adj, graph, visited);
        }
    }
};
