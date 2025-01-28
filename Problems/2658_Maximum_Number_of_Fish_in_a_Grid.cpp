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

// BFS
class Solution
{
public:
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int nr, int nc)
    {

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        auto isInBounds = [&](int i, int j) -> bool
        {
            return i >= 0 && i < nr && j >= 0 && j < nc;
        };

        int ans = 0;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz-- > 0)
            {
                pair<int, int> node = q.front();
                q.pop();
                ans += grid[node.first][node.second];
                for (pair<int, int> &dir : dirs)
                {
                    int ni = node.first + dir.first, nj = node.second + dir.second;
                    if (isInBounds(ni, nj) && visited[ni][nj] == false && grid[ni][nj] != 0)
                    {
                        q.push({ni, nj});
                        visited[ni][nj] = true;
                    }
                }
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
                    ans = max(ans, bfs(grid, visited, i, j, nr, nc));
                }
            }
        }

        return ans;
    }
};