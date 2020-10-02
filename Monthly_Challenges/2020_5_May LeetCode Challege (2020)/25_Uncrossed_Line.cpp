class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (A[i] == B[j])
                {
                    dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j - 1] + 1;
                }
                else
                {
                    int x = (i == 0) ? 0 : dp[i - 1][j];
                    int y = (j == 0) ? 0 : dp[i][j - 1];
                    dp[i][j] = max(x, y);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};