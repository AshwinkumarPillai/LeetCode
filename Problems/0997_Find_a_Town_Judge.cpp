class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        unordered_set<int> ele;
        unordered_map<int, int> m;
        for (int i = 1; i <= n; i++)
        {
            ele.insert(i);
        }
        for (auto x : trust)
        {
            auto e = ele.find(x[0]);
            if (e != ele.end())
            {
                ele.erase(e);
            }
            if (m.find(x[1]) == m.end())
            {
                m[x[1]] = 1;
            }
            else
            {
                m[x[1]]++;
            }
        }

        if (ele.empty())
        {
            return -1;
        }

        for (auto e : ele)
        {
            if (m[e] == (n - 1))
            {
                return e;
            }
        }
        return -1;
    }
};