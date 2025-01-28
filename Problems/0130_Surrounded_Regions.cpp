// In this question we have to flip all O's which are surrounded by X.
// In other words all the O's which can be traversed through the border O's should not be flipped.
// So we can first perform DFS on all the O's connected to boreder O's and mark them as visited then we can perform bfs on remaing and flip them.

// I have used a flag flip - if flip is 0 change O to X and if not don't.
// So while traversing borders flip will be set to 0 and for rest it will be 1

// So to traverse all bordering O's we will use 4 loops:

// flip = 0 - mark all O's as visited
// 1.  row - 0          column - 0 to n-1
// 2.  row - 1 to n-1   column - 0
// 3.  row - n-1        column - 1 to n-2
// 4.  row - 1 to n-2   column - n-1
// Afterwards just loop through the remiang parts and all the non visited O's will be flipped.

// Note :
// vector<pair<int,int>>dirs = {{-1,0},{0,1},{1,0},{0,-1}};
// here the values will be used to calculate adjacent indices -

// for dir: dirs

// (i + dir.first)    (j + dir.second)
// i-1                 j
// i                   j+1
// i+1                 j
// i                   j-1

class Solution
{
public:
    //Check function is used to check whether the given indices i,j are in range.
    bool check(int i, int j, int r, int c)
    {
        return (i >= 0 && i < r && j >= 0 && j < c);
    }
    // DFS funtion to traverse the adjacent elements
    void dfs(vector<vector<char>> &b, vector<vector<int>> &visited, int i, int j, int r, int c, int flip)
    {
        if (visited[i][j])
            return;        // If already visited return
        visited[i][j] = 1; // Set visited to 1
        if (flip)
            b[i][j] = 'X'; // if we are in flip mode then filp the value to X

        // The dirs array consists of pair that we can use to calculate the adjacent indices.
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        // For all 4 directions :
        for (auto dir : dirs)
        {
            int ii = i + dir.first, jj = j + dir.second; // obtain the indices
                                                         // If the indices are valid and the value is O and it is not visited yet then perform dfs on those indices
            if (check(ii, jj, r, c) && b[ii][jj] == 'O' && !visited[ii][jj])
            {
                dfs(b, visited, ii, jj, r, c, flip);
            }
        }
    }
    void solve(vector<vector<char>> &b)
    {
        int r = b.size();
        if (r < 3)
            return;
        int c = b[0].size();
        vector<vector<int>> visited(r, vector<int>(c));
        for (int i = 0; i < c; i++)
        {
            if (b[0][i] == 'O' && !visited[0][i])
            {
                dfs(b, visited, 0, i, r, c, 0);
            }
        }
        for (int i = 1; i < r; i++)
        {
            if (b[i][0] == 'O' && !visited[i][0])
            {
                bfs(b, visited, i, 0, r, c, 0);
            }
        }
        for (int i = 1; i < c; i++)
        {
            if (b[r - 1][i] == 'O' && !visited[r - 1][i])
            {
                dfs(b, visited, r - 1, i, r, c, 0);
            }
        }
        for (int i = 1; i < r - 1; i++)
        {
            if (b[i][c - 1] == 'O' && !visited[i][c - 1])
            {
                dfs(b, visited, i, c - 1, r, c, 0);
            }
        }

        for (int i = 1; i < r - 1; i++)
        {
            for (int j = 1; j < c - 1; j++)
            {
                if (b[i][j] == 'O' && !visited[i][j])
                {
                    dfs(b, visited, i, j, r, c, 1);
                }
            }
        }
    }
};
