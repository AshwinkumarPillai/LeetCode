class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < m + 1; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i < n + 1; i++)
        {
            int ii = i - 1;
            for (int j = 1; j < m + 1; j++)
            {
                int jj = j - 1;
                if (word1[ii] != word2[jj])
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};