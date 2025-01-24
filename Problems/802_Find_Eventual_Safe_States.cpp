class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &visiting, int node)
    {
        if (visiting[node])
            return false;
        if (visited[node])
            return true;

        visited[node] = true;
        visiting[node] = true;
        for (int neighbour : graph[node])
        {
            if (!dfs(graph, visited, visiting, neighbour))
            {
                return false;
            }
        }
        visiting[node] = false;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> visited(n), visiting(n);
        for (int i = 0; i < n; i++)
        {
            dfs(graph, visited, visiting, i);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!visiting[i])
                ans.emplace_back(i);
        }

        return ans;
    }
};