class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &p)
    {
        map<int, set<int>> m;
        for (auto x : p)
        {
            m[x[0]].insert(x[1]);
        }

        vector<int> black(n);
        vector<int> grey(n);
        for (auto p : m)
        {
            if (black[p.first] == 0 && !dfs(m, black, grey, p.first))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(map<int, set<int>> &m, vector<int> &black, vector<int> &grey, int i)
    {
        if (black[i] == 1)
        {
            return true;
        }
        grey[i] = 1;
        for (auto x : m[i])
        {
            if (grey[x] == 1)
            {
                return false;
            }
            if (!dfs(m, black, grey, x))
            {
                return false;
            }
        }

        grey[i] = 0;
        black[i] = 1;
        return true;
    }
};