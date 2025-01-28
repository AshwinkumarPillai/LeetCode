class Solution {
public:
     bool subsetSum(vector<int> &s, int n){
        int m = s.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 0; i <=m; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= m; i++)
        {
            int ii = i-1;
            for (int j = 1; j <= n; j++)
            {
                if (s[ii] <= j)
                {
                    dp[i][j] = dp[i - 1][j - s[ii]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x: nums){
            sum+=x;
        }
        if(sum % 2 != 0){
            return false;
        }
        return subsetSum(nums,sum/2);
    }
};