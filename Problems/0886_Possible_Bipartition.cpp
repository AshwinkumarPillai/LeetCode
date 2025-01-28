class Solution
{
public:
    bool possibleBipartition(int N, vector<vector<int>> &d)
    {
        map<int, set<int>> m;
        vector<int> g(N + 1, -1);
        for (auto x : d)
        {
            m[x[0]].insert(x[1]);
            m[x[1]].insert(x[0]);
        }

        //if g[p] = -1 then it will perform dfs and if there is a error it will return false else it will go             to next unvisited node the part before.
        for (auto p : m)
        {
            if (g[p.first] == -1 && !dfs(m, g, p.first, 0))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(map<int, set<int>> &m, vector<int> &g, int i, int c)
    {
        if (g[i] == -1)
        {
            g[i] = c;
        }
        else
        {
            return g[i] == c;
        }

        for (auto x : m[i])
        {
            if (!dfs(m, g, x, 1 - c))
            {
                return false;
            }
        }
        return true;
    }
};