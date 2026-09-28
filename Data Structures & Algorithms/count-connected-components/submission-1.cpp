class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // building the graph again due to not always connected, we need to build node connected in two direction why -> because it is undirected graph: a-> b then b->a? but we visited a so just get grid of b will be easy
        vector<vector<int>> builtGraph(n);
        for (auto edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            builtGraph[a].push_back(b);
            builtGraph[b].push_back(a);
        }

        // n = 5, edges = [[0,1],[1,2],[3,4]]
        // builtGraph = {{1}, {0, 2}, {1}, {4}, {3}}

        vector<bool>visited(n, false);
        int components = 0;
        for (int i = 0; i < builtGraph.size(); i++)
        {
            if (!visited[i])
            {
                dfs(builtGraph, i, visited);
                components++;
            }
        }
        return components;
    }
private:
    void dfs(vector<vector<int>>& myGraph, int index, vector<bool>& visited)
    {
        if (visited[index]) return;
        visited[index] = true;

        for (int i : myGraph[index])
        {
            if (!visited[i])
            {
                dfs(myGraph, i, visited);
            }
        }
    }
};
