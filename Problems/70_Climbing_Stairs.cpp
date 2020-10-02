// Recursive
class Solution {
public:
    int climb(int n,vector<int>& dp){
        if(dp[n]) return dp[n];
        return dp[n] = climb(n-1,dp) + climb(n-2,dp);
    }
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        vector<int>dp(n+1);
        dp[1] = 1; dp[2] = 2;
        return climb(n,dp);
    }
};

// Iterative 
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n; 
        vector<int>dp(n+1);
        dp[0] = 0,dp[1] = 1,dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
