// Math Solution in python file
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 || n == 1)
            return 1;
        m--;
        n--;
        if (m < n) // swap m and n  (keep m as larger value)
        {
            m = m + n;
            n = m - n;
            m = m - n;
        }
        long ans = 1;
        for (int i = m + 1, j = 1; i <= m + n; i++, j++)
        {
            ans *= i;
            ans /= j;
        }
        return ans;
    }
};
// Dynamic Programming Solution
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 || n == 1)
            return 1;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1 && j == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};