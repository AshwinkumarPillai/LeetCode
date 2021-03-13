// Recursion with memoization
class Solution {
public:
    int minDp(vector<int>& coins, vector<int>& dp, int remain){
        if(remain < 0) return -1;
        if(remain == 0) return 0;
        if(dp[remain] != 0) return dp[remain];
        int minval = INT_MAX;
        for(int coin : coins){
            int ans = minDp(coins,dp,remain-coin);
            if(ans >= 0 && ans<minval) minval = ans + 1;
        }
        return dp[remain] = (minval == INT_MAX) ? -1 : minval;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount+1);
        return minDp(coins, dp, amount);
    }
};

// Tabular Dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<double> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {          
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};
