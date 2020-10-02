class Solution {
public:
    
    int nthUglyNumber(int n) {
        if(n<7) return n;
        vector<int>dp;
        dp.push_back(1);
        int in2 = 0,in3 = 0,in5 = 0;
        while(dp.size() < n){
            int mul2 = dp[in2] * 2;
            int mul3 = dp[in3] * 3;
            int mul5 = dp[in5] * 5;
            int val = min({mul2,mul3,mul5});
            dp.emplace_back(val);
            if(val == mul2) in2++;
            if(val == mul3) in3++;
            if(val == mul5) in5++;
        }
        return dp[dp.size()-1];
    }
};
