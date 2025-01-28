// DP
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]) return 0;
        int r = grid.size(),c = grid[0].size();
        vector<vector<long>>dp(r,vector<long>(c));
        dp[0][0] = 1;
        for(int i=1;i<c;i++) dp[0][i] = (grid[0][i] == 1) ? 0 : dp[0][i-1];
        for(int i=1;i<r;i++) dp[i][0] = (grid[i][0] == 1) ? 0 : dp[i-1][0];
        for(int i=1;i<r;i++)
            for(int j=1;j<c;j++)
                dp[i][j] = (!grid[i][j]) ? dp[i-1][j] + dp[i][j-1] : 0;
        return dp[r-1][c-1];
    }
};

// same as above with comments
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long>> dp(m, vector<long>(n));
        // 1 way to reach here (m = n = 1 this case will be handled too)
        dp[0][0] = 1;
        // fill up 1st row
        for(int i = 1; i<n; i++) dp[0][i] = (grid[0][i] == 1) ? 0 : dp[0][i-1];
        // fill up 1st column
        for(int i = 1; i<m; i++) dp[i][0] = (grid[i][0] == 1) ? 0 : dp[i-1][0];
        
        // apply DP
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = (!grid[i][j]) ? dp[i-1][j] + dp[i][j-1] : 0;
            }
        }
        return dp[m-1][n-1];
    }
};

// BruteForce (TLE)
class Solution {
public:
    
    int ans;
    
    void traverse(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i == m-1 && j == n-1){
            ans++;
            return;
        }
        if(j+1 < n && grid[i][j+1] == 0) traverse(grid, i, j+1, m, n);
        if(i+1 < m && grid[i+1][j] == 0) traverse(grid, i+1, j, m, n);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        ans = 0;
        traverse(obstacleGrid, 0, 0, m, n);
        return ans;
    }
};