class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int ans = 0, nr = grid.size(), nc = grid[0].size();
        vector<int> rows(nr), cols(nc);
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] == 1)
                {
                    rows[i]++;
                    cols[j]++;
                    ans++;
                }
            }
        }

        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (rows[i] == 1 && cols[j] == 1)
                    {
                        ans--;
                    }
                }
            }
        }

        return ans;
    }
};