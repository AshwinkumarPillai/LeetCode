class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        queue<pair<int, int>> q;
        set<pair<int, int>> waterCells;
        int nr = isWater.size(), nc = isWater[0].size();
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (isWater[i][j] == 1)
                {
                    isWater[i][j] = 0;
                    waterCells.insert({i, j});
                    q.push({i, j});
                }
            }
        }

        auto isInBounds = [&](int i, int j) -> bool
        {
            return i >= 0 && i < nr && j >= 0 && j < nc;
        };

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty())
        {
            int sz = q.size();
            while (sz-- > 0)
            {
                pair<int, int> cell = q.front();
                q.pop();
                int val = isWater[cell.first][cell.second];
                for (pair<int, int> &dir : dirs)
                {
                    int ni = cell.first + dir.first, nj = cell.second + dir.second;
                    if (isInBounds(ni, nj) && waterCells.count({ni, nj}) == 0 && isWater[ni][nj] == 0)
                    {
                        isWater[ni][nj] = val + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }
        return isWater;
    }
};