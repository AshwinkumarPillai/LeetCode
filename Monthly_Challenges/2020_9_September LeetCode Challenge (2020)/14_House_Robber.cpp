// Iterative - forward
class Solution {
public:    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++) 
            dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
        return dp[n-1];
    }
};

// Iterative - backward
class Solution {
public:    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        vector<int>dp(n);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--){
            dp[i] = max(nums[i] + dp[i+2],dp[i+1]);
        
        return dp[0];
    }
};

// Recursive DP - from last element
class Solution {
public:
    int n;
    int getMoney(vector<int>& nums,int i,vector<int>& dp){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i] + getMoney(nums,i-2,dp),getMoney(nums,i-1,dp));
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        if(!n) return 0;
        vector<int>dp(n,-1);
        return getMoney(nums,n-1,dp);
    }
};

// Recursive DP - from start element
class Solution {
public:
    int n;
    int getMoney(vector<int>& nums,int i,vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i] + getMoney(nums,i+2,dp),getMoney(nums,i+1,dp));
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        if(!n) return 0;
        vector<int>dp(n,-1);
        return getMoney(nums,0,dp);
    }
};
