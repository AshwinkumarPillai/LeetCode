// DFS SOLUTION
class Solution
{
public:
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int nr, int nc)
    {
        visited[i][j] = true;
        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        auto isInBounds = [&](int i, int j) -> bool
        {
            return i >= 0 && i < nr && j >= 0 && j < nc;
        };

        int ans = grid[i][j];

        for (pair<int, int> &dir : dirs)
        {
            int ni = i + dir.first, nj = j + dir.second;
            if (isInBounds(ni, nj) && visited[ni][nj] == false && grid[ni][nj] != 0)
            {
                ans += dfs(grid, visited, ni, nj, nr, nc);
            }
        }

        return ans;
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        int nr = grid.size(), nc = grid[0].size();
        vector<vector<bool>> visited(nr, vector<bool>(nc, false));

        int ans = 0;

        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] > 0 && !visited[i][j])
                {
                    ans = max(ans, dfs(grid, visited, i, j, nr, nc));
                }
            }
        }

        return ans;
    }
};